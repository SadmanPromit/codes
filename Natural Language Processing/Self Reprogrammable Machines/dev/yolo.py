import cv2
from ultralytics import YOLO

image_path = 'temp.jpg'
image = cv2.imread(image_path)
results = YOLO('yolov8n.pt')(image)