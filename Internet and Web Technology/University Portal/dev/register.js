document.getElementById('registerForm').addEventListener('submit', function(event) {
    var password = document.getElementById('user_password').value.trim();
    var confirmPassword = document.getElementById('user_password_confirm').value.trim();
    var email = document.getElementById('user_email').value.trim();
    var user_first_name = document.getElementById('user_first_name').value.trim();
    var user_last_name = document.getElementById('user_last_name').value.trim();
    var user_address = document.getElementById('user_address').value.trim();
    var user_type_id = document.getElementById('user_type_id').value.trim();

    if (password !== confirmPassword) {
        alert('Passwords do not match!');
        event.preventDefault();
    }
    if (!email || !password || !confirmPassword || !user_first_name || !user_last_name || !user_address || !user_type_id) {
        alert('All fields must be filled out!');
        event.preventDefault();
    }
});
