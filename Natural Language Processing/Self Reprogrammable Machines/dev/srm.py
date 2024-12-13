# srm: v1 © 2024 Sadman Sakib Khan Promit
from transformers import AutoTokenizer, AutoModelForCausalLM, logging
import torch
import warnings
import re
import threading
import time
import os
import configparser
import keyboard
import gc
import sounddevice as sd
from scipy.io.wavfile import write
import whisper
import numpy as np
from gtts import gTTS
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
import pygame
from utils import get_som_labeled_img, check_ocr_box, get_caption_model_processor, get_yolo_model
from ultralytics import YOLO
from PIL import Image,  ImageGrab
import io
import transformers
import logging as logging2

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
input_text = ""
generate_flag = True
record_flag = True
config_parser = configparser.ConfigParser()
default = {
    'model': 'microsoft/phi-2',
    'half': 'h',
    'token': '50',
    'voice': 't',
    'sound': 'm'
}
if not os.path.exists('config.ini'):
    config_parser['settings'] = default
    with open('config.ini', 'w') as configfile:
        config_parser.write(configfile)
config_parser.read('config.ini')
model_dir = config_parser.get('settings', 'model', fallback=default['model'])
half_flag = config_parser.get('settings', 'half', fallback=default['half'])
output_token = config_parser.getint('settings', 'token', fallback=int(default['token']))
voice_flag = config_parser.get('settings', 'voice', fallback=default['voice'])
sound_flag = config_parser.get('settings', 'sound', fallback=default['sound'])

def menu():    
    def update_model():
        global model_dir
        model_dir1 = input("Enter '1' for microsoft/phi-2 5.18 GB or '2' for google/gemma-7b or '3' for nvidia/Mistral-NeMo-Minitron-8B-Base 15.6 GB or '4' for adding model: ")
        if(model_dir1 == '1'):
            model_dir = 'microsoft/phi-2'
        elif(model_dir1 == '2'):
            model_dir = 'google/gemma-7b'
        elif(model_dir1 == '3'):
            model_dir = 'nvidia/Mistral-NeMo-Minitron-8B-Base'
        elif(model_dir1 == '4'):
            model_dir = input('Enter transformer text model directory: ')
        config_parser['settings']['model'] = model_dir

    def update_half():
        global half_flag
        half_flag = input("Enter 'h' for FP16 or 'f' for FP32: ")
        config_parser['settings']['half'] = half_flag

    def update_token():
        global output_token
        output_token = int(input("Enter output token: "))
        config_parser['settings']['token'] = str(output_token)

    def update_voice():
        global voice_flag
        voice_flag = input("Enter 'v' for voice or 't' for text input: ")
        config_parser['settings']['voice'] = voice_flag

    def update_sound():
        global sound_flag
        sound_flag = input("Enter 's' for sound or 'm' for mute: ")
        config_parser['settings']['sound'] = sound_flag

    def reset_settings():
        global model_dir, half_flag, output_token, voice_flag, voice_flag
        config_parser['settings'] = default
        model_dir = config_parser.get('settings', 'model', fallback=default['model'])
        half_flag = config_parser.get('settings', 'half', fallback=default['half'])
        output_token = config_parser.getint('settings', 'token', fallback=int(default['token']))
        voice_flag = config_parser.get('settings', 'voice', fallback=default['voice'])
        sound_flag = config_parser.get('settings', 'sound', fallback=default['sound'])

    options = {
        'M': update_model,
        'H': update_half,
        'T': update_token,
        'V': update_voice,
        'S': update_sound,
        'R': reset_settings
    }
    choice = input(f"Press 'R' to reset to default, 'M' to update model, 'H' for half-precision, 'T' for token length, 'V' for input type, 'S' for output sound, or any to skip: ")
    action = options.get(choice, None)
    if action:
        action()
        with open('config.ini', 'w') as configfile:
            config_parser.write(configfile)
        print("Settings saved.")
        return True
    else:
        return False

def input_wait():
    global generate_flag
    keyboard.wait('esc')
    generate_flag = False

def record_wait():
    global record_flag
    keyboard.wait('esc')
    record_flag = False

def record(filename):
    global record_flag
    record_flag = True
    sample_rate = 48000
    audio_data = []
    print("prompt: ", end='', flush=True)
    keyboard.wait('return')
    record_thread = threading.Thread(target=record_wait, daemon=True)
    record_thread.start()
    while record_flag:
        segment = sd.rec(int(5 * sample_rate), samplerate=sample_rate, channels=1)
        sd.wait()
        audio_data.append(segment)
    audio_data = np.concatenate(audio_data, axis=0)
    write(filename, sample_rate, audio_data)

def voice_to_text():
    global device
    model = whisper.load_model("tiny.en").to(device) # tiny.en base.en small.en medium.en
    record("temp.wav")
    result = model.transcribe("temp.wav", fp16=True)
    os.remove("temp.wav")
    print(result["text"])
    return result["text"]

def omniparse(image):
    global device
    yolo_logger = logging2.getLogger("ultralytics")
    yolo_logger.setLevel(logging.ERROR)
    transformers.logging.set_verbosity_error()
    dir = 'C:/Users/proom/.cache/OmniParser-master/'
    som_model = get_yolo_model(model_path=dir+'weights/icon_detect/best.pt').to(device)
    caption_model_processor = get_caption_model_processor(model_name="florence2", model_name_or_path=dir+"weights/icon_caption_florence", device=device) # florence2 blip2
    image_path = 'temp.png'
    image.save(image_path)
    BOX_TRESHOLD = 0.03
    image = Image.open(image_path)
    image_rgb = image.convert('RGB')
    box_overlay_ratio = image.size[0] / 3200
    draw_bbox_config = {
        'text_scale': 0.8 * box_overlay_ratio,
        'text_thickness': max(int(2 * box_overlay_ratio), 1),
        'text_padding': max(int(3 * box_overlay_ratio), 1),
        'thickness': max(int(3 * box_overlay_ratio), 1)
    }
    ocr_bbox_rslt, is_goal_filtered = check_ocr_box(
        image_path,
        display_img = False,
        output_bb_format = 'xyxy',
        goal_filtering = None,
        easyocr_args = {
            'paragraph': False,
            'text_threshold': 0.9
        },
        use_paddleocr = True
    )
    text, ocr_bbox = ocr_bbox_rslt
    dino_labled_img, label_coordinates, parsed_content_list = get_som_labeled_img(
        image_path,
        som_model,
        BOX_TRESHOLD = BOX_TRESHOLD,
        output_coord_in_ratio = False,
        ocr_bbox = ocr_bbox,
        draw_bbox_config = draw_bbox_config,
        caption_model_processor = caption_model_processor,
        ocr_text = text,
        use_local_semantics = True,
        iou_threshold = 0.1,
        imgsz = 640
    )
    os.remove(image_path)
    return parsed_content_list

def predict(tokenizer, model, do_sample=True, top_k=50, top_p=0.95):
    global input_text, generate_flag, voice_flag, record_flag, output_token
    generate_flag = True
    if(voice_flag == 'v'):
        input_text = voice_to_text()
    else:
        image = ImageGrab.grabclipboard()    
        if isinstance(image, Image.Image):
            input_text = omniparse(image)
        else:
            input_text = input('prompt: ')
    input_thread = threading.Thread(target=input_wait, daemon=True)
    input_thread.start()
    generated_text = input_text
    inputs = tokenizer(input_text, return_tensors="pt")
    inputs = {key: value.to(model.device) for key, value in inputs.items() if key != "token_type_ids"}
    input_ids = inputs['input_ids']
    attention_mask = inputs['attention_mask']
    token = 0
    start_time = time.time()
    print(f"{input_text}", end='', flush=True)
    with torch.no_grad():
        while generate_flag and token < output_token:
            outputs = model.generate(
                input_ids,
                attention_mask=attention_mask,
                max_new_tokens=1,
                do_sample=do_sample,
                top_k=top_k,
                top_p=top_p,
                pad_token_id=tokenizer.eos_token_id
            )
            new_token = outputs[0, -1].unsqueeze(0).unsqueeze(0)
            buffer = tokenizer.decode(new_token.squeeze().item(), skip_special_tokens=True)
            print(buffer, end='', flush=True)
            generated_text += buffer
            input_ids = torch.cat((input_ids, new_token), dim=1)
            attention_mask = torch.cat((attention_mask, torch.ones((1, 1)).to(model.device)), dim=1)
            token += 1
    end_time = time.time()
    if(sound_flag == 's'):
        text_to_speech(generated_text)
    execution_time = end_time - start_time
    return generated_text, execution_time, token

def py_regex(text):
    code_pattern = re.compile(r"(?:\n|^)(\s*(?:def|class|import|from|\s{4,}).+?(?:\n\s*#.*|\n{2,}|$))", re.DOTALL | re.MULTILINE)
    code_snippets = code_pattern.findall(text)
    return "\n".join(code_snippets)

def text_to_speech(text):
    tts = gTTS(text, lang="en")
    file = "temp.mp3"
    tts.save(file)
    pygame.mixer.init()
    pygame.mixer.music.load(file)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        pass
    pygame.mixer.music.stop()
    pygame.mixer.quit()
    os.remove(file)

def main():
    global model_dir, half_flag, output_token, voice_flag, sound_flag, device
    logging.set_verbosity_error()
    warnings.filterwarnings("ignore")
    print('Self Reprogrammable Machines (SRM) v1\n© 2024 Sadman Sakib Khan Promit\nhttps://www.spromits.com')
    while True:
        tokenizer = AutoTokenizer.from_pretrained(model_dir)
        if(half_flag == 'h'):
            model = AutoModelForCausalLM.from_pretrained(model_dir, torch_dtype=torch.float16).to(device)
        else:
            model = AutoModelForCausalLM.from_pretrained(model_dir).to(device)
        reload_flag = menu()
        if reload_flag:
            del model
            del tokenizer
            gc.collect()
            torch.cuda.empty_cache()
        else:
            break
    print(f"[{device}][{model_dir}][{half_flag}][{output_token}][{voice_flag}][{sound_flag}][Press 'ENTER'/'ESC' to prompt at any time]")
    while True:
        output, exec_time, token = predict(tokenizer, model)
        inout = input_text + output
        py_code = py_regex(inout)
        if py_code != "":
            os.system(f'python -c {py_code}')
            print('[programmed]', end='', flush=True)
        if(token != 0):
            print(f"[{token} token * {exec_time / token:.2f} rate = {exec_time:.2f} second]")

if __name__ == "__main__":
    main()