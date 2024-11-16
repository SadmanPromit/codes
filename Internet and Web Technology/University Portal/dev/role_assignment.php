<?php
require_once 'session.php';

// Only allow POST requests
if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    header('HTTP/1.1 405 Method Not Allowed');
    exit;
}

// Require the user to be an admin
requireUserType('admin');

// Get the POST data
$userId = $_POST['user_id'];
$roleId = $_POST['role_id'];
$departmentId = $_POST['department_id'];

// Connect to the database
require_once 'db_connect.php';

try {
    // Start the transaction
    $pdo->beginTransaction();

    // Assign the role to the user
    $stmt = $pdo->prepare("INSERT INTO department_chair (department_id, chair_user_id, start_date) VALUES (?, ?, NOW())");
    $stmt->execute([$departmentId, $userId]);

    // Commit the transaction
    $pdo->commit();

    // Return a success response
    header('HTTP/1.1 200 OK');
} catch (PDOException $e) {
    // Rollback the transaction if something failed
    $pdo->rollBack();

    // Log the error message
    error_log($e->getMessage());

    // Return an error response
    header('HTTP/1.1 500 Internal Server Error');
}
?>
