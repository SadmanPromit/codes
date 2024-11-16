<?php
require_once 'db_connect.php';
include 'navigation.php';

if (!isset($_SESSION['section_id'])) {
    die('Error: section_id not set in session');
}

// Select the attendance records from the database
$stmt = $pdo->prepare('SELECT u.user_first_name, a.present FROM attendance a JOIN user u ON a.user_id = u.user_id WHERE section_id = :section_id');
$stmt->execute(['section_id' => $_SESSION['section_id']]);

$data = [];
while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
    $data[] = ['name' => $row['user_first_name'], 'attendance' => $row['present'] ? 'Present' : 'Absent'];
}

header('Content-Type: application/json');
echo json_encode($data);
?>
