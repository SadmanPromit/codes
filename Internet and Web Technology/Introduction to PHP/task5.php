<?php
function validatePassword($pass) {
  if(strlen($pass) < 8 || strlen($pass) > 32){
    return "Password must be between 8-32 characters.";
  }
  if(!preg_match("/[A-Z]/", $pass) || !preg_match("/[a-z]/", $pass) || !preg_match("/[0-9]/", $pass)){
    return "Password must contain atleast one uppercase, one lowercase, and one numeric character.";
  }
  if(preg_match("/[^a-zA-Z0-9]/", $pass)){
    return "Password cannot contain any special character.";
  }
  return "Password is valid.";
}
if(isset($_POST['submit'])){
  $password = $_POST['password'];
  $result = validatePassword($password);
  echo $result;
}
?>
<form method="post">
  <label for="password">Enter Password:</label><br>
  <input type="password" name="password"><br>
  <input type="submit" name="submit" value="Submit">
</form>