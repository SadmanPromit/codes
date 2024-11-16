$(document).ready(function() {
    $("#evaluation-form").submit(function(event) {
        event.preventDefault();

        $.ajax({
            url: 'evaluation.php',
            type: 'post',
            data: $(this).serialize(),
            success: function(data) {
                alert(data);
            },
            error: function(xhr, status, error) {
                console.error(xhr);
            }
        });
    });
});
