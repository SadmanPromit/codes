import os
import random
from PIL import Image

SEED = 42
random.seed(SEED)


def is_image_file(file):
    return file.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.tif', '.tiff'))


def check_image_size(filepath):
    try:
        with Image.open(filepath) as img:
            width, height = img.size
        return width >= 224 and height >= 224
    except Exception as e:
        print(f"Error processing {filepath}. Error: {e}")
        return False


def is_grayscale_image(filepath):
    try:
        with Image.open(filepath) as img:
            channels = img.split()
            if len(channels) == 1:
                return True  # Only one channel means it's grayscale
            r, g, b = channels[:3]
            if r == g == b:
                return True  # All channels are identical
    except Exception as e:
        print(f"Error checking if {filepath} is grayscale. Error: {e}")
    return False


def is_not_rgb(filepath):
    try:
        with Image.open(filepath) as img:
            return img.mode != 'RGB'
    except Exception as e:
        print(f"Error checking mode of {filepath}. Error: {e}")
    return False


def process_directory(directory, keep_count=250):
    deleted_count = 0

    for root, _, files in os.walk(directory):
        image_files = [f for f in files if is_image_file(f) and os.path.isfile(os.path.join(root, f))]

        # Filter out and delete grayscale images
        for img in image_files[:]:
            if is_grayscale_image(os.path.join(root, img)):
                os.remove(os.path.join(root, img))
                image_files.remove(img)
                deleted_count += 1

        # Filter out and delete non-RGB images
        for img in image_files[:]:
            if is_not_rgb(os.path.join(root, img)):
                os.remove(os.path.join(root, img))
                image_files.remove(img)
                deleted_count += 1

        # Filter out and delete smaller images
        for img in image_files[:]:
            if not check_image_size(os.path.join(root, img)):
                os.remove(os.path.join(root, img))
                image_files.remove(img)
                deleted_count += 1

        # If more than 250 images, sample excess to delete
        if len(image_files) > keep_count:
            excess_count = len(image_files) - keep_count
            excess_images = random.sample(image_files, excess_count)
            for img in excess_images:
                os.remove(os.path.join(root, img))
            print(f"In {root}, retained {keep_count} random images and deleted the excess {excess_count} images.")
        else:
            print(f"In {root}, there are {len(image_files)} images. No excess images to delete.")

    return deleted_count


if __name__ == "__main__":
    count = process_directory('.')
    print(f"Deleted {count} images that were either smaller than 224x224, grayscale, or not RGB in total.")
