<?php
if(isset($_POST['submit'])){
  $names = $_POST['names'];
  $reversed_names = array();
  for($i = count($names) - 1; $i >= 0; $i--){
    $reversed_names[] = $names[$i];
  }
  echo "Original Array: <br>";
  print_r($names);
  echo "<br> Reversed Array: <br>";
  print_r($reversed_names);
}
?>
<form method="post">
  <label for="names">Enter Names:</label><br>
  <input type="text" name="names[]"><br>
  <input type="text" name="names[]"><br>
  <input type="text" name="names[]"><br>
  <input type="submit" name="submit" value="Submit">
</form>