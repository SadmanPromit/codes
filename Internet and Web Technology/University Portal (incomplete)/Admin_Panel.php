<?php
// Include your database connection file
include 'db_conn.php';

// Check if form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Add or Delete user
    if(isset($_POST['AddDelete']) && isset($_POST['FacultyInstructorStudent']) && isset($_POST['ID'])){
        $action = $_POST['AddDelete'];
        $type = $_POST['FacultyInstructorStudent'];
        $id = $_POST['ID'];

        if($action == 'Add'){
            // Add a new user
            $stmt = $conn->prepare("INSERT INTO user (user_id, user_type) VALUES (?, ?)");
            $stmt->bind_param("is", $id, $type);
        }elseif($action == 'Delete'){
            // Delete a user
            $stmt = $conn->prepare("DELETE FROM user WHERE user_id = ?");
            $stmt->bind_param("i", $id);
        }

        if ($stmt->execute() === TRUE) {
            echo "Record updated successfully";
        } else {
            echo "Error updating record: " . $stmt->error;
        }
        $stmt->close();
    }

    // Change Password
    if(isset($_POST['Password']) && isset($_POST['NewPassword']) && isset($_POST['ConfirmPassword'])){
        $currentPassword = $_POST['Password'];
        $newPassword = $_POST['NewPassword'];
        $confirmPassword = $_POST['ConfirmPassword'];

        if($newPassword == $confirmPassword){
            // Retrieve the existing hash
            $stmt = $conn->prepare("SELECT login_password FROM login WHERE user_id = ?");
            $stmt->bind_param("i", $id);
            $stmt->execute();
            $result = $stmt->get_result();
            $user = $result->fetch_object();

            // Check the provided password against the hash
            if (password_verify($currentPassword, $user->login_password)) {
                // Change password
                $newPasswordHash = password_hash($newPassword, PASSWORD_DEFAULT);
                $stmt = $conn->prepare("UPDATE login SET login_password = ? WHERE user_id = ?");
                $stmt->bind_param("si", $newPasswordHash, $id);

                if ($stmt->execute() === TRUE) {
                    echo "Password updated successfully";
                } else {
                    echo "Error updating password: " . $stmt->error;
                }
            } else {
                echo "Current password is incorrect";
            }
        }else{
            echo "New password and confirm password do not match";
        }
        $stmt->close();
    }
}

$conn->close();
?>
