<?php
require_once 'db_connect.php';
include 'navigation.php';

try {
    $stmt = $pdo->prepare("SELECT * FROM department");
    $stmt->execute();
    $result = $stmt->fetchAll(PDO::FETCH_ASSOC);

    // Returns data as JSON
    echo json_encode($result);
} catch (PDOException $e) {
    if (DEBUG_MODE) {
        die("Database error: " . $e->getMessage());
    } else {
        error_log($e->getMessage(), 1, ADMIN_EMAIL);
        header('Content-Type: application/json');
        echo json_encode(["error" => "Failed to fetch departments."]);
        exit;
    }
}
?>
