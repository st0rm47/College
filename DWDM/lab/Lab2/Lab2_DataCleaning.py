import pandas as pd

# Load the dataset
df = pd.read_csv("../data/DataCleaning.csv")

# Display dataset information
print("\nDataset Information:")
print(df.info())

# Display missing values
print("\nMissing Values:")
print(df.isnull().sum())

# 1. Handle Missing Values
df1 = df.copy()

# Fill missing Date using forward fill
df1["Date"] = df1["Date"].ffill()

# Fill missing Calories with mean
mean_calories = df1["Calories"].mean()
df1["Calories"] = df1["Calories"].fillna(mean_calories)

print("\nDataset after handling missing values:")
print(df1)

# 2. Remove Duplicate Rows
df2 = df1.copy()
df2 = df2.drop_duplicates()

print("\nDataset after removing duplicates:")
print(df2)

# 3. Correct Date Format
df3 = df2.copy()

# Remove extra apostrophes
df3["Date"] = df3["Date"].astype(str).str.replace("'", "", regex=False)

# Convert Date column to datetime
df3["Date"] = pd.to_datetime(df3["Date"], errors="coerce")

# Remove rows with invalid dates
df3 = df3.dropna(subset=['Date'])

print("\nDataset after correcting date format:")
print(df3)


# 4. Handle Outliers
df4 = df3.copy()
for i in df4.index:
    if df4.loc[i, "Duration"] > 120:
        df4.loc[i, "Duration"] = 120

print("\nDataset after handling outliers:")
print(df4)

# 5. Final Cleaned Dataset
print("\nFinal Cleaned Dataset:")
print(df4)

# Save cleaned dataset
df4.to_csv("../data/CleanedData.csv", index=False)

print("\nData cleaning completed successfully by Subodh Ghimire.")
