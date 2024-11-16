<?php
require_once 'utils.php';

// Check if the user is logged in
if (!isLoggedIn()) {
    header('HTTP/1.1 403 Forbidden');
    exit;
}

// Get the current user's ID and type
$user_id = getUserId();
$user_type = getUserType();
