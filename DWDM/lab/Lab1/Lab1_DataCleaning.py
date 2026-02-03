import pandas as pd
import matplotlib.pyplot as plt

df= pd.read_csv('data\DataCleaning.csv')

# 1. Inspect the data
print("-"*60)
print("Initial DataFrame:")
print(df.head())
print("-"*60)
print(df.info())

# 2. Handling the missing values 
print("-"*60)
print("Handling missing values:")
print("-"*60)
print("Missing values before handling:")
print(df.isnull().sum())

## Found 2 rows NaN in Calories column and a row in Date column 

# 3. Clean the Date column - remove trailing quotes and parse as datetime
df['Date'] = df['Date'].astype(str).str.replace("'", "")
df['Date'] = pd.to_datetime(df['Date'], format='mixed', errors='coerce')

# Drop rows with NaT (parsing errors) in Date column
df = df.dropna(subset=['Date'])

# 4. Filling the missing Calorie values with the mean 
mean_calories = df['Calories'].mean()
df['Calories'] = df['Calories'].fillna(mean_calories)

print("-"*60)
print("Missing values after handling:")
print(df.isnull().sum())

## Visualize the data distribution of columns 
plt.figure(figsize=(12, 5))
plt.subplot(1, 3, 1)
plt.hist(df['Duration'], bins=20, color='skyblue', edgecolor='black')
plt.title('Age Distribution')
plt.xlabel('Age')
plt.ylabel('Frequency')

plt.subplot(1, 3, 2)
plt.hist(df['Calories'], bins=20, color='lightgreen', edgecolor='black')
plt.title('Calories Distribution (After Cleaning)')
plt.xlabel('Calories')
plt.ylabel('Frequency')

plt.subplot(1, 3, 3)
plt.hist(df['Pulse'], bins=20, color='salmon', edgecolor='black')
plt.title('Pulse Distribution')
plt.xlabel('Pulse')
plt.ylabel('Frequency')

plt.tight_layout()
plt.show()