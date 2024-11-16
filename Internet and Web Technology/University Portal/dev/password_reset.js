document.getElementById("passwordResetForm").addEventListener("submit", function(event) {
    event.preventDefault();
    
    var email = document.getElementById("userEmail").value;
    var csrfToken = document.getElementById("csrfToken").value;

    var xhr = new XMLHttpRequest();
    xhr.open("POST", "password_reset.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.onreadystatechange = function() {
        if (this.readyState === XMLHttpRequest.DONE && this.status === 200) {
            document.getElementById("message").innerText = this.responseText;
        }
    }
    xhr.send("email=" + email + "&csrf_token=" + csrfToken);
});

// Fetch CSRF token from the server
fetch("get_csrf_token.php")
    .then(response => response.text())
    .then(token => {
        document.getElementById("csrfToken").value = token;
    });
