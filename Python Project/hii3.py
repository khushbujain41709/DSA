import matplotlib.pyplot as plt
import pandas as pd

# Load data
df = pd.read_csv("data.csv")
# df = pd.read_excel("data.xlsx")

# =================================================
# 1. HISTOGRAM → Distribution of numerical column
# =================================================
plt.figure()
plt.hist(df["Age"])
plt.title("Age Distribution")
plt.xlabel("Age")
plt.ylabel("Frequency")
plt.show()


# =================================================
# 2. BAR CHART → Categorical comparison
# =================================================
category_counts = df["Category"].value_counts()

plt.figure()
plt.bar(category_counts.index, category_counts.values)
plt.title("Count by Category")
plt.xlabel("Category")
plt.ylabel("Count")
plt.xticks(rotation=45)
plt.show()


# =================================================
# 3. PIE CHART → Percentage share
# =================================================
payment_counts = df["PaymentMethod"].value_counts()

plt.figure()
plt.pie(payment_counts.values, labels=payment_counts.index, autopct="%1.1f%%")
plt.title("Payment Method Share")
plt.show()


# =================================================
# 4. LINE CHART → Trend over time
# =================================================
df["OrderDate"] = pd.to_datetime(df["OrderDate"])

monthly_sales = df.groupby(df["OrderDate"].dt.month)["Revenue"].sum()

plt.figure()
plt.plot(monthly_sales.index, monthly_sales.values)
plt.title("Monthly Revenue Trend")
plt.xlabel("Month")
plt.ylabel("Revenue")
plt.show()


# =================================================
# 5. SCATTER PLOT → Relationship between variables
# =================================================
plt.figure()
plt.scatter(df["Price"], df["Revenue"])
plt.title("Price vs Revenue")
plt.xlabel("Price")
plt.ylabel("Revenue")
plt.show()


# =================================================
# 6. BOX PLOT → Outlier detection
# =================================================
plt.figure()
plt.boxplot(df["Revenue"])
plt.title("Revenue Outliers")
plt.ylabel("Revenue")
plt.show()


# =================================================
# 7. CORRELATION HEATMAP
# =================================================
corr = df[["Age", "Quantity", "Price", "Revenue"]].corr()

plt.figure()
plt.imshow(corr)
plt.title("Correlation Heatmap")
plt.colorbar()
plt.xticks(range(len(corr.columns)), corr.columns, rotation=45)
plt.yticks(range(len(corr.columns)), corr.columns)
plt.show()