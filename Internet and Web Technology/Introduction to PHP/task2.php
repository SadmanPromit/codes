<?php
if(isset($_POST['submit'])){
  $message = $_POST['message'];
  $words = explode(" ", $message);
  echo "Original Message: $message <br>";
  echo "Original Words: <br>";
  print_r($words);

  echo "<br> Reversed Words: <br>";
  $reversed_words = array_reverse($words);
  print_r($reversed_words);
}
?>
<form method="post">
  <label for="message">Enter Message:</label><br>
  <input type="text" name="message"><br>
  <input type="submit" name="submit" value="Submit">
</form>
