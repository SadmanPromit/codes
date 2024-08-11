// products.js

const products = [
    {id: 1, name: "Product 1", price: 100},
    {id: 2, name: "Product 2", price: 200},
    // Add more products as necessary
];

let cart = {}; // This will hold the cart items. Key is product id, value is quantity

if(document.cookie.includes("cart")) {
    cart = {};
    const cartStr = decodeURIComponent(document.cookie.split("; ").find(row => row.startsWith("cart=")).split('=')[1]);
    cartStr.split(',').forEach(item => {
        const [productId, quantity] = item.split(':');
        cart[productId] = Number(quantity);
    });
}

function loadProducts() {
    const productsDiv = document.getElementById("products-list");

    if (!productsDiv) {
        console.log("No products list found on this page.");
        return;
    }

    products.forEach(product => {
        const productCard = document.createElement("div");
        productCard.className = "product-card";

        const productName = document.createElement("div");
        productName.className = "product-name";
        productName.textContent = product.name;

        const productPrice = document.createElement("div");
        productPrice.className = "product-price";
        productPrice.textContent = "$" + product.price;

        const addToCartBtn = document.createElement("button");
        addToCartBtn.textContent = "Add to Cart";
        addToCartBtn.addEventListener('click', function() {
            // Logic to add the product to the shopping cart
            if(cart[product.id]) {
                cart[product.id]++;
            } else {
                cart[product.id] = 1;
            }
    
            const cartStr = Object.entries(cart).map(([productId, quantity]) => `${productId}:${quantity}`).join(',');
            document.cookie = `cart=${encodeURIComponent(cartStr)}; expires=Fri, 31 Dec 9999 23:59:59 GMT`;
    
            alert(`${product.name} added to cart!`);
        });

        productCard.append(productName, productPrice, addToCartBtn);
        productsDiv.appendChild(productCard);
    });
}

window.addEventListener('DOMContentLoaded', loadProducts);
