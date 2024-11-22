import os

def search_string_in_file(file_name, string_to_search):
    lines_with_string = []
    try:
        with open(file_name, 'r', encoding='utf-8') as file:
            for line_no, line in enumerate(file, 1):
                if string_to_search in line:
                    lines_with_string.append((line_no, line.strip()))
    except Exception as e:
        pass
    return lines_with_string

def search_string_in_directory(directory, string_to_search):
    for dirpath, _, filenames in os.walk(directory):
        for filename in filenames:
            if filename.endswith('.c') or filename.endswith('.py'):
                file_path = os.path.join(dirpath, filename)
                matches = search_string_in_file(file_path, string_to_search)
                for match in matches:
                    print(f"{file_path}, Line {match[0]}: {match[1]}")

if __name__ == "__main__":
    search_str = input("Search keyword in codes .c .py: ")
    search_string_in_directory(os.getcwd(), search_str)
