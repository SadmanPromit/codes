require_once 'db_connect.php';
require_once 'session.php';

if (!isLoggedIn()) {
    http_response_code(401);
    exit;
}

$sectionId = $_GET['sectionId'] ?? null;

if ($sectionId === null) {
    http_response_code(400);
    exit;
}

try {
    $stmt = $pdo->prepare('SELECT * FROM section WHERE section_id = ?');
    $stmt->execute([$sectionId]);
    $section = $stmt->fetch();

    if ($section === false) {
        http_response_code(404);
        exit;
    }

    header('Content-Type: application/json');
    echo json_encode($section);
} catch(PDOException $e) {
    if (DEBUG_MODE) {
        die("ERROR: Could not execute SQL. " . $e->getMessage());
    } else {
        error_log($e->getMessage(), 1, ADMIN_EMAIL);
        http_response_code(500);
        exit;
    }
}
