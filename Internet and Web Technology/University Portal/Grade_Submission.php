<?php
// Include your database connection file
include 'db_conn.php';

// Process grade submission
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $user_id = $_POST["user_id"];
  $grade = $_POST["grade"];

  // Insert grade into the database
  $sql = "INSERT INTO evaluation (user_id, section_id, evaluation_data) VALUES ('$user_id', '$section_id', '$grade')";
  if (mysqli_query($conn, $sql)) {
    echo "Grade submitted successfully";
  } else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
  }
}

// Close connection
mysqli_close($conn);
?>