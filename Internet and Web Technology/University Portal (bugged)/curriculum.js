$(document).ready(function() {
    // Call the fetchCurriculum function when the page loads
    fetchCurriculum();
});

function fetchCurriculum() {
    $.ajax({
        url: "curriculum.php",
        method: "GET",
        dataType: "html",
        success: function(data) {
            // On success, append the returned HTML to the #curriculum div
            $("#curriculum").html(data);
        },
        error: function() {
            // On error, show an error message
            $("#curriculum").html("<p>There was an error loading the curriculum. Please try again later.</p>");
        }
    });
}
