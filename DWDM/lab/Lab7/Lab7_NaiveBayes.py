import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import CategoricalNB
from sklearn.metrics import accuracy_score

# Step 1: Read Dataset
data = pd.read_csv("../data/ID3_golf_dataset.csv")

# Step 2: Encode Categorical Data
label_encoder = LabelEncoder()
encoded_data = data.copy()
for column in encoded_data.columns:
    encoded_data[column] = label_encoder.fit_transform(encoded_data[column])
print("\nEncoded Dataset")
print(encoded_data)

# Step 3: Separate Features and Target
X = encoded_data.iloc[:, :-1]
y = encoded_data.iloc[:, -1]

print("\nFeatures")
print(X)
print("\nTarget")
print(y)

# Step 4: Split Dataset
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.40, random_state=42)

# Step 5: Train Naive Bayes Model
model = CategoricalNB()
model.fit(X_train, y_train)

# Step 6: Predict Test Data
y_pred = model.predict(X_test)

print("\nActual Class")
print(y_test.values)
print("\nPredicted Class")
print(y_pred)

# Step 7: Accuracy
accuracy = accuracy_score(y_test, y_pred)
print("\nAccuracy :", round(accuracy * 100, 2), "%")

# Step 8: Predict New Data
new_data = pd.DataFrame({
    "Outlook": ["Sunny"],
    "Temperature": ["Cool"],
    "Humidity": ["High"],
    "Windy": [False]
})

# Encode new data using the same mappings
encoded_new = new_data.copy()
for column in new_data.columns:
    encoder = LabelEncoder()
    encoder.fit(data[column])
    encoded_new[column] = encoder.transform(new_data[column])
prediction = model.predict(encoded_new)

# Decode prediction
target_encoder = LabelEncoder()
target_encoder.fit(data["PlayGolf"])
predicted_class = target_encoder.inverse_transform(prediction)

print("\nNew Data")
print(new_data)
print("\nPredicted Class :", predicted_class[0])