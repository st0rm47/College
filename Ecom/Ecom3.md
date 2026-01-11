# Write a program to display a cart list and empty cart features in an ecommerce store. Assuming That the list of products is already in a data structure or table for cart. Also display the items in the cart list.


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

    <h2>🛒 Shopping Cart</h2>

    <div class="cart-card">
        <h2>Your Cart Items</h2>

        <ul id="cart-items"></ul>

        <p class="total">Total: $<span id="total">0</span></p>

        <button onclick="emptyCart()" class="btn empty-btn">
            Empty Cart
        </button>
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

/* Cart Card */
.cart-card {
    max-width: 500px;
    margin: auto;
    background: #ffffff;
    padding: 20px;
    border-radius: 8px;
    box-shadow: 0 3px 10px rgba(0,0,0,0.1);
}

ul {
    list-style: none;
    padding: 0;
}

li {
    padding: 10px;
    border-bottom: 1px solid #ddd;
    display: flex;
    justify-content: space-between;
}

.price {
    color: #28a745;
    font-weight: bold;
}

.total {
    margin-top: 15px;
    font-size: 18px;
    font-weight: bold;
}

.btn {
    width: 100%;
    padding: 12px;
    margin-top: 15px;
    border: none;
    border-radius: 5px;
    color: white;
    cursor: pointer;
    font-size: 16px;
}

.empty-btn {
    background-color: #dc3545;
}

.btn:hover {
    opacity: 0.9;
}

.empty-message {
    text-align: center;
    color: #777;
    padding: 20px;
}
```

### 3. script.js
```javascript
// Sample cart data (already available data structure)
const cartItems = [
    { id: 1, name: "Laptop", price: 999.99, description: "A high-performance laptop." },
    { id: 2, name: "Smartphone", price: 499.99, description: "A latest model smartphone." },
    { id: 3, name: "Headphones", price: 199.99, description: "Noise-cancelling headphones." }
];

// Display cart items
function displayCartItems() {
    const cartList = document.getElementById("cart-items");
    const totalElement = document.getElementById("total");

    cartList.innerHTML = "";
    let total = 0;

    if (cartItems.length === 0) {
        cartList.innerHTML = "<p class='empty-message'>Your cart is empty.</p>";
        totalElement.textContent = 0;
        return;
    }

    cartItems.forEach(item => {
        const li = document.createElement("li");
        li.innerHTML = `
            <span>${item.name}</span>
            <span class="price">$${item.price.toFixed(2)}</span>
        `;
        cartList.appendChild(li);
        total += item.price;
    });

    totalElement.textContent = total;
}

// Empty cart
function emptyCart() {
    cartItems.length = 0;   // Clear cart
    displayCartItems();     // Refresh UI
}

// Initial load
displayCartItems();
```
