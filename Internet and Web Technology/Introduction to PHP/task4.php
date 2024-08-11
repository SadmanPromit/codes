<?php
function power($number, $degree) {
  $result = 1;
  for($i = 1; $i <= $degree; $i++){
    $result *= $number;
  }
  return $result;
}
if(isset($_POST['submit'])){
  $number = $_POST['number'];
  $degree = $_POST['degree'];
  $result = power($number, $degree);
  echo "Result: $result";
}
?>
<form method="post">
  <label for="number">Enter Number:</label><br>
  <input type="text" name="number"><br>
  <label for="degree">Enter Degree:</label><br>
  <input type="text" name="degree"><br>
  <input type="submit" name="submit" value="Submit">
</form>
