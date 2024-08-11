<!DOCTYPE html>
<html>
<head>
	<title>Month Information</title>
</head>
<body>
	<form method="POST">
		<label for="month">Enter month number (1-12):</label>
		<input type="number" id="month" name="month" min="1" max="12" required>
		<button type="submit">Submit</button>
	</form>

	<?php
	if (isset($_POST['month'])) {
		$month = $_POST['month'];
		$days = array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
		$total_days = array_sum(array_slice($days, 0, $month)) + ($month > 1 && date('L') ? 1 : 0); // adjust for leap years

		echo "<table>";
		echo "<tr><td>Name of the month</td><td>" . date('F', mktime(0, 0, 0, $month, 1)) . "</td></tr>";
		echo "<tr><td>Number of the month</td><td>$month</td></tr>";
		echo "<tr><td>Last day of the month</td><td>" . $days[$month-1] . "</td></tr>";
		echo "<tr><td>Number of days in year</td><td>$total_days</td></tr>";
		echo "</table>";
	}
	?>
</body>
</html>