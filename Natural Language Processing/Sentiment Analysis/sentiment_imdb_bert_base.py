import time
import torch
import torch.nn as nn
import numpy as np
import pandas as pd
from transformers import BertTokenizer, BertForSequenceClassification, AdamW, get_linear_schedule_with_warmup
from torch.utils.data import DataLoader, RandomSampler, SequentialSampler
from sklearn.metrics import f1_score, accuracy_score

# Set device to GPU if available, else CPU
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

# Load the pre-trained BERT tokenizer and model
tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
model = BertForSequenceClassification.from_pretrained('bert-base-uncased', num_labels=2).to(device)

# Load the IMDB movie reviews dataset (size = 63.1 MB) from local storage
df = pd.read_csv('C:/Users/promi/Documents/Datasets/imdb_dataset.csv')

# Encode the labels (positive/negative) as 0/1
df['label'] = df['sentiment'].apply(lambda x: 1 if x == 'positive' else 0)

# Tokenize the input text and convert it into input features
input_ids, attention_masks, labels = [], [], []
for review, label in zip(df['review'], df['label']):
    encoded_dict = tokenizer.encode_plus(
        review,
        add_special_tokens=True,
        max_length=256,
        pad_to_max_length=True,
        return_attention_mask=True,
        return_tensors='pt'
    )
    input_ids.append(encoded_dict['input_ids'])
    attention_masks.append(encoded_dict['attention_mask'])
    labels.append(torch.tensor(label))

input_ids = torch.cat(input_ids, dim=0).to(device)
attention_masks = torch.cat(attention_masks, dim=0).to(device)
labels = torch.stack(labels).to(device)

# Create a dataset and dataloader
dataset = torch.utils.data.TensorDataset(input_ids, attention_masks, labels)
train_size = int(0.8 * len(dataset))
val_size = len(dataset) - train_size
train_dataset, val_dataset = torch.utils.data.random_split(dataset, [train_size, val_size])

batch_size = 8  # Use a smaller batch size if running on CPU
train_dataloader = DataLoader(train_dataset, sampler=RandomSampler(train_dataset), batch_size=batch_size)
val_dataloader = DataLoader(val_dataset, sampler=SequentialSampler(val_dataset), batch_size=batch_size)

# Set hyper parameters and optimizer
learning_rate = 2e-5
adam_epsilon = 1e-8
max_epochs = 20

optimizer = AdamW(model.parameters(), lr=learning_rate, eps=adam_epsilon)
total_steps = len(train_dataloader) * max_epochs
scheduler = get_linear_schedule_with_warmup(optimizer, num_warmup_steps=0, num_training_steps=total_steps)

# Define loss function and evaluation metrics
loss_fn = nn.CrossEntropyLoss().to(device)

# Define variables for storing the best validation loss and associated model weights
best_val_loss = float('inf')

# Fine-tune the pre-trained BERT model on the IMDB movie reviews dataset
for epoch in range(max_epochs):
    start_time = time.time()

    # Train the model
    model.train()

    train_loss, train_predicted, train_labels = 0.0, [], []
    for batch in train_dataloader:
        batch = tuple(t.to(device) for t in batch)
        inputs = {'input_ids': batch[0],
                  'attention_mask': batch[1],
                  'labels': batch[2]}
        optimizer.zero_grad()

        outputs = model(**inputs)
        loss = loss_fn(outputs[1], inputs['labels'])

        train_loss += loss.item()

        loss.backward()
        torch.nn.utils.clip_grad_norm_(model.parameters(), 1.0)
        optimizer.step()
        scheduler.step()

        logit = outputs[1].detach().cpu().numpy()
        label_ids = inputs['labels'].to('cpu').numpy()

        train_predicted.append(np.argmax(logit, axis=1).flatten())
        train_labels.append(label_ids.flatten())

    train_predicted = np.concatenate(train_predicted, axis=0)
    train_labels = np.concatenate(train_labels, axis=0)
    train_f1_score = f1_score(train_labels, train_predicted, average='weighted')
    train_acc = accuracy_score(train_labels, train_predicted)

    # Evaluate the model on the validation set
    model.eval()

    val_loss = 0.0
    val_predicted = []
    val_labels = []

    for batch in val_dataloader:
        batch = tuple(t.to(device) for t in batch)
        inputs = {'input_ids': batch[0],
                  'attention_mask': batch[1],
                  'labels': batch[2]}

        with torch.no_grad():
            outputs = model(**inputs)
            loss = loss_fn(outputs[1], inputs['labels'])

            val_loss += loss.item()

            logit = outputs[1].detach().cpu().numpy()
            label_ids = inputs['labels'].to('cpu').numpy()

            val_predicted.append(np.argmax(logit, axis=1).flatten())
            val_labels.append(label_ids.flatten())

    val_predicted = np.concatenate(val_predicted, axis=0)
    val_labels = np.concatenate(val_labels, axis=0)
    val_f1_score = f1_score(val_labels, val_predicted, average='weighted')
    val_acc = accuracy_score(val_labels, val_predicted)

    if val_loss < best_val_loss:
        # Save the model with the best validation loss so far
        best_val_loss = val_loss
        torch.save(model.state_dict(), 'sentiment_imdb_bert_base_model.pth')

    print(
        'Epoch: %d | Train Loss: %.4f | Train Acc: %.4f | Train F1-Score: %.4f | Val Loss: %.4f | Val Acc: %.4f | Val '
        'F1-Score: %.4f | Time Elapsed: %.2f sec' %
        (epoch + 1, train_loss / len(train_dataloader), train_acc, train_f1_score, val_loss / len(val_dataloader),
         val_acc, val_f1_score, time.time() - start_time)
    )
