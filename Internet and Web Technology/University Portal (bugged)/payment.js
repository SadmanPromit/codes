document.getElementById('payment-form').addEventListener('submit', function(e) {
    e.preventDefault();

    var amount = document.getElementById('amount').value;

    // You would typically send the payment request to your server here
    // Then the server would communicate with the payment gateway
    // For simplicity, let's just log the amount to the console for now

    console.log('Paying amount:', amount);
});
