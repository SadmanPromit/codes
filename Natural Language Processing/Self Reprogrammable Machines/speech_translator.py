# speech translator: bn -> en v1 © 2024 Sadman Sakib Khan Promit
# pip install noisereduce scipy gtts googletrans==4.0.0-rc1 SpeechRecognition sounddevice pygame numpy
from scipy.io.wavfile import write, read
from noisereduce import reduce_noise
from gtts import gTTS
import os
import sounddevice as sd
import numpy as np
from googletrans import Translator
import speech_recognition as sr
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
import pygame

def record(filename, threshold = 0.1, chunk_duration = 3, max_silence = 3):
    sample_rate = 48000
    audio_data = []
    num_silent_chunks = 0
    max_silent_chunks = int(max_silence / chunk_duration)
    try:
        while True:
            chunk = sd.rec(int(chunk_duration * sample_rate), samplerate=sample_rate, channels=1, dtype='float32')
            sd.wait()
            chunk = chunk.flatten()
            energy = np.sqrt(np.mean(chunk ** 2))
            if energy > threshold:
                audio_data.append(chunk)
                num_silent_chunks = 0
            else:
                num_silent_chunks += 1
                if num_silent_chunks > max_silent_chunks:
                    break
    except Exception as e:
        pass
    if audio_data:
        audio_data = np.concatenate(audio_data)
        audio_data = audio_data / np.max(np.abs(audio_data))
        audio_data_int16 = np.int16(audio_data * 32767)
        write(filename, sample_rate, audio_data_int16)

def reduce_audio_noise(file):
    sample_rate, data = read(file)
    os.remove(file)
    reduced_noise = reduce_noise(y=data.astype(float), sr=sample_rate)
    write(file, sample_rate, reduced_noise.astype(np.int16))

def voice_input_bangla():
    file = "temp.wav"
    try:
        record(filename=file)
        reduce_audio_noise(file)
        recognizer = sr.Recognizer()
        with sr.AudioFile(file) as source:
            audio_data = recognizer.record(source)
        result_text = recognizer.recognize_google(audio_data, language="bn-BD")
        return result_text
    except Exception as e:
        pass
    finally:
        if os.path.exists(file):
            os.remove(file)
    return voice_input_bangla()

def speech_output(text):
    tts = gTTS(text)
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
    translator = Translator()
    while True:
        print("[Speak in Bangla]")
        text = voice_input_bangla()
        if text:
            print(f'[Bangla Recognized]: {text}')
            translated = translator.translate(text, dest='en')
            print(f'[Translated to English]: {translated.text}')
            speech_output(translated.text)

if __name__ == "__main__":
    main()