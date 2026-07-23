# ==============================
# 1. IMPORT LIBRARIES
# ==============================
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# ==============================
# 2. LOAD DATASET
# ==============================
# For CSV file
df = pd.read_csv("your_file.csv")

# For Excel file (uncomment if needed)
# df = pd.read_excel("your_file.xlsx")

# ==============================
# 3. BASIC INFORMATION
# ==============================
print("First 5 rows:")
print(df.head())

print("\nLast 5 rows:")
print(df.tail())

print("\nDataset shape (rows, columns):")
print(df.shape)

print("\nColumn names:")
print(df.columns)

print("\nData types and non-null counts:")
print(df.info())

# ==============================
# 4. DESCRIPTIVE STATISTICS
# ==============================
print("\nStatistical summary (numerical columns):")
print(df.describe())

print("\nStatistical summary (all columns):")
print(df.describe(include='all'))

# ==============================
# 5. CHECK MISSING VALUES
# ==============================
print("\nMissing values per column:")
print(df.isnull().sum())

# Percentage of missing values
missing_percent = (df.isnull().sum() / len(df)) * 100
print("\nMissing value percentage:")
print(missing_percent)

# ==============================
# 6. HANDLE MISSING VALUES
# ==============================
# Example strategies

# Fill numeric columns with mean
for col in df.select_dtypes(include=np.number):
    df[col].fillna(df[col].mean(), inplace=True)

# Fill categorical columns with mode
for col in df.select_dtypes(include='object'):
    df[col].fillna(df[col].mode()[0], inplace=True)

# ==============================
# 7. CHECK DUPLICATES
# ==============================
print("\nDuplicate rows:")
print(df.duplicated().sum())

# Remove duplicates
df.drop_duplicates(inplace=True)

# ==============================
# 8. OUTLIER DETECTION (IQR METHOD)
# ==============================
numeric_cols = df.select_dtypes(include=np.number).columns

for col in numeric_cols:
    Q1 = df[col].quantile(0.25)
    Q3 = df[col].quantile(0.75)
    IQR = Q3 - Q1

    lower = Q1 - 1.5 * IQR
    upper = Q3 + 1.5 * IQR

    outliers = df[(df[col] < lower) | (df[col] > upper)]
    print(f"\nOutliers in {col}: {len(outliers)}")

# ==============================
# 9. DATA DISTRIBUTION VISUALIZATION
# ==============================
for col in numeric_cols:
    plt.figure()
    plt.hist(df[col])
    plt.title(f"Distribution of {col}")
    plt.xlabel(col)
    plt.ylabel("Frequency")
    plt.show()

# ==============================
# 10. CORRELATION ANALYSIS
# ==============================
correlation = df.corr(numeric_only=True)
print("\nCorrelation matrix:")
print(correlation)

plt.figure()
plt.imshow(correlation)
plt.title("Correlation Heatmap")
plt.colorbar()
plt.show()

# ==============================
# 11. GROUP ANALYSIS (IF CATEGORICAL EXISTS)
# ==============================
categorical_cols = df.select_dtypes(include='object').columns

for col in categorical_cols:
    print(f"\nValue counts for {col}:")
    print(df[col].value_counts())

# ==============================
# 12. SAVE CLEANED DATA
# ==============================
df.to_csv("cleaned_data.csv", index=False)

print("\nEDA completed successfully")