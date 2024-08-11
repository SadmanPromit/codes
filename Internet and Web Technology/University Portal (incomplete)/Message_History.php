<?php
// Include your database connection file
include 'db_conn.php';

// retrieve message history from database
$sql = "SELECT * FROM message";
$result = mysqli_query($conn, $sql);

// check if there are any results
if (mysqli_num_rows($result) > 0) {
    // output data of each row
    while($row = mysqli_fetch_assoc($result)) {
        echo "<tr>";
        echo "<td>" . $row["message_id"] . "</td>";
        echo "<td>" . $row["semester"] . "</td>";
        echo "<td>" . $row["faculty_code"] . "</td>";
        echo "<td>" . $row["send_to"] . "</td>";
        echo "<td>" . $row["message_body"] . "</td>";
        echo "<td>" . $row["sending_time"] . "</td>";
        echo "</tr>";
    }
} else {
    echo "0 results";
}

// close connection
mysqli_close($conn);
?>
