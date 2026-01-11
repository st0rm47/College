# Write a program to display a product list and add to cart features for the products in an ecommerce store. Assuming that the list of products is already in a data structure or table for products. Also display the items in the cart list.

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
    <!-- Product List -->
    <div>
        <h2>Available Products</h2>
        <div id="products" class="product-grid">
            <!-- Products appear here -->
        </div>
    </div>

    <!-- Cart -->
    <div class="cart">
        <h2>Shopping Cart</h2>
        <ul id="cart-items"></ul>
        <p class="total">Total: $<span id="total">0</span></p>
        <button onclick="checkout()" class="btn">Checkout</button>
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

/* Product Grid */
.product-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(220px, 1fr));
    gap: 20px;
    margin-bottom: 30px;
}

/* Product Card */
.product-card {
    background: white;
    padding: 15px;
    border-radius: 8px;
    box-shadow: 0 3px 8px rgba(0,0,0,0.1);
    text-align: center;
}

.product-card h3 {
    margin: 10px 0;
}

.price {
    color: #28a745;
    font-size: 18px;
    font-weight: bold;
}

.product-card button {
    margin-top: 10px;
    padding: 8px 12px;
    border: none;
    border-radius: 5px;
    background-color: #007bff;
    color: white;
    cursor: pointer;
}

.product-card button:hover {
    background-color: #0056b3;
}

/* Cart */
.cart {
    background: white;
    padding: 20px;
    border-radius: 8px;
    box-shadow: 0 3px 10px rgba(0,0,0,0.1);
}

.cart ul {
    list-style: none;
    padding: 0;
}

.cart li {
    padding: 8px 0;
    border-bottom: 1px solid #ddd;
}

.total {
    font-weight: bold;
    margin-top: 10px;
}

.btn {
    margin-top: 10px;
    padding: 10px 15px;
    background-color: #28a745;
    border: none;
    border-radius: 5px;
    color: white;
    cursor: pointer;
}

.btn:hover {
    opacity: 0.9;
}
```


### 3. script.js
```javascript
// Product data (already available data structure)
const products = [
    { id: 1, name: "Smartphone", price: 699, description: "Latest model smartphone with advanced features." },
    { id: 2, name: "Laptop", price: 999, description: "High-performance laptop for work and gaming." },
    { id: 3, name: "Headphones", price: 199, description: "Noise-cancelling over-ear headphones." },
    { id: 4, name: "Smartwatch", price: 299, description: "Stylish smartwatch with health tracking features." },
];

const cartItems = [];

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
            <p>${product.description}</p>
            <button onclick="addToCart(${product.id})">Add to Cart</button>
        `;

        container.appendChild(div);
    });
}

// Add to cart
function addToCart(productId) {
    const product = products.find(p => p.id === productId);
    if (product) {
        cartItems.push(product);
        displayCartItems();
    }
}

// Display cart items
function displayCartItems() {
    const cartList = document.getElementById("cart-items");
    const totalElement = document.getElementById("total");

    cartList.innerHTML = "";
    let total = 0;

    cartItems.forEach(item => {
        const li = document.createElement("li");
        li.textContent = `${item.name} - $${item.price}`;
        cartList.appendChild(li);
        total += item.price;
    });

    totalElement.textContent = total;
}

// Checkout
function checkout() {
    if (cartItems.length === 0) {
        alert("Your cart is empty!");
    } else {
        alert("Checkout successful!");
    }
}

// Initial load
displayProducts();
```

