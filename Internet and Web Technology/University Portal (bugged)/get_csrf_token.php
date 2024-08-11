require_once 'session.php';

header('Content-Type: application/json');

if (isset($_SESSION['csrf_token'])) {
    echo json_encode(['csrf_token' => $_SESSION['csrf_token']]);
} else {
    http_response_code(500);
    echo json_encode(['error' => 'Error generating CSRF token']);
    exit;
}
