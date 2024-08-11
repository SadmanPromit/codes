<?php
if(isset($_POST['submit'])){
  $numbers = $_POST['numbers'];
  $numbers_array = array_map('intval', explode(',', $numbers));
  $frequency = array_count_values($numbers_array);
  foreach($frequency as $number => $count){
    echo "$number occurred $count times. <br>";
  }
}
?>
<form method="post">
  <label for="numbers">Enter Numbers (separated by commas):</label><br>
  <input type="text" name="numbers"><br>
  <input type="submit" name="submit" value="Submit">
</form>