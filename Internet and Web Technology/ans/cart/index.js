document.getElementById("remember-me").addEventListener('change', function() {
    if (this.checked) {
        document.cookie = "user=uniqueUserID; expires=Fri, 31 Dec 9999 23:59:59 GMT";
    } else {
        document.cookie = "user=; expires=Thu, 01 Jan 1970 00:00:00 UTC;";
    }
});
