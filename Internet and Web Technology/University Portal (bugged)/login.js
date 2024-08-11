document.getElementById('loginForm').addEventListener('submit', function(event) {
    event.preventDefault();

    let formData = new FormData(event.target);

    fetch('login.php', {
        method: 'POST',
        body: formData,
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            location.href = 'dashboard.php';
        } else {
            alert('Invalid login.');
        }
    });
});
