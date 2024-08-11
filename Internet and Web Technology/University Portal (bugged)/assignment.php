<?php
require_once 'utils.php';
include 'navigation.php';

// Determine the action to take
$action = $_POST['action'] ?? 'invalid';

if ($action === 'getWelcomeMessage') {
    if (isLoggedIn()) {
        echo "Welcome back, " . $_SESSION['user_first_name'] . "!";
    } else {
        echo "You are not logged in.";
    }
} else {
    echo "Invalid action.";
}
?>
