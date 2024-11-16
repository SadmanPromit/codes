<?php
require_once 'db_connect.php';
require_once 'session.php';
include 'navigation.php';

header('Content-Type: application/json');

if (!isLoggedIn()) {
  echo json_encode(['error' => 'User is not logged in']);
  exit;
}

try {
  $stmt = $pdo->prepare("SELECT course_title, department_name FROM course JOIN department ON course.department_id = department.department_id");
  $stmt->execute();
  $result = $stmt->fetchAll();

  echo json_encode($result);
} catch (PDOException $e) {
  if (DEBUG_MODE) {
    echo json_encode(['error' => $e->getMessage()]);
  } else {
    error_log($e->getMessage(), 1, ADMIN_EMAIL);
    echo json_encode(['error' => 'An error occurred while retrieving course data']);
  }
}
?>
