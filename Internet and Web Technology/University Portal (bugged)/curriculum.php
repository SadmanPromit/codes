<?php
require_once 'session.php';
requireUserType('faculty');
include 'navigation.php';

try {
    $stmt = $pdo->prepare("SELECT curriculum_content FROM curriculum WHERE course_id = :course_id");
    $stmt->bindParam(':course_id', $_SESSION['course_id'], PDO::PARAM_INT);
    $stmt->execute();

    while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
        echo "<p>" . htmlspecialchars($row['curriculum_content']) . "</p>";
    }
} catch(PDOException $e) {
    if (DEBUG_MODE) {
        die("ERROR: Could not execute $sql. " . $e->getMessage());
    } else {
        error_log($e->getMessage(), 1, ADMIN_EMAIL);
        echo "<p>There was an error loading the curriculum. Please try again later.</p>";
    }
} finally {
    $stmt = null;
    $pdo = null;
}
?>
