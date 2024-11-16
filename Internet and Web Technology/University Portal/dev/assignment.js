$(document).ready(function() {
    $.ajax({
        url: 'assignment.php',
        type: 'POST',
        data: { action: 'getWelcomeMessage' },
        success: function(response) {
            $('#welcomeMessage').html(response);
        },
        error: function() {
            $('#welcomeMessage').html('An error occurred while loading the welcome message.');
        }
    });
});
