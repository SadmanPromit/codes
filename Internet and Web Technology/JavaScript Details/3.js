function validateForm() {
    var x = document.forms["forms"]["username"].value;
    var y = document.forms["forms"]["password"].value;
    if (x == "") {
        alert("Username must be filled out");
        return false;
    }
    if (y == "") {
        alert("Password must be filled out");
        return false;
    }
}