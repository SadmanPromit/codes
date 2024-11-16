<?php
// Including the database connection file and session handling
require_once 'db_connect.php';
require_once 'session.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // Validate input
    $required_fields = ['user_email', 'user_password', 'user_password_confirm', 'user_first_name', 'user_last_name', 'user_address', 'user_type_id'];
    foreach($required_fields as $field) {
        if (empty($_POST[$field])) {
            header("Location: register.html?error=Please fill out all fields");
            exit;
        }
    }

    // Capture input
    $user_type_id = trim($_POST["user_type_id"]);
    $user_email = trim($_POST["user_email"]);
    $user_password = trim($_POST["user_password"]);
    $user_first_name = trim($_POST["user_first_name"]);
    $user_middle_name = trim($_POST["user_middle_name"]);
    $user_last_name = trim($_POST["user_last_name"]);
    $user_address = trim($_POST["user_address"]);
    $user_password_confirm = trim($_POST["user_password_confirm"]);

    // Validate email
    if (!filter_var($user_email, FILTER_VALIDATE_EMAIL)) {
        header("Location: register.html?error=Invalid email format");
        exit;
    }
    
    // Validate password strength
    $uppercase = preg_match('@[A-Z]@', $user_password);
    $lowercase = preg_match('@[a-z]@', $user_password);
    $number    = preg_match('@[0-9]@', $user_password);
    if(!$uppercase || !$lowercase || !$number || strlen($user_password) < 8) {
        header("Location: register.html?error=Password should be at least 8 characters in length and should include at least one upper case letter, one number.");
        exit;
    }

    if($user_password !== $user_password_confirm){
        header("Location: register.html?error=Passwords do not match");
        exit;
    }

    try {
        // SQL INSERT statement
        $sql = "INSERT INTO user (user_type_id, user_email, user_password, user_first_name, user_middle_name, user_last_name, user_address)
                VALUES (?, ?, ?, ?, ?, ?, ?)";

        // Prepare the statement
        $stmt = $pdo->prepare($sql);

        // Execute the statement with the data
        $hashed_password = password_hash($user_password, PASSWORD_BCRYPT, ['cost' => 12]);
        $stmt->execute([$user_type_id, $user_email, $hashed_password, $user_first_name, $user_middle_name, $user_last_name, $user_address]);

        // Redirect the user to the login page with a success message
        header("Location: login.html?message=Registration successful, please log in");
        exit;

    } catch (PDOException $e) {
        // If an error occurs, stop the script and display an error message
        if (defined('DEBUG_MODE') && DEBUG_MODE) {
            die("ERROR: Could not execute SQL statement. " . $e->getMessage());
        } else {
            // Email the error details to the admin or log it to a file for investigation, don't reveal info to user
            error_log($e->getMessage(), 1, ADMIN_EMAIL);
            header("Location: register.html?error=An error occurred during registration, please try again");
            exit;
        }
    }
}
?>
