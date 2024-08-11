function initMap() {
    var universityLocation = {lat: 23.8151, lng: 90.4255};
    var map = new google.maps.Map(document.getElementById('map'), {
        zoom: 15,
        center: universityLocation
    });
    var marker = new google.maps.Marker({
        position: universityLocation,
        map: map
    });
}
