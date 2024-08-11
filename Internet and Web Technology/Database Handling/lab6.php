<!DOCTYPE html>
<html>
  <head>
    <title>Registration</title>
  </head>
  <body>
    <h2>Registration</h2>
    <?php
      $usernameErr = $emailErr = $passwordErr = $repeatPasswordErr = $firstNameErr = $lastNameErr = $phoneErr = $streetErr = $cityErr = $stateErr = $zipcodeErr = $countryErr = "";
      $username = $email = $password = $repeatPassword = $firstName = $lastName = $phone = $street = $city = $state = $zipcode = $country = $membershipLevel = "";
      $validForm = false;
      if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (empty($_POST["username"])) {
          $usernameErr = "Username is required";
        } else {
          $username = test_input($_POST["username"]);
          if (!preg_match("/^[a-zA-Z0-9]*$/",$username)) {
            $usernameErr = "Username can only contain letters and numbers";
          }
        }
        if (empty($_POST["email"])) {
          $emailErr = "Email is required";
        } else {
          $email = test_input($_POST["email"]);
          if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email format";
          }
        }
        if (empty($_POST["password"])) {
          $passwordErr = "Password is required";
        } else {
          $password = test_input($_POST["password"]);
        }
        if (empty($_POST["repeat_password"])) {
          $repeatPasswordErr = "Please repeat your password";
        } else {
          $repeatPassword = test_input($_POST["repeat_password"]);
          if ($password !== $repeatPassword) {
            $repeatPasswordErr = "Passwords do not match";
          }
        }
        if (empty($_POST["first_name"])) {
          $firstNameErr = "First name is required";
        } else {
          $firstName = test_input($_POST["first_name"]);
        }
        if (empty($_POST["last_name"])) {
          $lastNameErr = "Last name is required";
        } else {
          $lastName = test_input($_POST["last_name"]);
        }
        if (empty($_POST["phone"])) {
          $phoneErr = "Phone number is required";
        } else {
          $phone = test_input($_POST["phone"]);
          if (!preg_match("/^[0-9+]*$/",$phone)) {
            $phoneErr = "Phone number can only contain numbers and '+'";
          }
        }
        if (empty($_POST["street"])) {
          $streetErr = "Street address is required";
        } else {
          $street = test_input($_POST["street"]);
        }
        if (empty($_POST["city"])) {
          $cityErr = "City is required";
        } else {
          $city = test_input($_POST["city"]);
        }
        if (empty($_POST["state"])) {
          $stateErr = "State is required";
        } else {
          $state = test_input($_POST["state"]);
        }
        if (empty($_POST["zipcode"])) {
          $zipcodeErr = "Zip code is required";
        } else {
          $zipcode = test_input($_POST["zipcode"]);
          if (!preg_match("/^[0-9]*$/",$zipcode)) {
            $zipcodeErr = "Zip code can only contain numbers";
          }
        }
        if (empty($_POST["country"])) {
            $countryErr = "Country is required";
        } else {
            $country = test_input($_POST["country"]);
            // Check if country only contains letters and whitespace
            if (!preg_match("/^[a-zA-Z ]*$/",$country)) {
              $countryErr = "Only letters and white space allowed";
            }
        }
        if (empty($_POST["membership_level"])) {
          $membershipLevel = "Free";
        } else {
          $membershipLevel = test_input($_POST["membership_level"]);
        }
      }
      function test_input($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
      }
    ?>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      <label for="username">User Name</label>
      <input type="text" name="username" value="<?php echo $username;?>"><br>
      <span class="error"><?php echo $usernameErr;?></span><br><br>
      <label for="email">Email</label>
      <input type="text" name="email" value="<?php echo $email;?>"><br>
      <span class="error"><?php echo $emailErr;?></span><br><br>
      <label for="password">Password</label>
      <input type="password" name="password"><br>
      <span class="error"><?php echo $passwordErr;?></span><br><br>
      <label for="repeat_password">Repeat Password</label>
      <input type="password" name="repeat_password"><br>
      <span class="error"><?php echo $repeatPasswordErr;?></span><br><br>
      <label for="first_name">First Name</label>
      <input type="text" name="first_name" value="<?php echo $firstName;?>"><br>
      <span class="error"><?php echo $firstNameErr;?></span><br><br>
      <label for="last_name">Last Name</label>
      <input type="text" name="last_name" value="<?php echo $lastName;?>"><br>
      <span class="error"><?php echo $lastNameErr;?></span><br><br>
      <label for="phone">Phone</label>
      <input type="text" name="phone" value="<?php echo $phone;?>"><br>
      <span class="error"><?php echo $phoneErr;?></span><br><br>
      <label for="street">Street</label>
      <input type="text" name="street" value="<?php echo $street;?>"><br>
      <span class="error"><?php echo $streetErr;?></span><br><br>
      <label for="city">City</label>
      <input type="text" name="city" value="<?php echo $city;?>"><br>
      <span class="error"><?php echo $cityErr;?></span><br><br>
      <label for="state">State</label>
      <input type="text" name="state" value="<?php echo $state;?>"><br>
      <span class="error"><?php echo $stateErr;?></span><br><br>
      <label for="zipcode">Zip Code</label>
      <input type="text" name="zipcode" value="<?php echo $zipcode;?>"><br>
      <span class="error"><?php echo $zipcodeErr;?></span><br><br>
      <label for="country">Country</label>
      <input type="text" name="country" value="<?php echo $country;?>"><br>
      <span class="error"><?php echo $countryErr;?></span><br>
      <label for="membership_level">Membership Level</label>
      <select name="membership_level">
        <option value="Free" <?php if (isset($membershipLevel) && $membershipLevel == "Free") echo "selected";?>>Free</option>
        <option value="Premium" <?php if (isset($membershipLevel) && $membershipLevel == "Premium") echo "selected";?>>Premium</option>
        <option value="Platinum" <?php if (isset($membershipLevel) && $membershipLevel == "Platinum") echo "selected";?>>Platinum</option>
      </select><br><br>
      <input type="submit" name="register" value="Register" style="background-color: red; color: white; padding: 10px 20px; border: none; border-radius: 5px; cursor: pointer;">
    </form>
    <?php
      if ($validForm) {
        echo "<h2>Registration Details:</h2>";
        echo "<p><strong>User Name:</strong> " . $username . "</p>";
        echo "<p><strong>Email:</strong> " . $email . "</p>";
        echo "<p><strong>First Name:</strong> " . $firstName . "</p>";
        echo "<p><strong>Last Name:</strong> " . $lastName . "</p>";
        echo "<p><strong>Phone:</strong> " . $phone . "</p>";
        echo "<p><strong>Street:</strong> " . $street . "</p>";
        echo "<p><strong>City:</strong> " . $city . "</p>";
        echo "<p><strong>State:</strong> " . $state . "</p>";
        echo "<p><strong>Zip Code:</strong> " . $zipcode . "</p>";
        echo "<p><strong>Country:</strong> " . $country . "</p>";
        echo "<p><strong>Membership Level:</strong> " . $membershipLevel . "</p>";
      }
    ?>
  </body>
</html>