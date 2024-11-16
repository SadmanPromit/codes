<?php
// Include your database connection file
include 'db_conn.php';

class Message {
    private $conn;
    private $table_name = "messages";

    public $course1;
    public $course2;
    public $course3;
    public $course4;
    public $course5;
    public $message;

    public function __construct($db) {
        $this->conn = $db;
    }

    public function create() {
        $query = "INSERT INTO " . $this->table_name . " SET course1=:course1, course2=:course2, course3=:course3, course4=:course4, course5=:course5, message=:message";

        $stmt = $this->conn->prepare($query);

        $stmt->bindParam(':course1', $this->course1);
        $stmt->bindParam(':course2', $this->course2);
        $stmt->bindParam(':course3', $this->course3);
        $stmt->bindParam(':course4', $this->course4);
        $stmt->bindParam(':course5', $this->course5);
        $stmt->bindParam(':message', $this->message);

        if($stmt->execute()) {
            return true;
        } else {
            return false;
        }
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $database = new Database();
    $conn = $database->dbConnection();
    $message = new Message($conn);

    $message->course1 = isset($_POST['course1']) ? $_POST['course1'] : null;
    $message->course2 = isset($_POST['course2']) ? $_POST['course2'] : null;
    $message->course3 = isset($_POST['course3']) ? $_POST['course3'] : null;
    $message->course4 = isset($_POST['course4']) ? $_POST['course4'] : null;
    $message->course5 = isset($_POST['course5']) ? $_POST['course5'] : null;
    $message->message = isset($_POST['Message']) ? $_POST['Message'] : null;

    if($message->create()) {
        echo 'Message sent successfully.';
    } else {
        echo 'Unable to send message.';
    }
}
?>