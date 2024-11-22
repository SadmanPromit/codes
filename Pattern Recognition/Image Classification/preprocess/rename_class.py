import os

def transform_directory_name(dir_name):
    """Transform directory name by converting uppercase to lowercase and spaces to underscores."""
    return dir_name.lower().replace(' ', '_')

def main():
    current_directory = os.getcwd()

    for subdir_name in os.listdir(current_directory):
        full_path = os.path.join(current_directory, subdir_name)

        # Check if it's a directory
        if os.path.isdir(full_path):
            new_name = transform_directory_name(subdir_name)
            new_path = os.path.join(current_directory, new_name)

            # Rename if new name is different from the old name
            if new_name != subdir_name:
                os.rename(full_path, new_path)
                print(f"Renamed: {subdir_name} -> {new_name}")

if __name__ == "__main__":
    main()
