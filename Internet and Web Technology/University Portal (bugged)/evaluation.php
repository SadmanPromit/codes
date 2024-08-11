<?php
require_once 'session.php';
require_once 'db_connect.php';
require_once 'utils.php';
include 'navigation.php';

if (isLoggedIn()) {
    try {
        $query = "INSERT INTO evaluation(user_id, section_id, evaluation_data) VALUES(:user_id, :section_id, :evaluation_data)";
        $stmt = $pdo->prepare($query);

        $stmt->execute([
            ':user_id' => getUserId(),
            ':section_id' => $_POST['section'],
            ':evaluation_data' => $_POST['evaluation_data']
        ]);

        echo "Evaluation submitted successfully.";

    } catch (PDOException $e) {
        if (DEBUG_MODE) {
            die("Error: " . $e->getMessage());
        } else {
            // Email the error details to the admin or log it to a file for investigation, don't reveal info to user
            error_log($e->getMessage(), 1, ADMIN_EMAIL);
            echo "There was a problem submitting the evaluation. Please try again.";
        }
    }
} else {
    header('HTTP/1.1 401 Unauthorized');
    echo "You must be logged in to submit an evaluation.";
}
