### 1. form.html
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
        <br>
        Description<textarea id="productDescription" placeholder="Product Description"></textarea>
        <br><br>
        <button onclick="addProduct()" class="btn add-btn">Add Product</button>
    </div>


    <!-- Product List -->
    <div>
        <h2>Available Products</h2>
        <div id="products" class="product-grid">
            <!-- Products appear here -->
        </div>
    </div>

    <script src="products.js"></script>
</body>
</html>
```

### 2. products.js
```javascript
// Initialize or load from localStorage
let products = JSON.parse(localStorage.getItem('products')) || [];
let cartItems = JSON.parse(localStorage.getItem('cartItems')) || [];
let wishListItems = JSON.parse(localStorage.getItem('wishListItems')) || [];
let orderHistory = JSON.parse(localStorage.getItem('orderHistory')) || [];

// ---------- Product Management ----------
function addProduct() {
    const name = document.getElementById("productName")?.value;
    const price = document.getElementById("productPrice")?.value;
    const category = document.getElementById("productCategory")?.value;

    if (!name || !price) { alert("Please fill product name and price!"); return; }

    const id = products.length ? products[products.length-1].id + 1 : 1;

    products.push({ id, name, price: parseFloat(price), category, image });
    localStorage.setItem('products', JSON.stringify(products));

    displayProducts();
    if(document.getElementById("productName")) {
        document.getElementById("productName").value = "";
        document.getElementById("productPrice").value = "";
        document.getElementById("productCategory").value = "";
    }
}

// ---------- Display Products ----------
function displayProducts() {
    const container = document.getElementById("products");
    if(!container) return;

    container.innerHTML = "";

    products.forEach(p => {
        const div = document.createElement("div");
        div.className = "product-card";

        div.innerHTML = `
            <h3>${p.name}</h3>
            <p>$${p.price}</p>
            <button onclick="addToCart(${p.id})">🛒 Add to Cart</button>
            <button class="wishlist-btn" onclick="addToWishList(${p.id})">Wish List</button>
        `;

        container.appendChild(div);
    });
}

// ---------- Cart ----------
function addToCart(productId) {
    const product = products.find(p => p.id === productId);
    const item = cartItems.find(c => c.id === productId);
    if(item) { item.quantity++; } 
    else { cartItems.push({...product, quantity:1}); }

    localStorage.setItem('cartItems', JSON.stringify(cartItems));
    displayCartItems();
}

function displayCartItems() {
    const container = document.getElementById("cart-items");
    if(!container) return;
    container.innerHTML = "";

    let total = 0;
    cartItems.forEach(item => {
        const li = document.createElement("li");
        li.textContent = `${item.name} × ${item.quantity} - $${item.price*item.quantity}`;
        container.appendChild(li);
        total += item.price * item.quantity;
    });

    const totalElem = document.getElementById("cart-total");
    if(totalElem) totalElem.textContent = total.toFixed(2);
}

function emptyCart() {
    cartItems = [];
    localStorage.setItem('cartItems', JSON.stringify(cartItems));
    displayCartItems();
}

function checkout() {
    if(!cartItems.length) { alert("Cart is empty"); return; }

    orderHistory.push({ items: cartItems, total: cartItems.reduce((s,i)=>s+i.price*i.quantity,0) });
    localStorage.setItem('orderHistory', JSON.stringify(orderHistory));
    emptyCart();
    alert("Checkout successful!");
    displayOrders();
}

// ---------- Wish List ----------
function addToWishList(productId) {
    if(wishListItems.find(p => p.id === productId)) { alert("Already in wish list"); return; }
    const product = products.find(p => p.id === productId);
    wishListItems.push(product);
    localStorage.setItem('wishListItems', JSON.stringify(wishListItems));
    displayWishList();
}

function displayWishList() {
    const container = document.getElementById("wish-list-items");
    if(!container) return;
    container.innerHTML = "";
    wishListItems.forEach(item => {
        const li = document.createElement("li");
        li.textContent = `${item.name} - $${item.price}`;
        container.appendChild(li);
    });
}

// ---------- Orders ----------
function displayOrders() {
    const container = document.getElementById("orders");
    if(!container) return;

    container.innerHTML = "";
    orderHistory.forEach((order,i)=>{
        const li = document.createElement("li");
        li.className = "order-item";
        li.innerHTML = `<strong>Order ${i+1}</strong>: ${order.items.map(it=>`${it.name} × ${it.quantity}`).join(", ")} - Total: $${order.total}`;
        container.appendChild(li);
    });
}

// Initial load
displayProducts();
displayWishList();
displayCartItems();
displayOrders();
```


### 3. products.html
```html
<!DOCTYPE html>
<html>
<head>
    <title>Products - E-Commerce</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Products</h1>

    <div id="products" class="product-grid"></div>

    <div class="card">
        <h2>💖 Wish List</h2>
        <ul id="wish-list-items"></ul>
    </div>

    <div class="card">
        <h2>🛒 Shopping Cart</h2>
        <ul id="cart-items"></ul>
        <p>Total: $<span id="cart-total">0</span></p>
        <button onclick="emptyCart()" class="btn checkout-btn">Empty Cart</button>
        <a href="cart.html" class="btn checkout-btn">Go to Cart</a>
    </div>

    <script src="products.js"></script>
</body>
</html>
```

### 4. cart.html
```html
<!DOCTYPE html>
<html>
<head>
    <title>Shopping Cart</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Shopping Cart</h1>

    <div class="card">
        <ul id="cart-items"></ul>
        <p>Total: $<span id="cart-total">0</span></p>
        <button onclick="checkout()" class="btn checkout-btn">Checkout</button>
        <button onclick="emptyCart()" class="btn checkout-btn">Empty Cart</button>
        <a href="products.html" class="btn">Back to Products</a>
    </div>

    <div class="card">
        <h2>Order History</h2>
        <ul id="orders"></ul>
        <a href="orders.html" class="btn">View All Orders</a>
    </div>

    <script src="products.js"></script>
</body>
</html>
```


### 5. orders.html
```html
<!DOCTYPE html>
<html>
<head>
    <title>Order History</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Order History</h1>

    <div class="card">
        <ul id="orders"></ul>
        <a href="products.html" class="btn">Back to Products</a>
    </div>

    <script src="products.js"></script>
</body>
</html>
```

### 6. styles.css
```css

/* Global styles */
body {
    font-family: Arial, sans-serif;
    background-color: #f0f2f5;
    margin: 0;
    padding: 20px;
}

h1 {
    text-align: center;
    color: #333;
    margin-bottom: 25px;
}

h2 {
    color: #333;
    margin-bottom: 15px;
}

/* Card container for sections */
.card {
    background-color: #fff;
    padding: 20px;
    margin-bottom: 25px;
    border-radius: 10px;
    box-shadow: 0 3px 10px rgba(0, 0, 0, 0.08);
}

/* Input fields */
input[type="text"], input[type="number"] {
    width: 100%;
    padding: 8px;
    margin: 5px 0 15px 0;
    border-radius: 5px;
    border: 1px solid #ccc;
    box-sizing: border-box;
}

/* Buttons */
.btn {
    padding: 10px 15px;
    background-color: #007BFF;
    color: #fff;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    margin-right: 5px;
    text-decoration: none;
    font-size: 14px;
}

.btn:hover {
    background-color: #0056b3;
}

/* Checkout buttons slightly different */
.checkout-btn {
    background-color: #28a745;
}

.checkout-btn:hover {
    background-color: #218838;
}

/* Product grid */
.product-grid {
    display: grid;
    grid-template-columns: repeat(auto-fill, minmax(200px, 1fr));
    gap: 20px;
}

/* Product card */
.product-card {
    background-color: #fff;
    padding: 15px;
    border-radius: 8px;
    box-shadow: 0 2px 8px rgba(0, 0, 0, 0.05);
    text-align: center;
    transition: transform 0.2s, box-shadow 0.2s;
}

.product-card:hover {
    transform: translateY(-5px);
    box-shadow: 0 6px 15px rgba(0,0,0,0.1);
}

.product-card h3 {
    margin-bottom: 5px;
    color: #333;
}

.product-card .price {
    color: #28a745;
    font-weight: bold;
    font-size: 16px;
    margin-bottom: 10px;
}

.product-card img {
    width: 100%;
    height: 150px;
    object-fit: cover;
    border-radius: 5px;
}

/* Product buttons inside cards */
.product-card button {
    margin-top: 5px;
}

.product-card button.wishlist-btn {
    background-color: #ff4081;
}

.product-card button.wishlist-btn:hover {
    background-color: #e73370;
}

/* Wish list items */
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

/* Cart items */
#cart-items li {
    background-color: #f9f9f9;
    border-left: 5px solid #28a745;
    padding: 10px;
    margin: 5px 0;
    border-radius: 5px;
    display: flex;
    justify-content: space-between;
}

/* Orders */
.order-item {
    background-color: #f5f5f5;
    border-left: 5px solid #007BFF;
    padding: 10px;
    margin: 5px 0;
    border-radius: 5px;
}

/* Responsive adjustments */
@media (max-width: 600px) {
    .product-grid {
        grid-template-columns: 1fr;
    }
}
```
