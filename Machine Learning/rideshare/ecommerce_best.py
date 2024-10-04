# ecommerce_best.py
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder, MinMaxScaler
from xgboost import XGBRegressor
from catboost import CatBoostRegressor
from sklearn.metrics import mean_absolute_error
from ydata_profiling import ProfileReport
import seaborn as sns
import matplotlib.pyplot as plt
import joblib

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

# Initialize a dictionary to store the MAE results
mae_results = {
    'XGBoost': mae_xgb,
    'CatBoost': mae_cat
}

# Sort the dictionary based on MAE (lowest is best)
sorted_mae_results = {k: v for k, v in sorted(mae_results.items(), key=lambda item: item[1])}

# Open a file for writing the sorted MAE results
with open('mae_results_best.txt', 'a') as f:
    for model, mae in sorted_mae_results.items():
        f.write(f'{model} MAE: {mae}\n')

f.close()
print('Finished')
