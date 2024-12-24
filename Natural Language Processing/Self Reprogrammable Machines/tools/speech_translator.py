# speech translator: en <-> bn v3 © 2024 Sadman Sakib Khan Promit
# pip install noisereduce gtts googletrans==4.0.0-rc1 SpeechRecognition sounddevice pygame numpy langdetect
# input device mic -> output device speaker
# speaking english will translate to bangla
# speaking bangla will translate to english
from noisereduce import reduce_noise
from gtts import gTTS
import os
import sounddevice as sd
import numpy as np
from googletrans import Translator
import speech_recognition as sr
from langdetect import detect
from io import BytesIO
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
import pygame

sample_rate = 48000

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
        result_text = recognizer.recognize_google(audio_data)
        translator = Translator()
        if detect(result_text) == 'en':
            result_text = recognizer.recognize_google(audio_data, language = "en-BD")
            translation = translator.translate(result_text, dest = 'bn').text
        else:
            result_text = recognizer.recognize_google(audio_data, language = "bn-BD")
            translation = translator.translate(result_text, dest = 'en').text
        print(f'[Recognized] {result_text}\n[Translated] {translation}')
        return translation
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