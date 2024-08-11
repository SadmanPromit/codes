document.getElementById("roleAssignmentForm").addEventListener("submit", function(e){
    e.preventDefault();
    
    let userId = document.getElementById("userSelect").value;
    let roleId = document.getElementById("roleSelect").value;
    let departmentId = document.getElementById("departmentSelect").value;

    let request = new XMLHttpRequest();
    request.open('POST', 'role_assignment.php', true);
    request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded; charset=UTF-8');
    request.send('user_id=' + userId + '&role_id=' + roleId + '&department_id=' + departmentId);
});
