<?php
// Include necessary files
require_once 'db_connect.php';
require_once 'session.php';
include 'navigation.php';

// Only allow access to students
requireUserType('student');

// Check if a POST request has been made
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Prepare and execute SQL query to insert a new message
    $stmt = $pdo->prepare('INSERT INTO messages (sender_user_id, message_content) VALUES (?, ?)');
    $stmt->execute([getUserId(), $_POST['message-content']]);
} else {
    // Prepare and execute SQL query to fetch all messages
    $stmt = $pdo->prepare('SELECT user_first_name, message_content, message_time FROM messages JOIN user ON messages.sender_user_id = user.user_id ORDER BY message_time DESC');
    $stmt->execute();
    // Fetch and display each row
    while ($row = $stmt->fetch()) {
        echo '<p><strong>' . htmlspecialchars($row['user_first_name']) . ':</strong> ' . htmlspecialchars($row['message_content']) . '</p>';
    }
}
?>
