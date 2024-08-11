<?php
// Database connection settings
define('DB_DSN', 'mysql:host=localhost;dbname=university_portal;charset=utf8mb4');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_OPTIONS', [
    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    PDO::ATTR_EMULATE_PREPARES => false,
]);

// Site URL for absolute paths
define('SITE_URL', 'https://your-university-portal.com');

// Default time zone
date_default_timezone_set('Asia/Dhaka');

// Password default cost for hashing
define('PASSWORD_COST', 10);

// Enable debug mode
define('DEBUG_MODE', true);

// Admin email for error reporting
define('ADMIN_EMAIL', 'admin@your-university-portal.com');

// Setting for infinite scroll, pagination etc.
define('RECORDS_PER_PAGE', 10);

// Mail server settings
define('MAIL_HOST', 'smtp.your-university-portal.com');
define('MAIL_USERNAME', 'your-email@your-university-portal.com');
define('MAIL_PASSWORD', 'password');
define('MAIL_PORT', 587);

// Content Security Policy
header("Content-Security-Policy: default-src 'self'; script-src 'self' https://apis.google.com; img-src 'self'; style-src 'self'");

// HTTPS Redirect
if (!isset($_SERVER['HTTPS']) || $_SERVER['HTTPS'] !== 'on') {
    $redirectURL = 'https://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    header("HTTP/1.1 301 Moved Permanently");
    header("Location: $redirectURL");
    exit;
}

// Start the session
session_start();

// Secure the session
ini_set('session.cookie_httponly', 1);
if (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on') {
    ini_set('session.cookie_secure', 1);
}
?>
