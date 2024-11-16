<?php
include 'navigation.php';

// Check if the user is logged in
require_once 'session.php';
if (!isLoggedIn()) {
    header('Location: login.php');
    exit;
}

// Include the HTML file
include 'map.html';
?>
