import os
import shutil

def count_files_in_directory(directory):
    """Count files in a directory, non-recursively."""
    return sum([len(files) for _, _, files in os.walk(directory)])

# Get a list of all sub-directories in the current directory
subdirectories = [d for d in os.listdir() if os.path.isdir(d)]

# Iterate over the sub-directories
for subdir in subdirectories:
    file_count = count_files_in_directory(subdir)
    if file_count < 250:
        # Delete the sub-directory if it has less than 250 files
        shutil.rmtree(subdir)
        print(f"Deleted {subdir} with {file_count} files.")

print("Operation completed!")
