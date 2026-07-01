import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# Step 1: Create Dataset
X = np.array([[1,2],[2,1],[2,2],[3,2],[2,3],[8,8],[9,8],[8,9],[9,9],[10,8],[4,10],[5,11],[6,10],[5,9],[6,11]])
print("Dataset")
print(X)

# Step 2: Apply K-Means
k = 3
kmeans = KMeans(
    n_clusters=k,
    random_state=42,
    n_init=10
)
kmeans.fit(X)
labels = kmeans.labels_
centroids = kmeans.cluster_centers_
print("\nCluster Labels")
print(labels)

print("\nCluster Centroids")
print(centroids)

# Step 3: Plot Clusters
markers = ['o', 'x', 's']
colors = ['blue', 'green', 'orange']

plt.figure(figsize=(8,6))

for i in range(k):
    cluster_points = X[labels == i]

    plt.scatter(
        cluster_points[:,0],
        cluster_points[:,1],
        marker=markers[i],
        color=colors[i],
        s=120,
        label=f"Cluster {i+1}"
    )

# Plot Centroids
plt.scatter(
    centroids[:,0],
    centroids[:,1],
    marker='*',
    color='red',
    s=300,
    label='Centroids'
)

plt.title("K-Means Clustering")
plt.xlabel("Feature 1")
plt.ylabel("Feature 2")
plt.grid(True)
plt.legend(loc='upper left')

plt.show()