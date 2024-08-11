// Wait for the DOM to finish loading
document.addEventListener("DOMContentLoaded", function() {

    // When the form with the ID "loginForm" is submitted
    document.getElementById("loginForm").addEventListener("submit", function(event){

        // Prevent the form from being submitted in the default way
        event.preventDefault();

        // Make an AJAX request
        fetch('academic_management.php', {
            method: 'POST',
            body: new FormData(this)
        })
        .then(response => response.json())
        .then(data => {
            // If the server script responded with an error, display the error message
            if(data.error) {
                alert(data.message);
            } else {
                // If the request was successful, reload the page
                location.reload();
            }
        })
        .catch((error) => {
            // Log the error to the console
            console.error('Error:', error);
            // Display a general error message
            alert("Something went wrong! Please try again.");
        });
    });
});
