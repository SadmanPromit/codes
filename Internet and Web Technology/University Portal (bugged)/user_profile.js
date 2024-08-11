$(document).ready(function(){
    // Load user profile when page is ready
    loadUserProfile();

    function loadUserProfile() {
        $.ajax({
            url: 'user_profile.php',
            type: 'GET',
            success: function(response) {
                $('#user-profile').html(response);
            },
            error: function(error) {
                console.error('Error:', error);
            }
        });
    }
});
