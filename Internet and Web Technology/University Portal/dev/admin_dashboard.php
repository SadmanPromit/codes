<?php
// Include database connection and session handling
require_once 'db_connect.php';
require_once 'session.php';
include 'navigation.php';

// Ensure the user is an admin
requireUserType('admin');

// Retrieve some data to display (for example, the number of users)
$stmt = $pdo->prepare('SELECT COUNT(*) AS user_count FROM user');
$stmt->execute();
$data = $stmt->fetch();
$user_count = $data['user_count'];

echo "<h1>Admin Dashboard</h1>";
echo "<p>There are currently $user_count users in the system.</p>";
