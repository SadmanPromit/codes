<?php
require_once 'session.php';
require_once 'db_connect.php';
require_once 'utils.php';
include 'navigation.php';

// Only logged in users can access
if (!isLoggedIn()) {
    header('Location: login.php');
    exit;
}

$userId = getUserId();
$amount = isset($_POST['amount']) ? $_POST['amount'] : null;

if (!$amount) {
    http_response_code(400);
    exit('Payment amount is required');
}

// In production, you would typically contact the payment gateway here
// For now, let's just assume the payment was successful and store it in the database

$sql = 'INSERT INTO payment (user_id, payment_date, amount) VALUES (?, NOW(), ?)';
$stmt = $pdo->prepare($sql);

if (!$stmt->execute([$userId, $amount])) {
    http_response_code(500);
    exit('Error recording payment');
}

echo 'Payment successful!';
