import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import DBSCAN

# Step 1: Create Dataset
X = np.array([
    [2,2],[2,3],[3,2],[3,3],[2.5,2.5],        # Cluster 1

    [8,8],[8,9],[9,8],[9,9],[8.5,8.5],        # Cluster 2

    [5,12],[6,12],[5.5,13],[6,13],[5.8,12.5], # Cluster 3

    [12,2],[13,13]                            # Noise
])

print("Dataset")
print(X)

# Step 2: Apply DBSCAN
model = DBSCAN(eps=1.5, min_samples=3)

labels = model.fit_predict(X)

print("\nCluster Labels")
print(labels)

# Step 3: Plot Clusters

markers = ['o', 's', '^', 'D', 'P', '*']
colors = ['blue', 'green', 'orange', 'purple', 'brown', 'pink']

plt.figure(figsize=(8,6))

unique_labels = set(labels)

for cluster in unique_labels:

    points = X[labels == cluster]

    if cluster == -1:
        plt.scatter(
            points[:,0],
            points[:,1],
            marker='x',
            color='red',
            s=120,
            label='Noise'
        )

    else:
        plt.scatter(
            points[:,0],
            points[:,1],
            marker=markers[cluster % len(markers)],
            color=colors[cluster % len(colors)],
            s=120,
            label=f'Cluster {cluster+1}'
        )

plt.title("DBSCAN Clustering")
plt.xlabel("Feature 1")
plt.ylabel("Feature 2")
plt.legend()
plt.grid(True)

plt.show()