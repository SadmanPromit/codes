import os
import random
from PIL import Image

def make_collage(images, filename, collage_size=(5000, 4000), individual_img_size=(1000, 1000)):
    # Create a blank white image
    collage = Image.new('RGB', collage_size, (255, 255, 255))
    width, height = individual_img_size

    idx = 0
    for j in range(0, collage_size[1], height):
        for i in range(0, collage_size[0], width):
            if idx >= len(images):
                break
            img = Image.open(images[idx])
            img = img.resize((width, height))
            collage.paste(img, (i, j))
            idx += 1
    collage.save(filename, "PNG", quality=95)  # Save as high-quality PNG

def main():
    # Get all subdirectories
    subdirs = [d for d in os.listdir('.') if os.path.isdir(d)]

    if len(subdirs) < 20:
        print("There are fewer than 20 subdirectories.")
        return

    selected_images = []
    
    for subdir in subdirs:
        # Get all images in the selected subdir
        all_images = [os.path.join(subdir, f) for f in os.listdir(subdir) if f.lower().endswith(('png', 'jpg', 'jpeg'))]
        
        if not all_images:
            print(f"Skipping {subdir} as it has no valid images.")
            continue

        # Randomly select an image from this subdir
        img = random.choice(all_images)
        selected_images.append(img)

        if len(selected_images) == 20:
            break

    if len(selected_images) < 20:
        print(f"Only found {len(selected_images)} images from unique sub-directories. Collage might be incomplete.")
    
    # Create collage
    collage_filename = "collage.png"
    make_collage(selected_images, collage_filename)
    print(f"Collage saved as {collage_filename}")

if __name__ == "__main__":
    main()
