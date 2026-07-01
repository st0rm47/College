import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, association_rules

#Read the Dataset
data = pd.read_csv("../data/AprioriData.csv")

print("Original Dataset")
print(data)

# Convert Transactions into List
transactions = []
for items in data["Items"]:
    transactions.append(items.split(","))

# Convert the list of transactions into a one-hot encoded DataFrame
te = TransactionEncoder()
encoded_data = te.fit(transactions).transform(transactions)
basket = pd.DataFrame(encoded_data, columns=te.columns_)
print("\nOne-Hot Encoded Dataset")
print(basket)

# Generate Frequent Itemsets
min_support = 0.20
frequent_itemsets = apriori(
    basket,
    min_support=min_support,
    use_colnames=True
)

# Generate Association Rules
min_confidence = 0.60
rules = association_rules(
    frequent_itemsets,
    metric="confidence",
    min_threshold=min_confidence
)

# Convert frozensets to strings for better readability
frequent_itemsets["itemsets"] = frequent_itemsets["itemsets"].apply(
    lambda x: ", ".join(sorted(list(x)))
)

rules["antecedents"] = rules["antecedents"].apply(
    lambda x: ", ".join(sorted(list(x)))
)

rules["consequents"] = rules["consequents"].apply(
    lambda x: ", ".join(sorted(list(x)))
)

# Display selected columns
rules = rules[
    [
        "antecedents",
        "consequents",
        "support",
        "confidence",
    ]
]

print("\nFrequent Itemsets")
print(frequent_itemsets)

print("\nAssociation Rules")
print(rules)

# Display Parameters
print("\nMinimum Support :", min_support)
print("Minimum Confidence :", min_confidence)