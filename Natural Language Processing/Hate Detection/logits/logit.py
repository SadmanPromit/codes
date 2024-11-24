import torch
from pathlib import Path
import pandas as pd
from transformers import BertTokenizerFast as BertTokenizer, BertForSequenceClassification
from torch.utils.data import TensorDataset, DataLoader
from tqdm import tqdm


device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# Initialize tokenizer and model
tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
model = BertForSequenceClassification.from_pretrained('bert-base-uncased')
model = model.to(device)
model.eval()  # Set model to evaluation mode

# Load data
positive_data_path = Path('./pos.tsv')
negative_data_path = Path('./neg.csv')

negative_data = pd.read_csv(positive_data_path, sep='\t')
positive_data = pd.read_csv(negative_data_path)

# Clean and preprocess data
negative_data['comment'] = negative_data['comment'].str.replace('NEWLINE', '').str.replace(':', '')
data = pd.concat([negative_data['comment'], positive_data['body']], ignore_index=True)
data = data.fillna("").astype(str)
labels = torch.tensor([1] * len(negative_data) + [0] * len(positive_data))

# Tokenize data
inputs = tokenizer(list(data), 
                   padding='max_length', 
                   truncation=True, 
                   max_length=256, 
                   return_tensors='pt')

# Create DataLoader for batching
dataset = TensorDataset(inputs['input_ids'], inputs['attention_mask'], labels)
data_loader = DataLoader(dataset, batch_size=16, shuffle=False)

logits_list = []

# No gradient calculation needed
with torch.no_grad():
    for input_ids, attention_mask, labels_tensor in tqdm(data_loader):
        input_ids = input_ids.to(device)
        attention_mask = attention_mask.to(device)

        # Forward pass to get logits
        outputs = model(input_ids, attention_mask=attention_mask)
        logits = outputs.logits  # Extract logits (before softmax)

        logits_list.append(logits.cpu())  # Store logits, move to CPU for easier handling

# Optionally, concatenate logits into a single tensor
logits_tensor = torch.cat(logits_list, dim=0)

# Save logits to a text file
logits_path = "./logits.txt"
with open(logits_path, "w") as f:
    for logit in logits_tensor:
        # Convert each tensor row to a string and write to the file
        f.write(" ".join(map(str, logit.tolist())) + "\n")

print(f"Logits saved to {logits_path}")