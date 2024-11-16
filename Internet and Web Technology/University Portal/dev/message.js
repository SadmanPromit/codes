document.getElementById('message-form').addEventListener('submit', function(event) {
    event.preventDefault();
    var messageContent = document.getElementById('message-content').value;
    fetch('message.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
        },
        body: 'message-content=' + encodeURIComponent(messageContent),
    }).then(function(response) {
        if (response.ok) {
            document.getElementById('message-content').value = '';
            loadMessages();
        } else {
            console.error('Error sending message: ' + response.statusText);
        }
    });
});

function loadMessages() {
    fetch('message.php').then(function(response) {
        if (response.ok) {
            return response.text();
        } else {
            throw new Error('Error loading messages: ' + response.statusText);
        }
    }).then(function(data) {
        document.getElementById('message-container').innerHTML = data;
    }).catch(function(error) {
        console.error(error);
    });
}

loadMessages();
setInterval(loadMessages, 5000);
