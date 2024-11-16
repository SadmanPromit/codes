<?php
require_once 'session.php';
include 'navigation.php';

// Check if the user is logged in, if not then redirect to login page
if (!isLoggedIn()) {
    header("Location: login.php");
    exit;
}

// Prepare a select statement
$sql = "SELECT user_first_name FROM user WHERE user_id = :user_id";

if ($stmt = $pdo->prepare($sql)) {
    // Bind variables to the prepared statement as parameters
    $stmt->bindParam(":user_id", $param_user_id, PDO::PARAM_INT);

    // Set parameters
    $param_user_id = getUserId();

    // Attempt to execute the prepared statement
    if ($stmt->execute()) {
        if ($stmt->rowCount() == 1) {
            if ($row = $stmt->fetch()) {
                echo "Welcome " . htmlspecialchars($row["user_first_name"]) . "! You are logged in as " . getUserType() . ".";
            }
        } else {
            echo "Oops! Something went wrong. Please try again later.";
        }
    }
    unset($stmt);
}

// Close connection
unset($pdo);
?>
