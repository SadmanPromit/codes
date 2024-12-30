# dictionary: v1 © 2024 Sadman Sakib Khan Promit
import nltk
from nltk.corpus import wordnet
import pytesseract
from PIL import Image, ImageGrab
from gtts import gTTS
from io import BytesIO
import webbrowser
import urllib.parse
import pyperclip
import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
import pygame

nltk.download('wordnet', quiet = True)

def main():
    print("[write/copy then press enter]")
    while True:
        word = ""
        word = input()
        image_ss = ImageGrab.grabclipboard()
        if word == "" and isinstance(image_ss, Image.Image):
            word = pytesseract.image_to_string(image_ss).strip()
        elif word == "":
            word = pyperclip.paste()
        definitions = wordnet.synsets(word)
        if definitions:
            definition = definitions[0].definition()
            print(f"[{word}: {definition}]")
            voice_output(definition)
        else:
            print(f"[{word}]")
            lookup_online(word + " definition")

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

def lookup_online(word):
    encoded_query = urllib.parse.quote_plus(word)
    google_url = f"https://www.google.com/search?q={encoded_query}"
    webbrowser.open_new_tab(google_url)

if __name__ == "__main__":
    main()