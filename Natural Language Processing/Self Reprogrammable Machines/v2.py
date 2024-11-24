# Self Reprogrammable Machines (SRM) v2
from transformers import AutoTokenizer, AutoModelForCausalLM, logging
from scipy.io.wavfile import write
from gtts import gTTS
from PIL import Image,  ImageGrab
import torch
import warnings
import time
import os
import sounddevice as sd
import whisper
import numpy as np
import pytesseract
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
import pygame

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f'Self Reprogrammable Machines (SRM) v2\n© 2024 Sadman Sakib Khan Promit\nhttps://www.spromits.com\n[{device}]')
model_dir = 'microsoft/phi-2'
tokenizer = AutoTokenizer.from_pretrained(model_dir)
model = AutoModelForCausalLM.from_pretrained(model_dir, torch_dtype=torch.float16).to(device)
model_voice = whisper.load_model("tiny.en").to(device)  # tiny base small medium

def record(filename, threshold = 0.01, chunk_duration = 5, max_silence = 5):
    sample_rate = 48000
    audio_data = []
    num_silent_chunks = 0
    max_silent_chunks = int(max_silence / chunk_duration)    
    try:
        while True:
            chunk = sd.rec(int(chunk_duration * sample_rate), samplerate = sample_rate, channels = 1, dtype = 'float32')
            sd.wait()
            chunk = chunk.flatten()
            energy = np.sqrt(np.mean(chunk ** 2)) # rms
            if energy > threshold:
                audio_data.append(chunk)
                num_silent_chunks = 0
            else:
                num_silent_chunks += 1
                if num_silent_chunks > max_silent_chunks:
                    break
    except KeyboardInterrupt:
        pass    
    if audio_data:
        audio_data = np.concatenate(audio_data)
        audio_data = audio_data / np.max(np.abs(audio_data)) # normalize
        audio_data_int16 = np.int16(audio_data * 32767) # wav
        write(filename, sample_rate, audio_data_int16)
    else:
        pass

def voice_input():
    global model_voice
    temp_filename = "temp.wav"
    record(filename=temp_filename) # VAD
    if os.path.exists(temp_filename):
        result = model_voice.transcribe(temp_filename, fp16=True)
        os.remove(temp_filename)
        return result["text"]
    else:
        return voice_input()

def vision_input(image):
    text = pytesseract.image_to_string(image)
    return text

def predict(text):
    global model, tokenizer, device
    generated_text = ''
    print('[inference]')
    inputs = tokenizer(text, return_tensors = "pt")
    inputs = {key: value.to(model.device) for key, value in inputs.items() if key != "token_type_ids"}
    input_ids = inputs['input_ids']
    attention_mask = inputs['attention_mask']
    token = 0
    start_time = time.time()
    with torch.no_grad():
        while token < 25:
            outputs = model.generate(
                input_ids,
                attention_mask=attention_mask,
                max_new_tokens=1,
                do_sample=True,
                top_k=50,
                top_p=0.95,
                pad_token_id=tokenizer.eos_token_id
            )
            new_token = outputs[0, -1].unsqueeze(0).unsqueeze(0)
            buffer = tokenizer.decode(new_token.squeeze().item(), skip_special_tokens=True)
            generated_text += buffer
            print(buffer, end = '', flush = True)
            input_ids = torch.cat((input_ids, new_token), dim=1)
            attention_mask = torch.cat((attention_mask, torch.ones((1, 1)).to(model.device)), dim=1)
            token += 1
    end_time = time.time()
    execution_time = end_time - start_time
    return generated_text, execution_time, token

def speech_output(text):
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
    logging.set_verbosity_error()
    warnings.filterwarnings("ignore")
    while True:
        print("[record/ss]")
        image_ss = ImageGrab.grabclipboard()    
        if isinstance(image_ss, Image.Image):
            text = vision_input(image_ss)
        else:
            text = voice_input()
        print('[record/ss read]' + text)
        text_output, exec_time, token = predict(text)
        print(f"[{token} token * {exec_time / token:.2f} rate = {exec_time:.2f} second]")
        speech_output(text_output)

if __name__ == "__main__":
    main()