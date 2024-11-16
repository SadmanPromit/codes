document.addEventListener("DOMContentLoaded", function() {
  fetch('course.php')
  .then(response => response.json())
  .then(data => {
    let courseInfo = document.getElementById('courseInfo');
    courseInfo.innerHTML = '';
    data.forEach(course => {
      let p = document.createElement('p');
      p.textContent = `${course.course_title} - ${course.department_name}`;
      courseInfo.appendChild(p);
    });
  })
  .catch(error => console.error('Error:', error));
});
