# search_docx: v1 © 2024 Sadman Sakib Khan Promit
import os
from docx import Document

def search_docx_files(directory, search_string):
    for foldername, subfolders, filenames in os.walk(directory):
        for filename in filenames:
            if filename.endswith('.docx'):
                filepath = os.path.join(foldername, filename)
                doc = Document(filepath)
                for paragraph in doc.paragraphs:
                    if search_string in paragraph.text:
                        print(f"Found '{search_string}' in {filepath}")

if __name__ == "__main__":
    current_directory = os.getcwd()  # Gets the current working directory
    search_string = input("Enter the string to search: ")
    search_docx_files(current_directory, search_string)
