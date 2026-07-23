# ==========================================
# 1. IMPORT LIBRARIES
# ==========================================
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# ==========================================
# 2. LOAD DATASET
# ==========================================
# CSV file
df = pd.read_csv("sales_data.csv")

# Excel file (use this instead if needed)
# df = pd.read_excel("sales_data.xlsx")

print("Dataset loaded successfully\n")

# ==========================================
# 3. OVERVIEW OF DATASET
# ==========================================
print("First 5 rows:")
print(df.head())

print("\nDataset shape:")
print(df.shape)

print("\nColumn names:")
print(df.columns.tolist())

print("\nData types and null values:")
df.info()

# ==========================================
# 4. DATA TYPE CONVERSION
# ==========================================
# Convert OrderDate to datetime
df["OrderDate"] = pd.to_datetime(df["OrderDate"], errors="coerce")

# ==========================================
# 5. MISSING VALUE ANALYSIS
# ==========================================
print("\nMissing values count:")
print(df.isnull().sum())

# Fill numeric columns with median (better than mean for skewed data)
for col in df.select_dtypes(include=np.number):
    df[col].fillna(df[col].median(), inplace=True)

# Fill categorical columns with mode
for col in df.select_dtypes(include="object"):
    df[col].fillna(df[col].mode()[0], inplace=True)

# ==========================================
# 6. REMOVE DUPLICATE RECORDS
# ==========================================
print("\nDuplicate rows:", df.duplicated().sum())
df.drop_duplicates(inplace=True)

# ==========================================
# 7. FEATURE ENGINEERING
# ==========================================
# Extract month and year from OrderDate
df["OrderMonth"] = df["OrderDate"].dt.month
df["OrderYear"] = df["OrderDate"].dt.year

# Create Age Group column
df["AgeGroup"] = pd.cut(df["Age"],
                        bins=[0, 18, 30, 45, 60, 100],
                        labels=["Teen", "Young Adult", "Adult", "Senior", "Old"])

# ==========================================
# 8. DESCRIPTIVE STATISTICS
# ==========================================
print("\nNumerical summary:")
print(df.describe())

print("\nCategorical summary:")
print(df.describe(include="object"))

# ==========================================
# 9. OUTLIER DETECTION (IQR METHOD)
# ==========================================
numeric_cols = ["Quantity", "Price", "Revenue", "Age"]

for col in numeric_cols:
    Q1 = df[col].quantile(0.25)
    Q3 = df[col].quantile(0.75)
    IQR = Q3 - Q1

    lower = Q1 - 1.5 * IQR
    upper = Q3 + 1.5 * IQR

    outliers = df[(df[col] < lower) | (df[col] > upper)]
    print(f"Outliers in {col}: {len(outliers)}")

# ==========================================
# 10. UNIVARIATE ANALYSIS (DISTRIBUTIONS)
# ==========================================
plt.figure()
plt.hist(df["Revenue"])
plt.title("Revenue Distribution")
plt.xlabel("Revenue")
plt.ylabel("Frequency")
plt.show()

plt.figure()
plt.hist(df["Age"])
plt.title("Customer Age Distribution")
plt.xlabel("Age")
plt.ylabel("Count")
plt.show()

# ==========================================
# 11. CATEGORY ANALYSIS
# ==========================================
print("\nSales by Category:")
print(df.groupby("Category")["Revenue"].sum().sort_values(ascending=False))

print("\nSales by City:")
print(df.groupby("City")["Revenue"].sum().sort_values(ascending=False))

print("\nPayment Method Distribution:")
print(df["PaymentMethod"].value_counts())

# ==========================================
# 12. TIME SERIES ANALYSIS
# ==========================================
monthly_sales = df.groupby("OrderMonth")["Revenue"].sum()

plt.figure()
plt.plot(monthly_sales.index, monthly_sales.values)
plt.title("Monthly Revenue Trend")
plt.xlabel("Month")
plt.ylabel("Revenue")
plt.show()

# ==========================================
# 13. CORRELATION ANALYSIS
# ==========================================
corr = df[["Quantity", "Price", "Revenue", "Age"]].corr()

print("\nCorrelation Matrix:")
print(corr)

plt.figure()
plt.imshow(corr)
plt.title("Correlation Heatmap")
plt.colorbar()
plt.show()

# ==========================================
# 14. TOP BUSINESS INSIGHTS
# ==========================================
print("\nTop 5 Customers by Revenue:")
print(df.groupby("CustomerName")["Revenue"].sum().sort_values(ascending=False).head())

print("\nTop 5 Products by Revenue:")
print(df.groupby("Product")["Revenue"].sum().sort_values(ascending=False).head())

# ==========================================
# 15. SAVE CLEANED DATA
# ==========================================
df.to_csv("cleaned_sales_data.csv", index=False)

print("\nEDA Completed Successfully")
