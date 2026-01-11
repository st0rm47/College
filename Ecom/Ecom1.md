# Write a program to create add products and display products in an ecommerce store. The products should include product name, price, description etc. Also implement search products feature to search items from data structure or table containing products.


### 1. index.html
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>E-Commerce Store</title>
    <link rel="stylesheet" type="text/css" href="styles.css"> 
</head>
<body>
    <h1>🛒 Simple E-Commerce Store</h1>

    <!-- Product Form -->
    <div class="card">
        <h2>Add Product</h2>
        Product Name <input type="text" id="productName" placeholder="Product Name">
        Price <input type="number" id="productPrice" placeholder="Price">
        Category
        <select id="productCategory">
            <option value="">Select Category</option>
            <option>Electronics</option>
            <option>Clothing</option>
            <option>Books</option>
            <option>Accessories</option>
        </select>
        Description<textarea id="productDescription" placeholder="Product Description"></textarea>

        <button onclick="addProduct()" class="btn add-btn">Add Product</button>
    </div>

    <!-- Search -->
    <div class="card">
        <h2>Search Product</h2>
        <input type="text" id="searchInput" placeholder="Search by name or category">
        <button onclick="searchProducts()" class="btn search-btn">Search</button>
    </div>

    <!-- Product List -->
    <div>
        <h2>Available Products</h2>
        <div id="products" class="product-grid">
            <!-- Products appear here -->
        </div>
    </div>

    <script src="script.js"></script>
</body>
</html>
```



### 2. styles.css
```css
body {
    font-family: Arial, sans-serif;
    background-color: #f4f6f9;
    padding: 20px;
}

h1 {
    text-align: center;
    color: #222;
}

h2 {
    color: #333;
}

.card {
    background: white;
    padding: 20px;
    margin-bottom: 20px;
    border-radius: 8px;
    box-shadow: 0 3px 10px rgba(0,0,0,0.1);
}

input, textarea, select {
    width: 100%;
    padding: 10px;
    margin: 8px 0;
    border-radius: 5px;
    border: 1px solid #ccc;
}

textarea {
    resize: none;
    height: 80px;
}

.btn {
    padding: 10px;
    border: none;
    border-radius: 5px;
    color: white;
    cursor: pointer;
}

.add-btn {
    background-color: #28a745;
}

.search-btn {
    background-color: #007bff;
}

.btn:hover {
    opacity: 0.9;
}

/* Product Layout */
.product-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
    gap: 20px;
}

/* Product Card */
.product-card {
    background: white;
    padding: 15px;
    border-radius: 8px;
    box-shadow: 0 3px 8px rgba(0,0,0,0.1);
    transition: transform 0.2s;
}

.product-card:hover {
    transform: translateY(-5px);
}


.product-card h3 {
    margin: 10px 0 5px;
}

.category {
    font-size: 14px;
    color: #007bff;
}

.price {
    font-size: 18px;
    font-weight: bold;
    color: #28a745;
}

.description {
    font-size: 14px;
    color: #555;
}
```



### 3. script.js
```javascript
let products = [];

// Add Product
function addProduct() {
    const name = document.getElementById("productName").value.trim();
    const price = document.getElementById("productPrice").value;
    const category = document.getElementById("productCategory").value;
    const description = document.getElementById("productDescription").value.trim();

    if (!name || !price || !category || !description) {
        alert("Please fill all fields!");
        return;
    }

    const product = {
        name,
        price,
        category,
        description
    };

    products.push(product);
    displayProducts();

    // Clear form
    document.getElementById("productName").value = "";
    document.getElementById("productPrice").value = "";
    document.getElementById("productCategory").value = "";
    document.getElementById("productDescription").value = "";
}

// Display Products
function displayProducts(list = products) {
    const container = document.getElementById("products");
    container.innerHTML = "";

    if (list.length === 0) {
        container.innerHTML = "<p>No products found.</p>";
        return;
    }

    list.forEach(product => {
        const div = document.createElement("div");
        div.className = "product-card";

        div.innerHTML = `
            <h3>${product.name}</h3>
            <p class="category">${product.category}</p>
            <p class="price">$ ${product.price}</p>
            <p class="description">${product.description}</p>
        `;

        container.appendChild(div);
    });
}

// Search Products
function searchProducts() {
    const query = document.getElementById("searchInput").value.toLowerCase();

    const filteredProducts = products.filter(product =>
        product.name.toLowerCase().includes(query) ||
        product.category.toLowerCase().includes(query)
    );

    displayProducts(filteredProducts);
}
