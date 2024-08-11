document.addEventListener("DOMContentLoaded", function() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'attendance.php', true);
    xhr.onload = function() {
        if (this.status == 200) {
            var data = JSON.parse(this.responseText);
            // Rest of the code...
        } else {
            document.getElementById('attendanceTable').innerHTML = 'Unable to load attendance data';
        }
    };
    xhr.onerror = function() {
        document.getElementById('attendanceTable').innerHTML = 'There was an error making the request';
    };
    xhr.send();
});
