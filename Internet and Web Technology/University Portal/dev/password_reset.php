<?php
require_once 'db_connect.php';
require_once 'session.php';
include 'navigation.php';

// Check CSRF token
if ($_POST['csrf_token'] !== $_SESSION['csrf_token']) {
    // Invalid CSRF token
    echo "Invalid CSRF token.";
    exit;
}

// Prevents SQL Injection and XSS attacks
$email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);

// Check if the email is registered
$stmt = $pdo->prepare("SELECT user_id FROM user WHERE user_email = :email");
$stmt->execute(['email' => $email]);

if($stmt->rowCount() > 0) {
    // Get user_id
    $user = $stmt->fetch();
    $user_id = $user['user_id'];

    // Generate reset token
    $reset_token = bin2hex(random_bytes(32));
    
    // Store the reset request in the database
    $stmt = $pdo->prepare("INSERT INTO password_reset_request (user_id, reset_token) VALUES (:user_id, :reset_token)");
    $stmt->execute(['user_id' => $user_id, 'reset_token' => $reset_token]);
    
    // Hash the token before storing it in the database to prevent it from being stolen if the database is compromised
    // Then send an email to the user with the reset token here
    // The user will click on the link with the token to reset their password

    echo "A password reset link has been sent to your email.";
} else {
    echo "Email not registered.";
}
?>
