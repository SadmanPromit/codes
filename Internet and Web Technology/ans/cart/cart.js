// Load the cart from the cookies
if(document.cookie.includes("cart")) {
    cart = {};
    const cartStr = decodeURIComponent(document.cookie.split("; ").find(row => row.startsWith("cart=")).split('=')[1]);
    cartStr.split(',').forEach(item => {
        const [productId, quantity] = item.split(':');
        cart[productId] = Number(quantity);
    });
}

const cartItemsDiv = document.getElementById("cart-items");

for (let productId in cart) {
    const item = products.find(product => product.id == productId); // Find the product using its id

    const cartItemDiv = document.createElement("div");
    cartItemDiv.className = "cart-item";

    const itemName = document.createElement("div");
    itemName.textContent = item.name;
    cartItemDiv.appendChild(itemName);

    const itemQuantityInput = document.createElement("input");
    itemQuantityInput.type = "number";
    itemQuantityInput.min = 1;
    itemQuantityInput.value = cart[productId];
    itemQuantityInput.addEventListener("change", function() {
        cart[productId] = Number(itemQuantityInput.value);
        const cartStr = Object.entries(cart).map(([productId, quantity]) => `${productId}:${quantity}`).join(',');
        document.cookie = `cart=${encodeURIComponent(cartStr)}; expires=Fri, 31 Dec 9999 23:59:59 GMT`;
        calculateTotal();
    });
    cartItemDiv.appendChild(itemQuantityInput);

    const removeItemBtn = document.createElement("button");
    removeItemBtn.textContent = "Remove";
    removeItemBtn.addEventListener("click", function() {
        delete cart[productId];
        const cartStr = Object.entries(cart).map(([productId, quantity]) => `${productId}:${quantity}`).join(',');
        document.cookie = `cart=${encodeURIComponent(cartStr)}; expires=Fri, 31 Dec 9999 23:59:59 GMT`;
        cartItemDiv.remove();
        calculateTotal();
    });
    cartItemDiv.appendChild(removeItemBtn);

    cartItemsDiv.appendChild(cartItemDiv);
}

function calculateTotal() {
    let total = 0;
    for (let productId in cart) {
        const item = products.find(product => product.id == productId); // Find the product using its id
        total += item.price * cart[productId];
    }
    document.getElementById("total").textContent = "Total: $" + total;
}

calculateTotal();
