<?php
require_once 'config.php';
require_once 'db_connect.php';
require_once 'session.php';

// Only admins are allowed to manage users
requireUserType('admin');

$action = $_POST['action'] ?? '';

switch ($action) {
    case 'fetch_users':
        fetchUsers($pdo);
        break;

    // Other actions (like create, update, delete users) go here...
}

function fetchUsers($pdo) {
    $search = $_POST['search'] ?? '';

    $query = "SELECT * FROM user WHERE user_first_name LIKE ? OR user_last_name LIKE ?";
    $stmt = $pdo->prepare($query);
    $stmt->execute(['%' . $search . '%', '%' . $search . '%']);
    $users = $stmt->fetchAll();

    header('Content-Type: application/json');
    echo json_encode(['users' => $users]);
}
?>
