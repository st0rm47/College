# Write a program to implement add to cart and checkout features of an ecommerce store. Assuming that the list of products is already in a data structure or table for products.Also display the list of orders after checkout operation


### 1. Index.html
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
    <div class="card">
        <h2>Shopping Cart</h2>
        <ul id="cart-items"></ul>
        <p class="total">Total: $<span id="cart-total">0</span></p>
        <button onclick="checkout()" class="btn checkout-btn">Checkout</button>
    </div>

    <!-- Order History -->
    <div class="card">
        <h2>Order History</h2>
        <ul id="orders"></ul>
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
    margin-bottom: 5px;
}

.price {
    color: #28a745;
    font-weight: bold;
    font-size: 18px;
}

.product-card button {
    margin-top: 10px;
    padding: 8px 12px;
    background-color: #007bff;
    border: none;
    border-radius: 5px;
    color: white;
    cursor: pointer;
}

.product-card button:hover {
    background-color: #0056b3;
}

/* Cards */
.card {
    background: white;
    padding: 20px;
    margin-top: 20px;
    border-radius: 8px;
    box-shadow: 0 3px 10px rgba(0,0,0,0.1);
}

/* Cart */
ul {
    list-style: none;
    padding: 0;
}

li {
    padding: 8px 0;
    border-bottom: 1px solid #ddd;
}

.total {
    margin-top: 10px;
    font-weight: bold;
    font-size: 18px;
}

/* Buttons */
.btn {
    padding: 10px 15px;
    border: none;
    border-radius: 5px;
    color: white;
    cursor: pointer;
}

.checkout-btn {
    background-color: #28a745;
}

.btn:hover {
    opacity: 0.9;
}

/* Order Item */
.order-item {
    background-color: #f5f5f5;
    padding: 10px;
    border-radius: 5px;
    margin-top: 10px;
}
```

### 3. script.js
```javascript
// Product data
const products = [
    { id: 1, name: "Laptop", price: 999.99, description: "A high-performance laptop." },
    { id: 2, name: "Smartphone", price: 499.99, description: "A latest model smartphone." },
    { id: 3, name: "Headphones", price: 199.99, description: "Noise-cancelling headphones." }
];

const cartItems = [];
const orderHistory = [];

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
            <button onclick="addToCart(${product.id})">Add to Cart</button>
        `;

        container.appendChild(div);
    });
}

// Add to cart
function addToCart(productId) {
    const product = products.find(p => p.id === productId);

    if (!product) return;

    // Check if product already in cart
    const cartItem = cartItems.find(item => item.id === productId);

    if (cartItem) {
        cartItem.quantity += 1;
    } else {
        cartItems.push({
            ...product,
            quantity: 1
        });
    }

    displayCartItems();
}


// Display cart
function displayCartItems() {
    const cartList = document.getElementById("cart-items");
    const totalElement = document.getElementById("cart-total");

    cartList.innerHTML = "";
    let total = 0;

    cartItems.forEach(item => {
        const li = document.createElement("li");
        li.innerHTML = `
            ${item.name} × ${item.quantity} 
            <span>$${item.price * item.quantity}</span>
        `;
        cartList.appendChild(li);

        total += item.price * item.quantity;
    });

    totalElement.textContent = total;
}


// Checkout
function checkout() {
    if (cartItems.length === 0) {
        alert("Your cart is empty.");
        return;
    }

    const total = cartItems.reduce(
        (sum, item) => sum + item.price * item.quantity,
        0
    );

    orderHistory.push({
        items: JSON.parse(JSON.stringify(cartItems)),
        total
    });

    cartItems.length = 0;
    displayCartItems();
    displayOrderHistory();
}


// Display orders
function displayOrderHistory() {
    const ordersList = document.getElementById("orders");
    ordersList.innerHTML = "";

    orderHistory.forEach((order, index) => {
        const li = document.createElement("li");
        li.className = "order-item";

        const itemsText = order.items
            .map(item => `${item.name} × ${item.quantity}`)
            .join(", ");

        li.innerHTML = `
            <strong>Order ${index + 1}</strong><br>
            Items: ${itemsText}<br>
            Total: $${order.total}
        `;

        ordersList.appendChild(li);
    });
}


// Initial load
displayProducts();
displayOrderHistory();
```