<?php
require_once 'db_connect.php';
require_once 'session.php';
include 'navigation.php';

$response = ['error' => false, 'message' => ''];

if($_SERVER["REQUEST_METHOD"] == "POST") {
    try {
        $email = filter_input(INPUT_POST, 'email', FILTER_SANITIZE_EMAIL);
        $password = filter_input(INPUT_POST, 'password', FILTER_SANITIZE_STRING);

        // Begin authentication logic

        // Fetch the user record based on the provided email
        $stmt = $pdo->prepare('SELECT * FROM users WHERE email = :email');
        $stmt->execute(['email' => $email]);
        $user = $stmt->fetch();

        // Check if a user was found and the password matches
        if($user && password_verify($password, $user['password'])) {
            // Log the user in
            loginUser($user['id'], $user['type']);
            $response['message'] = 'Logged in successfully.';
        } else {
            // Invalid credentials were supplied
            throw new Exception("Invalid email or password.");
        }

        // End authentication logic
    } catch (Exception $e) {
        $response['error'] = true;
        $response['message'] = $e->getMessage();
    }

    echo json_encode($response);
}
?>
