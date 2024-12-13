# converse: v2 © 2024 Sadman Sakib Khan Promit
# input device mic -> output device speaker
from transformers import AutoTokenizer, AutoModelForCausalLM, logging
from noisereduce import reduce_noise
import speech_recognition as sr
from gtts import gTTS
import torch
import sounddevice as sd
import numpy as np
from io import BytesIO
import pytesseract
from PIL import Image, ImageGrab
import warnings
import time
import threading
import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
import pygame

generate_token = 300
sample_rate = 48000
model_dir = 'nvidia/Mistral-NeMo-Minitron-8B-Base'
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
tokenizer = AutoTokenizer.from_pretrained(model_dir)
model = AutoModelForCausalLM.from_pretrained(model_dir, torch_dtype = torch.float16).to(device)

def record(threshold = 0.1, chunk_duration = 2, max_silent_chunks = 1):
    audio_data = []
    silent_chunks = 0
    while True:
        chunk = sd.rec(int(chunk_duration * sample_rate), samplerate = sample_rate, channels = 1, dtype = 'float32')
        sd.wait()
        chunk = chunk.flatten()
        energy = np.sqrt(np.mean(chunk ** 2))
        if energy > threshold:
            audio_data.append(chunk)
            silent_chunks = 0
        else:
            silent_chunks += 1
            if silent_chunks > max_silent_chunks:
                break
    if audio_data:
        audio_data = np.concatenate(audio_data)
        audio_data = audio_data / np.max(np.abs(audio_data))
        return np.int16(audio_data * 32767)
    else:
        return record()

def voice_input():
    try:
        raw_audio = record()
        clean_audio = reduce_noise(y = raw_audio.astype(float), sr = sample_rate).astype(np.int16)
        recognizer = sr.Recognizer()
        audio_data = sr.AudioData(clean_audio.tobytes(), sample_rate, 2)
        return recognizer.recognize_google(audio_data)
    except Exception as e:
        return voice_input()

def predict(text):
    global model, tokenizer, device, generate_token
    print('[generation]')
    inputs = tokenizer(text, return_tensors = "pt")
    inputs = {key: value.to(model.device) for key, value in inputs.items() if key != "token_type_ids"}
    input_ids = inputs['input_ids']
    attention_mask = inputs['attention_mask']
    token = 0
    generated_text = ''
    start_time = time.time()
    with torch.no_grad():
        while token < generate_token:
            outputs = model.generate(
                input_ids,
                attention_mask = attention_mask,
                max_new_tokens = 1,
                do_sample = True,
                top_k = 50,
                top_p = 0.95,
                pad_token_id = tokenizer.eos_token_id
            )
            new_token = outputs[0, -1].unsqueeze(0).unsqueeze(0)
            buffer = tokenizer.decode(new_token.squeeze().item(), skip_special_tokens = True)
            generated_text += buffer
            print(buffer, end = '', flush = True)
            if buffer in '.!?\n':
                voice_output(generated_text)
                generated_text = ''
                end_time = time.time()
                execution_time = end_time - start_time
                print(f" [{execution_time / token:.2f}]")
                start_time = time.time()
            input_ids = torch.cat((input_ids, new_token), dim = 1)
            attention_mask = torch.cat((attention_mask, torch.ones((1, 1)).to(model.device)), dim = 1)
            token += 1

def voice_output(text):
    def play_audio():
        try:
            tts = gTTS(text)
            audio_buffer = BytesIO()
            tts.write_to_fp(audio_buffer)
            audio_buffer.seek(0)
            pygame.mixer.init()
            pygame.mixer.music.load(audio_buffer, 'mp3')
            pygame.mixer.music.play()
            while pygame.mixer.music.get_busy():
                pass
            pygame.mixer.music.stop()
            pygame.mixer.quit()
        except Exception as e:
            pass

    threading.Thread(target = play_audio, daemon = True).start()

def main():
    logging.set_verbosity_error()
    warnings.filterwarnings("ignore")
    while True:
        print("[speak/ss]")
        image_ss = ImageGrab.grabclipboard()
        if isinstance(image_ss, Image.Image):
            text = pytesseract.image_to_string(image_ss)
        else:
            text = voice_input()
        print('[recognized] ' + text)
        predict(text)

if __name__ == "__main__":
    main()