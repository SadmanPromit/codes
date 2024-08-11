$(document).ready(function() {
    function loadDashboard() {
        $.ajax({
            url: "admin_dashboard.php",
            type: "POST",
            success: function(data) {
                $("#admin_dashboard").html(data);
            }
        });
    }

    loadDashboard();

    // Call loadDashboard every minute to refresh data
    setInterval(loadDashboard, 60000);
});
