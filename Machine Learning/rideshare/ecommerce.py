# ecommerce.py
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder, MinMaxScaler
from sklearn.tree import DecisionTreeRegressor
from sklearn.svm import SVR
from sklearn.neighbors import KNeighborsRegressor
from sklearn.linear_model import Ridge, Lasso
from xgboost import XGBRegressor
from catboost import CatBoostRegressor
from lightgbm import LGBMRegressor
from sklearn.linear_model import ElasticNet, LinearRegression
from sklearn.ensemble import AdaBoostRegressor, RandomForestRegressor, GradientBoostingRegressor
from sklearn.metrics import mean_absolute_error
from ydata_profiling import ProfileReport
import seaborn as sns
import matplotlib.pyplot as plt
import joblib
import torch
import torch.nn as nn
from torch.utils.data import DataLoader, TensorDataset
import torch.optim as optim
from torch.cuda.amp import autocast, GradScaler
from tqdm import tqdm

# Reading the dataset
data = pd.read_csv('C:/Users/promi/Documents/Datasets/E-commerce/uber_and_lyft_dataset/rideshare_kaggle.csv')

# Generating the report
profile = ProfileReport(data, minimal=True)
profile.to_file("eda.html")

# Dropping rows with missing values
data = data.dropna()

# Reset the index
data = data.reset_index(drop=True)

# One hot encoding categorical variables
categorical_vars = ['timezone', 'source', 'destination', 'cab_type', 'name', 'short_summary', 'long_summary', 'icon']
onehot_encoder = OneHotEncoder(sparse_output=False)
onehot_encoded = onehot_encoder.fit_transform(data[categorical_vars])

# Create a DataFrame from the one-hot encoded variables
data_encoded = pd.DataFrame(onehot_encoded, columns=onehot_encoder.get_feature_names_out(categorical_vars))

# Merge the one-hot encoded variables with the original DataFrame
data = data.drop(categorical_vars, axis=1)
data = pd.concat([data, data_encoded], axis=1)

# Checking correlation matrix for 'price'
correlation_matrix = data.corr(numeric_only=True)
correlation_matrix = correlation_matrix[['price']].sort_values(by='price', ascending=False)

# Plotting a heatmap
fig, ax = plt.subplots(figsize=(10, 8))
cmap = sns.diverging_palette(240, 10, as_cmap=True)
sns.heatmap(correlation_matrix, cmap=cmap, center=0, ax=ax)

# Saving the heatmap as a PNG file
heatmap_png = 'heatmap.png'
plt.savefig(heatmap_png, bbox_inches='tight')
plt.close()

# Saving the correlation matrix as a CSV file
correlation_csv = 'correlation_matrix.csv'
correlation_matrix.to_csv(correlation_csv)

# Select only numeric columns
data_numeric = data.select_dtypes(include=[np.number])

# Exclude the target variable 'price' from scaling
data_numeric_scaled = data_numeric.drop(columns='price')

# Apply MinMaxScaler
scaler = MinMaxScaler()
data_scaled = pd.DataFrame(scaler.fit_transform(data_numeric_scaled), columns=data_numeric_scaled.columns)

# Add back the target variable 'price'
data_scaled = pd.concat([data_scaled, data['price']], axis=1)

# Splitting the dataset 70:15:15
train, test = train_test_split(data_scaled, test_size=0.3, random_state=42)
val, test = train_test_split(test, test_size=0.5, random_state=42)

# Separating features and target variable
X_train = train.drop('price', axis=1)
y_train = train['price']
X_val = val.drop('price', axis=1)
y_val = val['price']
X_test = test.drop('price', axis=1)
y_test = test['price']

# XGBoost model
xgb_model = XGBRegressor(tree_method='gpu_hist', n_jobs=-1)
xgb_model.fit(X_train, y_train)
y_pred_xgb = xgb_model.predict(X_val)
mae_xgb = mean_absolute_error(y_val, y_pred_xgb)
joblib.dump(xgb_model, 'xgb_model.pkl')

# CatBoost model
cat_model = CatBoostRegressor(task_type='GPU', thread_count=-1, verbose=False, allow_writing_files=False)
cat_model.fit(X_train, y_train)
y_pred_cat = cat_model.predict(X_val)
mae_cat = mean_absolute_error(y_val, y_pred_cat)
joblib.dump(cat_model, 'cat_model.pkl')

# ElasticNet model
elastic_model = ElasticNet()
elastic_model.fit(X_train, y_train)
y_pred_elastic = elastic_model.predict(X_val)
mae_elastic = mean_absolute_error(y_val, y_pred_elastic)
joblib.dump(elastic_model, 'elastic_model.pkl')

# AdaBoost model
ada_model = AdaBoostRegressor()
ada_model.fit(X_train, y_train)
y_pred_ada = ada_model.predict(X_val)
mae_ada = mean_absolute_error(y_val, y_pred_ada)
joblib.dump(ada_model, 'ada_model.pkl')

# Random Forest model
forest_model = RandomForestRegressor()
forest_model.fit(X_train, y_train)
y_pred_forest = forest_model.predict(X_val)
mae_forest = mean_absolute_error(y_val, y_pred_forest)
joblib.dump(forest_model, 'forest_model.pkl')

# Decision Tree model
tree_model = DecisionTreeRegressor()
tree_model.fit(X_train, y_train)
y_pred_tree = tree_model.predict(X_val)
mae_tree = mean_absolute_error(y_val, y_pred_tree)
joblib.dump(tree_model, 'tree_model.pkl')

# SVR model
svr_model = SVR()
svr_model.fit(X_train, y_train)
y_pred_svr = svr_model.predict(X_val)
mae_svr = mean_absolute_error(y_val, y_pred_svr)
joblib.dump(svr_model, 'svr_model.pkl')

# KNN model
knn_model = KNeighborsRegressor()
knn_model.fit(X_train, y_train)
y_pred_knn = knn_model.predict(X_val)
mae_knn = mean_absolute_error(y_val, y_pred_knn)
joblib.dump(knn_model, 'knn_model.pkl')

# Linear Regression model
lr_model = LinearRegression()
lr_model.fit(X_train, y_train)
y_pred_lr = lr_model.predict(X_val)
mae_lr = mean_absolute_error(y_val, y_pred_lr)
joblib.dump(lr_model, 'lr_model.pkl')

# Gradient Boosting model
gb_model = GradientBoostingRegressor()
gb_model.fit(X_train, y_train)
y_pred_gb = gb_model.predict(X_val)
mae_gb = mean_absolute_error(y_val, y_pred_gb)
joblib.dump(gb_model, 'gb_model.pkl')

# Ridge Regression model
ridge_model = Ridge()
ridge_model.fit(X_train, y_train)
y_pred_ridge = ridge_model.predict(X_val)
mae_ridge = mean_absolute_error(y_val, y_pred_ridge)
joblib.dump(ridge_model, 'ridge_model.pkl')

# Lasso Regression model
lasso_model = Lasso()
lasso_model.fit(X_train, y_train)
y_pred_lasso = lasso_model.predict(X_val)
mae_lasso = mean_absolute_error(y_val, y_pred_lasso)
joblib.dump(lasso_model, 'lasso_model.pkl')

# Convert data to PyTorch tensors
X_train_tensor = torch.tensor(X_train.values, dtype=torch.float).cuda()
y_train_tensor = torch.tensor(y_train.values, dtype=torch.float).cuda()
X_val_tensor = torch.tensor(X_val.values, dtype=torch.float).cuda()
y_val_tensor = torch.tensor(y_val.values, dtype=torch.float).cuda()

# Define dataset
train_dataset = TensorDataset(X_train_tensor, y_train_tensor)
val_dataset = TensorDataset(X_val_tensor, y_val_tensor)

# Define data loader
batch_size = 64  # Modify this value to suit your memory capacity
train_loader = DataLoader(dataset=train_dataset, batch_size=batch_size, shuffle=True)
val_loader = DataLoader(dataset=val_dataset, batch_size=batch_size)


# Neural Network model
class Net(nn.Module):
    def __init__(self, input_size):
        super(Net, self).__init__()
        self.layer = nn.Linear(input_size, 1)

    def forward(self, x):
        return self.layer(x)


# Initialize the model
model = Net(X_train_tensor.shape[1]).cuda()

# Define loss function (MSELoss for regression)
criterion = nn.MSELoss()

# Define optimizer
optimizer = optim.Adam(model.parameters(), lr=0.01)

# Initialize GradScaler for mixed-precision training
scaler = GradScaler()

# Training loop
best_loss = float('inf')
epochs = 100
patience = 10
no_improve = 0
early_stop = False

model.train()
with open('log.txt', 'a') as f:
    for epoch in range(epochs):
        if early_stop:
            f.write('Early stopping\n')
            break

        epoch_loss = 0
        epoch_iterator = tqdm(train_loader, desc="Training")
        for inputs, labels in epoch_iterator:
            inputs = inputs.cuda()
            labels = labels.cuda()
            optimizer.zero_grad()

            # Forward pass with autocast
            with autocast():
                output = model(inputs)
                loss = criterion(output, labels.unsqueeze(1))

            # Scales loss and calls backward() to create scaled gradients
            scaler.scale(loss).backward()

            # Unscales gradients and updates weights
            scaler.step(optimizer)

            # Updates the scale for next iteration
            scaler.update()

            epoch_loss += loss.item()

        epoch_loss /= len(train_loader)
        f.write(f'Epoch: {epoch+1}, Loss: {epoch_loss}\n')

        model.eval()
        val_loss = 0
        with torch.no_grad():
            for x_val, y_val in val_loader:
                x_val = x_val.cuda()
                with autocast():
                    output = model(x_val)
                    loss = criterion(output, y_val.unsqueeze(1))
                val_loss += loss.item()
        val_loss /= len(val_loader)
        f.write(f'Validation Loss: {val_loss}\n')

        if val_loss < best_loss:
            best_loss = val_loss
            torch.save(model.state_dict(), 'nn_model.pt')
            no_improve = 0
        else:
            no_improve += 1
        if no_improve > patience:
            early_stop = True

f.close()

# Load the best model
model.load_state_dict(torch.load('nn_model.pt'))

# Evaluation
model.eval()
y_val_preds = []
y_val_trues = []  # Initialize list for true target values
with torch.no_grad():
    for x_val, y_val in val_loader:
        x_val = x_val.cuda()
        y_val_trues.append(y_val.cpu().numpy())  # Append array to list
        with autocast():
            preds = model(x_val).detach().cpu().numpy()
            y_val_preds.extend(preds)

# Concatenate the predictions into a single numpy array and squeeze it to match dimensions
y_val_preds = np.concatenate(y_val_preds).squeeze()
y_val_trues = np.concatenate(y_val_trues)  # Convert list of arrays to a single numpy array

# Calculate MAE
mae_nn = mean_absolute_error(y_val_trues, y_val_preds)

# Remove or replace special characters in feature names
X_train.columns = X_train.columns.str.replace('[^A-Za-z0-9]', '_')
X_val.columns = X_val.columns.str.replace('[^A-Za-z0-9]', '_')
X_test.columns = X_test.columns.str.replace('[^A-Za-z0-9]', '_')

# LightGBM model
lgbm_model = LGBMRegressor(device='gpu', n_jobs=-1)
lgbm_model.fit(X_train, y_train)
y_pred_lgbm = lgbm_model.predict(X_val)
mae_lgbm = mean_absolute_error(y_val, y_pred_lgbm)
joblib.dump(lgbm_model, 'lgbm_model.pkl')

# Initialize a dictionary to store the MAE results
mae_results = {
    'XGBoost': mae_xgb,
    'CatBoost': mae_cat,
    'ElasticNet': mae_elastic,
    'AdaBoost': mae_ada,
    'Random Forest': mae_forest,
    'Decision Tree': mae_tree,
    'SVR': mae_svr,
    'KNN': mae_knn,
    'Linear Regression': mae_lr,
    'Gradient Boosting': mae_gb,
    'Ridge Regression': mae_ridge,
    'Lasso Regression': mae_lasso,
    'Neural Network': mae_nn,
    'LightGBM': mae_lgbm
}

# Sort the dictionary based on MAE (lowest is best)
sorted_mae_results = {k: v for k, v in sorted(mae_results.items(), key=lambda item: item[1])}

# Open a file for writing the sorted MAE results
with open('mae_results.txt', 'a') as f:
    for model, mae in sorted_mae_results.items():
        f.write(f'{model} MAE: {mae}\n')

f.close()

# Get a list of the model names sorted by performance
sorted_models = list(sorted_mae_results.keys())

# Print the best performing two algorithms
print(f'The best performing algorithm is: {sorted_models[0]}')
print(f'The second best performing algorithm is: {sorted_models[1]}')

print('Finished')
