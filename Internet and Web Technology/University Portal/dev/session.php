require_once 'db_connect.php';

define('SESSION_IDLE_TIMEOUT', 30 * 60);

if (session_status() === PHP_SESSION_NONE) {
    session_start([
        'cookie_lifetime' => SESSION_IDLE_TIMEOUT,
        'cookie_secure' => true,
        'cookie_httponly' => true,
    ]);

    if (!isset($_SESSION['CREATED']) || time() - $_SESSION['CREATED'] > SESSION_IDLE_TIMEOUT) {
        session_regenerate_id(true);    
        $_SESSION['CREATED'] = time();  
    }
}

if (isset($_SESSION['LAST_ACTIVITY']) && (time() - $_SESSION['LAST_ACTIVITY']) > SESSION_IDLE_TIMEOUT) {
    session_unset();
    session_destroy();
    session_start([
        'cookie_lifetime' => SESSION_IDLE_TIMEOUT,
        'cookie_secure' => true,
        'cookie_httponly' => true,
    ]);
}
$_SESSION['LAST_ACTIVITY'] = time();

if (empty($_SESSION['csrf_token'])) {
    try {
        $_SESSION['csrf_token'] = bin2hex(random_bytes(32));
    } catch (Exception $e) {
        error_log($e->getMessage());
        exit('Error generating CSRF token');
    }
}
