<?php
// Include your database connection file
include 'db_conn.php';

// Check if form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    // Fetch all form data
    for ($i = 1; $i <= 15; $i++) {
        $question = "question".$i;
        if(isset($_POST[$question])) {
            ${"question".$i} = $_POST[$question];
        } else {
            // If not set, you can set a default value or handle the error
            ${"question".$i} = "Not Answered";
        }
    }
    $comment = $_POST['Comment'];

    // Prepare an SQL statement for execution
    $stmt = $conn->prepare("INSERT INTO faculty_evaluation (question1, question2, question3, question4, question5, question6, question7, question8, question9, question10, question11, question12, question13, question14, question15, comment) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    // Bind variables to the prepared statement as parameters
    $stmt->bind_param("ssssssssssssssss", $question1, $question2, $question3, $question4, $question5, $question6, $question7, $question8, $question9, $question10, $question11, $question12, $question13, $question14, $question15, $comment);

    // Attempt to execute the prepared statement
    if($stmt->execute()){
        // Redirect to thank you page upon success
        header("location: thank_you.html");
    } else{
        echo "Something went wrong. Please try again later.";
    }

    // Close statement
    $stmt->close();
}

// Close connection
$conn->close();
?>