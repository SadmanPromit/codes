document.addEventListener('DOMContentLoaded', function() {
    let container = document.getElementById('departmentContainer');
    fetch('department.php')
    .then(response => {
        if(!response.ok) {
            throw new Error("HTTP error " + response.status);
        }
        return response.json();
    })
    .then(data => {
        // Sample data processing, you would need to tailor this
        data.forEach(dept => {
            let deptDiv = document.createElement('div');
            deptDiv.textContent = `${dept.department_id}: ${dept.department_name}`;
            container.appendChild(deptDiv);
        });
    })
    .catch(error => {
        console.error('Error:', error);
    });
});
