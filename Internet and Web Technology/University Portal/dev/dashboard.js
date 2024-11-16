window.addEventListener('DOMContentLoaded', (event) => {
    loadDashboard();
});

function loadDashboard() {
    fetch('dashboard.php')
    .then(response => {
        if (!response.ok) throw new Error(response.status);
        return response.text()
    })
    .then(data => {
        document.getElementById('dashboard').innerHTML = data;
    })
    .catch(error => {
        console.log('Error:', error);
    });
}
