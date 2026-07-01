import pandas as pd
import math
from collections import Counter
from pprint import pprint

# Read the dataset
df = pd.read_csv("../data/ID3_golf_dataset.csv")

# Get the target attribute from the dataset
t = df.keys()[-1]
print('Target Attribute is: ', t)

# Get the attribute names from input dataset
attribute_names = list(df.keys())

#Remove the target attribute from the attribute names list
attribute_names.remove(t) 
print('Predicting Attributes: ', attribute_names)

# Function to calculate the entropy of a list of probabilities
def entropy(probs):  
    return sum( [-prob*math.log(prob, 2) for prob in probs])

#Function to calulate the entropy of the given Datasets/List with respect to target attributes
def entropy_of_list(ls,value):   
    total_instances = len(ls) 
    cnt = Counter(ls)
    probs = [x / total_instances for x in cnt.values()]  
 
    return entropy(probs) 


# Function to calculate the information gain of a given attribute with respect to the target attribute
def information_gain(df, split_attribute, target_attribute,battr):
    
    # Group the data based on attribute values
    df_split = df.groupby(split_attribute) 
    glist=[]
    for gname,group in df_split:
        glist.append(gname) 
    
    # Reverse the list of attribute values to maintain the order of processing
    glist.reverse()
    nobs = len(df.index) * 1.0   
    df_agg1=df_split.agg({target_attribute:lambda x:entropy_of_list(x, glist.pop())})
    df_agg2=df_split.agg({target_attribute :lambda x:len(x)/nobs})
    
    df_agg1.columns=['Entropy']
    df_agg2.columns=['Proportion']
    
    # Calculate Information Gain:
    new_entropy = sum( df_agg1['Entropy'] * df_agg2['Proportion'])
    if battr != 'S':
        old_entropy = entropy_of_list(df[target_attribute],"S-" + str(df[battr].iloc[0]))
    else:
        old_entropy = entropy_of_list(df[target_attribute],battr)
    return old_entropy - new_entropy


# Function to implement the ID3 algorithm for building a decision tree
def id3(df, target_attribute, attribute_names, default_class=None,default_attr='S'):
    cnt = Counter(x for x in df[target_attribute])

    if len(cnt) == 1:
        return next(iter(cnt))
    elif df.empty or (not attribute_names):
        return default_class
    else:
        default_class = cnt.most_common(1)[0][0]
        # Compute the Information Gain of the attributes:
        gainz=[]
        for attr in attribute_names:
            ig= information_gain(df, attr, target_attribute,default_attr)
            gainz.append(ig)
            print('\nInformation gain','(',attr,')',':', ig)
        
        # Select the attribute with the highest information gain as the best attribute for splitting
        best_attr = attribute_names[gainz.index(max(gainz))]
        print ('\nBest attribute for splitting is:', best_attr)
        
        # Create an empty tree, to be populated in a moment
        tree = {best_attr:{}}
        
        remaining_attribute_names =[i for i in attribute_names if i != best_attr]
        
        # Split dataset on each split, recursively call this algorithm.P
        for attr_val, data_subset in df.groupby(best_attr):
            subtree = id3(data_subset,target_attribute, remaining_attribute_names,default_class,best_attr)
            tree[best_attr][attr_val] = subtree
        return tree
    
# Function to calulate the entropy of the given Dataset with respect to target attributes
def entropy_dataset(a_list):  
    cnt = Counter(x for x in a_list)   
    num_instances = len(a_list)*1.0   
    probs = [x / num_instances for x in cnt.values()]  
    return entropy(probs) 
    
total_entropy = entropy_dataset(df['PlayGolf'])
print("\nTotal Entropy of PlayGolf Dataset: ", total_entropy)
print("=========================================================")

tree = id3(df,t,attribute_names)
print("\n=======================")
print("Generated Decision Tree")
print("=======================")

def print_tree(tree, indent="", last=True):
    if not isinstance(tree, dict):
        print(indent + ("└── " if last else "├── ") + str(tree))
        return
    node = list(tree.keys())[0]
    branches = tree[node]
    if indent == "":
        print(node)
    else:
        print(indent + ("└── " if last else "├── ") + node)

    branch_items = list(branches.items())
    for i, (value, subtree) in enumerate(branch_items):
        is_last = (i == len(branch_items) - 1)
        if isinstance(subtree, dict):
            print(indent + ("    " if last else "│   ") +
                  ("└── " if is_last else "├── ") + str(value))
            print_tree(subtree, indent + ("    " if last else "│   ") + ("    " if is_last else "│   "),True)
        else:
            print(indent + ("    " if last else "│   ") +
                  ("└── " if is_last else "├── ") +
                  f"{value} → {subtree}")               
print_tree(tree)

attribute = next(iter(tree))
print("\nRoot Node :", attribute)
print("Branches  :", list(tree[attribute].keys()))