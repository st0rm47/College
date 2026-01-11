# Write a program to view a product list and add to wish list features for the products in an ecommerce store. Assuming that the list of products is already in a datastructure or table for products. Also display the wish list. 


### 1.index.html
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
    <!-- Product List -->
    <div>
        <h2>Available Products</h2>
        <div id="products" class="product-grid">
            <!-- Products appear here -->
        </div>
    </div>

    <!-- Wish List -->
    <div id="wish-list">
        <h2>Wish List</h2>
        <ul id="wish-list-items">
            <!-- Wish list items displayed dynamically -->
        </ul>
    </div>

    <script src="script.js"></script>
</body>
</html>
```


### 2.script.js
```javascript
// Sample product data
const products = [
    { id: 1, name: "Shirt", price: 10 },
    { id: 2, name: "Tshirt", price: 20 },
    { id: 3, name: "Jacket", price: 30 },
    { id: 4, name: "Sneakers", price: 50 },
    { id: 5, name: "Cap", price: 15 }
];

const wishListItems = [];

// Display products
function displayProducts() {
    const container = document.getElementById("products");
    container.innerHTML = "";

    products.forEach(product => {
        const div = document.createElement("div");
        div.className = "product-card";

        div.innerHTML = `
            <h3>${product.name}</h3>
            <p class="price">$${product.price}</p>
            <button onclick="addToWishList(${product.id})">Add to Wish List</button>
        `;

        container.appendChild(div);
    });
}

// Add to wish list
function addToWishList(productId) {
    const product = products.find(p => p.id === productId);

    // Prevent duplicates
    const exists = wishListItems.find(item => item.id === productId);
    if (exists) {
        alert("Product is already in your wish list!");
        return;
    }

    wishListItems.push(product);
    displayWishListItems();
}

// Display wish list
function displayWishListItems() {
    const wishList = document.getElementById("wish-list-items");
    wishList.innerHTML = "";

    wishListItems.forEach(item => {
        const li = document.createElement("li");
        li.innerHTML = `
            <span>${item.name}</span>
            <span>$${item.price}</span>
        `;
        wishList.appendChild(li);
    });
}

// Initial display
displayProducts();
```


### 3.styles.css
```css

body {
    font-family: Arial, sans-serif;
    background-color: #f4f6f9;
    margin: 0;
    padding: 20px;
}

h1 {
    text-align: center;
    color: #222;
    margin-bottom: 30px;
}

h2 {
    color: #333;
    margin-bottom: 15px;
}

/* Product Grid */
.product-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(220px, 1fr));
    gap: 20px;
}

/* Product Card */
.product-card {
    background-color: #fff;
    padding: 15px;
    border-radius: 10px;
    box-shadow: 0 3px 10px rgba(0,0,0,0.1);
    text-align: center;
    transition: transform 0.2s, box-shadow 0.2s;
}

.product-card:hover {
    transform: translateY(-5px);
    box-shadow: 0 8px 20px rgba(0,0,0,0.15);
}

.product-card h3 {
    margin-bottom: 5px;
}

.product-card .price {
    color: #28a745;
    font-weight: bold;
    font-size: 18px;
}

.product-card button {
    margin-top: 10px;
    padding: 8px 12px;
    background-color: #ff4081;
    border: none;
    border-radius: 5px;
    color: white;
    font-weight: bold;
    cursor: pointer;
    transition: background-color 0.2s;
}

.product-card button:hover {
    background-color: #e73370;
}

/* Cards */
.card {
    background-color: #fff;
    padding: 20px;
    margin-top: 30px;
    border-radius: 10px;
    box-shadow: 0 3px 10px rgba(0,0,0,0.1);
}

/* Wish List Items */
#wish-list-items li {
    background-color: #fff7e6;
    border-left: 5px solid #ff4081;
    padding: 10px;
    margin: 5px 0;
    border-radius: 5px;
    display: flex;
    justify-content: space-between;
    align-items: center;
}

#wish-list-items li span {
    font-weight: bold;
}

/* Responsive */
@media (max-width: 600px) {
    .product-grid {
        grid-template-columns: 1fr;
    }
}
