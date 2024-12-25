# translator: any -> en v4 © 2024 Sadman Sakib Khan Promit
# debug: pip install googletrans==4.0.0-rc1
# input device mic -> output device speaker
from noisereduce import reduce_noise
from gtts import gTTS
import os
import sounddevice as sd
import numpy as np
from googletrans import Translator
import speech_recognition as sr
from io import BytesIO
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
import pygame

sample_rate = 48000

def record(threshold = 0.1, chunk_duration = 2, max_silent_chunks = 1):
    audio = []
    silent_chunks = 0
    while True:
        chunk = sd.rec(int(chunk_duration * sample_rate), samplerate = sample_rate, channels = 1, dtype = 'float32')
        sd.wait()
        chunk = chunk.flatten()
        energy = np.sqrt(np.mean(chunk ** 2))
        if energy > threshold:
            audio.append(chunk)
            silent_chunks = 0
        else:
            silent_chunks += 1
            if silent_chunks > max_silent_chunks:
                break
    if audio:
        audio = np.concatenate(audio)
        audio = audio / np.max(np.abs(audio))
        return np.int16(audio * 32767)
    else:
        return record()

def voice_input():
    try:
        audio = record()
        audio = reduce_noise(y = audio.astype(float), sr = sample_rate).astype(np.int16)
        recognizer = sr.Recognizer()
        audio = sr.AudioData(audio.tobytes(), sample_rate, 2)      
        recognized_text = recognizer.recognize_google(audio)
        translator = Translator()
        translated_text = translator.translate(recognized_text, dest = 'en').text
        print(f'[Recognized] {recognized_text}\n[Translated] {translated_text}')
        return translated_text
    except Exception as e:
        return voice_input()

def voice_output(text):
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

def main():
    while True:
        print("[speak]")
        text = voice_input()
        voice_output(text)

if __name__ == "__main__":
    main()