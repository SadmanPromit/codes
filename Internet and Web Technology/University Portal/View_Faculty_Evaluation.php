<?php
// Include your database connection file
include 'db_conn.php';

$sql = "SELECT * FROM FacultyEvaluation";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "<tr>";
    echo "<td>".$row["Point"]."</td>";
    echo "<td>".$row["Semester"]."</td>";
    echo "<td>".$row["CSE482.1"]."</td>";
    echo "<td>".$row["CSE482.2"]."</td>";
    echo "<td>".$row["CSE482.3"]."</td>";
    echo "<td>".$row["CSE482.4"]."</td>";
    echo "<td>".$row["CSE482.5"]."</td>";
    echo "</tr>";
  }
} else {
  echo "0 results";
}
$conn->close();
?>
