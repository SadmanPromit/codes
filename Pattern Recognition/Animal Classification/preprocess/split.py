import os
import shutil
import glob
import random

SEED = 42
TRAIN_RATIO = 0.8

def split_dataset_into_train_and_validation(data_dir, train_dir, validation_dir):
    """
    Splits a dataset into train and validation sets while preserving subdirectory structures.

    Args:
    - data_dir (str): Path to the dataset.
    - train_dir (str): Path to the train directory to be created.
    - validation_dir (str): Path to the validation directory to be created.
    """

    # Ensure reproducibility
    random.seed(SEED)

    # List all subdirectories in the dataset
    subdirs = [d for d in os.listdir(data_dir) if os.path.isdir(os.path.join(data_dir, d))]

    for subdir in subdirs:
        full_subdir_path = os.path.join(data_dir, subdir)

        # Create corresponding subdirectories in train and validation directories
        train_subdir = os.path.join(train_dir, subdir)
        validation_subdir = os.path.join(validation_dir, subdir)
        os.makedirs(train_subdir, exist_ok=True)
        os.makedirs(validation_subdir, exist_ok=True)

        # List all files in this subdir
        all_files = glob.glob(os.path.join(full_subdir_path, "*.*"))

        # Shuffle files
        random.shuffle(all_files)

        # Split into train and validation sets
        train_count = int(len(all_files) * TRAIN_RATIO)
        train_files = all_files[:train_count]
        validation_files = all_files[train_count:]

        # Copy files to their respective sets
        for file in train_files:
            shutil.copy(file, train_subdir)

        for file in validation_files:
            shutil.copy(file, validation_subdir)

        # Delete the original subdir, but not the main directory
        shutil.rmtree(full_subdir_path)

# Example usage:
data_directory = "./"  # Current directory
train_directory = "./train"
validation_directory = "./validation"

split_dataset_into_train_and_validation(data_directory, train_directory, validation_directory)
