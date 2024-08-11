document.addEventListener('DOMContentLoaded', function() {
    fetchGrades();
});

function fetchGrades() {
    fetch('grades.php', {
        method: 'GET',
        headers: { 'Content-Type': 'application/json' }
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        return response.json();
    })
    .then(data => {
        let grades = data;
        let html = '<table><tr><th>Course</th><th>Section</th><th>Grade</th></tr>';
        grades.forEach(function(grade) {
            html += `<tr><td>${grade.course}</td><td>${grade.section}</td><td>${grade.grade}</td></tr>`;
        });
        html += '</table>';
        document.getElementById('gradesTable').innerHTML = html;
    })
    .catch(error => console.error('Error:', error));
}
