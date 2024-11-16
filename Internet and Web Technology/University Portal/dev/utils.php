require_once 'session.php';

function isLoggedIn() {
    return isset($_SESSION['user_id']);
}

function isAdmin() {
    return isset($_SESSION['user_type']) && $_SESSION['user_type'] === 'admin';
}

function getUserId() {
    return $_SESSION['user_id'] ?? null;
}

function getUserType() {
    return $_SESSION['user_type'] ?? null;
}

function requireUserType($requiredUserType) {
    if (!isLoggedIn() || getUserType() !== $requiredUserType) {
        http_response_code(403);
        header('Location: login.php');
        exit;
    }
}

function loginUser($user_id, $user_type) {
    $_SESSION['user_id'] = $user_id;
    $_SESSION['user_type'] = $user_type;
}

function logoutUser() {
    if (session_status() === PHP_SESSION_ACTIVE) {
        session_unset();
        session_destroy();
    }
}
