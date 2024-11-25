import os

# Get the current directory
current_directory = os.getcwd()

# Open the output file in write mode
with open("dataset.txt", "w") as outfile:
    # Walk through the current directory and subdirectories
    for dirpath, dirnames, filenames in os.walk(current_directory):
        # Write each file name to the output file
        for filename in filenames:
            outfile.write(os.path.join(dirpath, filename) + "\n")

print("File names saved in dataset.txt")
