document.addEventListener('DOMContentLoaded', function () {
    fetchUsers();
    document.getElementById('search').addEventListener('keyup', fetchUsers);
});

function fetchUsers() {
    let search = document.getElementById('search').value;

    fetch('user_management.php', {
        method: 'POST',
        body: JSON.stringify({
            action: 'fetch_users',
            search: search
        }),
        headers: {
            'Content-Type': 'application/json'
        }
    })
        .then(response => response.json())
        .then(data => {
            let usersDiv = document.getElementById('users');
            usersDiv.innerHTML = '';

            data.users.forEach(user => {
                let userDiv = document.createElement('div');
                userDiv.classList.add('user');
                userDiv.innerText = user.user_first_name + ' ' + user.user_last_name;
                usersDiv.appendChild(userDiv);
            });
        });
}
