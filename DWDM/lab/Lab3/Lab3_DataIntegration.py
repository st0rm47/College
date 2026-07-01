import pandas as pd
import mysql.connector

# Read CSV file
csv_data = pd.read_csv("../data/Online RetailSmallData.csv")

# Read Excel file
excel_data = pd.read_excel("../data/Online RetailSmall.xlsx")

# Connect to MySQL
conn = mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="retail_db"
)

# Read SQL table
sql_data = pd.read_sql("SELECT * FROM ONLINE_DATA3", conn)

# Close connection
conn.close()

# Rename SQL columns to match CSV and Excel columns
sql_data.rename(columns={
    "STOCKCODE": "StockCode",
    "DESCRIPTION": "Description",
    "CUSTOMERID": "CustomerID",
    "COUNTRY": "Country",
    "QUANTITY": "Quantity",
}, inplace=True)

# Add missing columns to SQL Dataset
sql_data["InvoiceNo"] = pd.NA
sql_data["InvoiceDate"] = pd.NA
sql_data["UnitPrice"] = pd.NA

# Add missing columns to Excel Dataset
excel_data["InvoiceNo"] = pd.NA

# Standardize Date Format
csv_data["InvoiceDate"] = pd.to_datetime(csv_data["InvoiceDate"], errors = "coerce")
excel_data["InvoiceDate"] = pd.to_datetime(excel_data["InvoiceDate"], errors = "coerce")

# Remove leading/trailing spaces from column names
for df in [csv_data, excel_data, sql_data]:
    df["StockCode"] = df["StockCode"].astype(str).str.strip()
    df["Description"] = df["Description"].astype(str).str.strip()
    df["Country"] = df["Country"].astype(str).str.strip()
    
# Arrange all datasets in the same column order
columns = ["InvoiceNo", "StockCode", "Description", "Quantity", "InvoiceDate", "UnitPrice", "CustomerID", "Country"]
csv_data = csv_data[columns]
excel_data = excel_data[columns]
sql_data = sql_data[columns]

# Integrate datasets
integrated_data = pd.concat([csv_data, excel_data, sql_data], ignore_index=True)

# Remove duplicate records
integrated_data = integrated_data.drop_duplicates(
    subset=["StockCode", "Description", "CustomerID", "Country", "Quantity"], keep = "first"
)

print("\nIntegrated Dataset")
print(integrated_data.head())

print("\nIntegrated Dataset Information")
print(integrated_data.info())

# Save integrated dataset
integrated_data.to_csv("../data/IntegratedData.csv", index=False)

print("\nData Integration Completed Successfully by Subodh Ghimire.")