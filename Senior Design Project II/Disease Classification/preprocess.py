import pandas as pd
from sklearn.model_selection import train_test_split
from ydata_profiling import ProfileReport

# Load the dataset
df = pd.read_csv('./data_set_thalBD.csv')

# Drop Highly correlated features
df = df.drop(columns=['hbF'])
df = df.drop(columns=['hbH'])

# EDA original
profile = ProfileReport(df, title='Pandas Profiling Report', explorative=True, minimal=False)
profile.to_file("./output/eda_thalBD.html")

# Drop rows with missing data
df.dropna(inplace=True)

# One-hot encode the 'Sex' column
df['Sex'] = df['Sex'].apply(lambda x: 1 if x == 'M' else 0)

# One-hot encode the 'Thalassemia Type' column
thalassemia_type_map = {
    'Beta Minor': 1,
    'Beta Major': 2,
    'Alpha Major': 3,
    'Alpha Minor': 0
}
df['Thalassemia Type'] = df['Thalassemia Type'].map(thalassemia_type_map)

# EDA processed
profile = ProfileReport(df, title='Pandas Profiling Report', explorative=True, minimal=False)
profile.to_file("./output/eda_thalBD_processed.html")

# Split the dataset with stratify into train and validation sets
train, val = train_test_split(df, test_size=0.2, random_state=42, stratify=df['Thalassemia Type'])

# Normalize excluding 'Sex' and 'Thalassemia Type'
features_to_normalize = df.columns.difference(['Thalassemia Type', 'Sex'])

for feature in features_to_normalize:
    mean = train[feature].mean()
    std = train[feature].std()

    train[feature] = (train[feature] - mean) / std
    val[feature] = (val[feature] - mean) / std

# Save the new datasets
train.to_csv("./thalBD_train.csv", index=False)
val.to_csv("./thalBD_val.csv", index=False)
