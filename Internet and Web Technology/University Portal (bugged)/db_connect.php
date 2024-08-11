require_once 'config.php';

if (!defined('DB_DSN')) {
    http_response_code(500);
    header('Content-Type: text/plain');
    exit('Database configuration error');
}

try {
    $pdo = new PDO(DB_DSN, DB_USERNAME, DB_PASSWORD, DB_OPTIONS);
} catch(PDOException $e) {
    if (defined('DEBUG_MODE') && DEBUG_MODE) {
        die("ERROR: Could not connect. " . $e->getMessage());
    } else {
        error_log($e->getMessage(), 1, ADMIN_EMAIL);
        header("Location: error.php");
        exit;
    }
}
