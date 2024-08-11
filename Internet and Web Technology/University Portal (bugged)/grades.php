<?php
require_once 'session.php';
requireUserType('student'); // Only students should be able to access this
include 'navigation.php';

try {
    $user_id = getUserId();

    $sql = "SELECT course.course_title, section.section_id, grades.grade 
            FROM grades
            JOIN section ON grades.section_id = section.section_id
            JOIN course ON section.course_id = course.course_id
            WHERE grades.user_id = :user_id";
            
    $stmt = $pdo->prepare($sql);
    $stmt->execute(['user_id' => $user_id]);
    $grades = $stmt->fetchAll();

    echo json_encode($grades);

} catch(PDOException $e) {
    error_log($e->getMessage(), 1, ADMIN_EMAIL);
    header('HTTP/1.1 500 Internal Server Error');
    exit;
}
?>
