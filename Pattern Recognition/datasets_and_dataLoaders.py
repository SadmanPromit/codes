import os.path
import pandas as pd
import matplotlib.image as mpimage
from PIL import Image
from torch.utils.data import Dataset

df = pd.read_csv('./data/flickr/captions.txt')
df.head(5)
img = mpimage.imread('./data/flickr/Images/')


class FlickrDataset(Dataset):
    def __init__(self, root_dir, caption_file, transform=None):
        self.root_dir = root_dir
        self.df = pd.read_csv(caption_file)
        self.transform = transform
        self.imgs = self.df['image']
        self.captions = self.df['caption']

    def __len__(self):
        return len(self.df)

    def __getitem__(self, idx):
        caption = self.captions[idx]
        img_name = self.imgs[idx]
        img_location = os.path.join(self.root_dir, img_name)
        img = Image.open(img_location).convert('RGB')
        # Dummy because we need to return an embedding for the text not the caption itself
        return img, caption
