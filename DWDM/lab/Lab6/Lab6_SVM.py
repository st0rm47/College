import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# Step 1: Create Dataset
X = np.array([
    [1, 2], [2, 3], [3, 3], [4, 4],
    [6, 7], [7, 8], [8, 7], [9, 9]
])

y = np.array([0, 0, 0, 0, 1, 1, 1, 1])

print("Features")
print(X)

print("\nTarget")
print(y)

# Step 2: Split Dataset
X_train, X_test, y_train, y_test = train_test_split( X, y, test_size=0.25, random_state=42)

# Step 3: Train SVM Model
model = svm.SVC(kernel="linear")
model.fit(X_train, y_train)

# Step 4: Prediction
y_pred = model.predict(X_test)

print("\nActual Class")
print(y_test)

print("\nPredicted Class")
print(y_pred)

# Step 5: Accuracy
accuracy = accuracy_score(y_test, y_pred)
print("\nAccuracy :", round(accuracy * 100, 2), "%")

# Step 6: Predict New Data
new_data = np.array([
    [5, 6],
    [2, 2],
    [8, 8]
])
prediction = model.predict(new_data)

print("\nPrediction for New Data")
for point, label in zip(new_data, prediction):
    print(point, "-> Class", label)

# Step 7: Plot Hyperplane
plt.figure(figsize=(8,6))

# Plot data points
plt.scatter(X[:,0], X[:,1], c=y, cmap="viridis", s=100, edgecolors="black")

# Create mesh grid to plot decision boundary
ax = plt.gca()
xlim = ax.get_xlim()
ylim = ax.get_ylim()
xx = np.linspace(xlim[0], xlim[1], 30)
yy = np.linspace(ylim[0], ylim[1], 30)
YY, XX = np.meshgrid(yy, xx)
xy = np.vstack([XX.ravel(), YY.ravel()]).T
Z = model.decision_function(xy).reshape(XX.shape)

# Decision boundary and margins
ax.contour( XX, YY, Z, levels=[-1,0,1], colors="black", linestyles=["--","-","--"])

# Highlight Support Vectors
ax.scatter(
    model.support_vectors_[:,0],
    model.support_vectors_[:,1],
    s=220,
    facecolors="none",
    edgecolors="red",
    linewidth=2,
    label="Support Vectors"
)

plt.title("Support Vector Machine")
plt.xlabel("Feature 1")
plt.ylabel("Feature 2")
plt.legend()

plt.show()