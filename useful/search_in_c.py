import os

def search_string_in_file(file_name, string_to_search):
    """Return the list of lines where the string is found in the file."""
    lines_with_string = []
    try:
        with open(file_name, 'r', encoding='utf-8') as file:
            for line_no, line in enumerate(file, 1):
                if string_to_search in line:
                    lines_with_string.append((line_no, line.strip()))
    except Exception as e:
        print(f"Error reading file {file_name}: {e}")
    return lines_with_string

def search_string_in_directory(directory, string_to_search):
    """Search for the string in all .c files in the specified directory."""
    for dirpath, _, filenames in os.walk(directory):
        for filename in filenames:
            if filename.endswith('.c'):
                file_path = os.path.join(dirpath, filename)
                matches = search_string_in_file(file_path, string_to_search)
                for match in matches:
                    print(f"Found in {file_path}, Line {match[0]}: {match[1]}")

if __name__ == "__main__":
    search_str = input("Enter the string to search for: ")
    search_string_in_directory(os.getcwd(), search_str)
