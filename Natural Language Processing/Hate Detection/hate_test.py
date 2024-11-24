# hate_eval.py
import torch
import pandas as pd
from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score
import seaborn as sns
import matplotlib.pyplot as plt
from torch.utils.data import DataLoader, TensorDataset
from transformers import BertTokenizerFast as BertTokenizer, BertForSequenceClassification
from pathlib import Path
from tqdm import tqdm

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')

# Load model
model = BertForSequenceClassification.from_pretrained('bert-base-uncased')
model.load_state_dict(torch.load("./hate.pt"))
model = model.to(device)
model.eval()

# Load new dataset for evaluation
positive_data_path = Path('./neg.csv')
negative_data_path = Path('./pos.tsv')

positive_data = pd.read_csv(positive_data_path)
negative_data = pd.read_csv(negative_data_path, sep='\t')

negative_data['comment'] = negative_data['comment'].str.replace('NEWLINE','').str.replace(':','')

data = pd.concat([negative_data['comment'], positive_data['body']], ignore_index=True)
data = data.fillna("").astype(str)
labels = torch.tensor([1] * len(negative_data) + [0] * len(positive_data))

inputs = tokenizer(list(data), padding='max_length', truncation=True, max_length=256, return_tensors='pt')

dataset = TensorDataset(inputs['input_ids'], inputs['attention_mask'], labels)
loader = DataLoader(dataset, batch_size=32, shuffle=False)

preds_list = []
labels_list = []

# Evaluate model on the new dataset
with torch.no_grad():
    for input_ids, attention_mask, labels_tensor in tqdm(loader):
        input_ids = input_ids.to(device)
        attention_mask = attention_mask.to(device)

        outputs = model(input_ids, attention_mask=attention_mask)
        preds = torch.argmax(outputs.logits, axis=1)

        preds_list.extend(preds.cpu().numpy())
        labels_list.extend(labels_tensor.cpu().numpy())

# Compute metrics
cm = confusion_matrix(labels_list, preds_list)
accuracy = accuracy_score(labels_list, preds_list)
precision = precision_score(labels_list, preds_list, average='binary')
recall = recall_score(labels_list, preds_list, average='binary')

# Save metrics to a file
with open('metrics.txt', 'w') as f:
    f.write(f'Accuracy: {accuracy}\n')
    f.write(f'Precision: {precision}\n')
    f.write(f'Recall: {recall}\n')

# Plot confusion matrix
plt.figure(figsize=(10, 7))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues')
plt.title('Confusion Matrix')
plt.xlabel('Predicted')
plt.ylabel('Actual')

# Save confusion matrix to a png file
plt.savefig('confusion_matrix.png')
