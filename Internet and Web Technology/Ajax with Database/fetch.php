<?php include('db_connect.php'); ?>
<?php

$output='';
if(isset($_POST["query"])){
	$search=mysqli_real_escape_string($connection, $_POST["query"]);
	$query="SELECT * FROM customerdetails WHERE name LIKE '%".$search."%'";
}
else{
	$query="SELECT * FROM customerdetails ORDER BY id";
}
$result= mysqli_query($connection, $query);
if(mysqli_num_rows($result)>0){
	$output .= '<div class="table-responsive">
					<table class="table table bordered"
					<tr>
						<th>Customer Name</th>
						<th>Address</th>
						<th>Contact</th>
					</tr>';
	while($row=mysqli_fetch_array($result)){
		
		$output .='
			<tr>
			<td>'.$row["name"].'</td>
			<td>'.$row["address"].'</td>
			<td>'.$row["contact"].'</td>
			</tr>';
	}				
	echo $output;
		
}
else{
	echo nl2br("\nData not found");
}
?>
<?php include('db_close.php');?>