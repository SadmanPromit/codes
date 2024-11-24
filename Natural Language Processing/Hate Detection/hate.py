# hate.py
import torch
from torch.cuda.amp import GradScaler, autocast
import gc
from tqdm import tqdm
from pathlib import Path
import pandas as pd
from transformers import BertTokenizerFast as BertTokenizer, BertForSequenceClassification, AdamW
import logging
from torch.utils.data import DataLoader, TensorDataset, random_split
from sklearn.metrics import accuracy_score

logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
handler = logging.FileHandler('hate.log')
handler.setFormatter(logging.Formatter('%(asctime)s - %(levelname)s - %(name)s -   %(message)s'))
logger.addHandler(handler)

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
logger.info(f'Using device: {device}')

tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')

positive_data_path = Path('./pos.tsv')
negative_data_path = Path('./neg.csv')
save_path = "C:/Users/promi/Documents/Datasets/hate/"

negative_data = pd.read_csv(positive_data_path, sep='\t')
positive_data = pd.read_csv(negative_data_path)

negative_data['comment'] = negative_data['comment'].str.replace('NEWLINE','').str.replace(':','')

data = pd.concat([negative_data['comment'], positive_data['body']], ignore_index=True)
data = data.fillna("").astype(str)
labels = torch.tensor([1] * len(negative_data) + [0] * len(positive_data))

inputs = tokenizer(list(data), padding='max_length', truncation=True, max_length=256, return_tensors='pt')

model = BertForSequenceClassification.from_pretrained('bert-base-uncased')
model = model.to(device)
model.train()

optimizer = AdamW(model.parameters(), lr=1e-5)

scaler = GradScaler()

dataset = TensorDataset(inputs['input_ids'], inputs['attention_mask'], labels)
train_size = int(0.8 * len(dataset))
val_size = len(dataset) - train_size
train_dataset, val_dataset = random_split(dataset, [train_size, val_size])

train_loader = DataLoader(train_dataset, batch_size=16, shuffle=True)
val_loader = DataLoader(val_dataset, batch_size=16, shuffle=False)

best_val_loss = float('inf')
accumulation_steps = 4

for epoch in range(10):
    logger.info(f'Starting epoch {epoch + 1}')

    train_loss = 0
    train_preds = []
    train_labels_list = []

    for step, (input_ids, attention_mask, labels_tensor) in enumerate(tqdm(train_loader)):
        input_ids = input_ids.to(device)
        attention_mask = attention_mask.to(device)
        labels_tensor = labels_tensor.to(device)

        with autocast():
            outputs = model(input_ids, attention_mask=attention_mask, labels=labels_tensor)
            loss = outputs.loss

        train_loss += loss.item()

        preds = torch.argmax(outputs.logits, axis=1)
        train_preds.extend(preds.cpu().numpy())
        train_labels_list.extend(labels_tensor.cpu().numpy())

        scaler.scale(loss).backward()

        if (step + 1) % accumulation_steps == 0:  # Wait for several backward steps
            scaler.step(optimizer)  # Now we can do an optimizer step
            scaler.update()
            optimizer.zero_grad()

        gc.collect()
        torch.cuda.empty_cache()

    train_loss /= len(train_loader)
    train_accuracy = accuracy_score(train_labels_list, train_preds)

    val_loss = 0
    val_preds = []
    val_labels_list = []
    model.eval()

    with torch.no_grad():
        for input_ids, attention_mask, labels_tensor in tqdm(val_loader):
            input_ids = input_ids.to(device)
            attention_mask = attention_mask.to(device)
            labels_tensor = labels_tensor.to(device)

            outputs = model(input_ids, attention_mask=attention_mask, labels=labels_tensor)
            val_loss += outputs.loss.item()

            preds = torch.argmax(outputs.logits, axis=1)
            val_preds.extend(preds.cpu().numpy())
            val_labels_list.extend(labels_tensor.cpu().numpy())

    val_loss /= len(val_loader)
    val_accuracy = accuracy_score(val_labels_list, val_preds)

    if val_loss < best_val_loss:
        best_val_loss = val_loss
        torch.save(model.state_dict(), save_path + 'hate.pt')

    model.train()

    logger.info(f'Finished epoch {epoch + 1}. Training loss: {train_loss}, Training accuracy: {train_accuracy}, Validation loss: {val_loss}, Validation accuracy: {val_accuracy}')
