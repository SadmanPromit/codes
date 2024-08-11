<!DOCTYPE html>
<html>
<head>
    <style>
        ul.navbar {
            list-style-type: none;
            margin: 0;
            padding: 0;
            overflow: hidden;
            background-color: #333;
        }

        ul.navbar li {
            float: left;
        }

        ul.navbar li a {
            display: block;
            color: white;
            text-align: center;
            padding: 14px 16px;
            text-decoration: none;
        }

        ul.navbar li a:hover {
            background-color: #111;
        }
    </style>
</head>
<body>
    <ul class="navbar">
        <?php
            require_once 'utils.php';

            if(isLoggedIn()) {
                // Navigation for logged in users
                echo '<li><a href="user_profile.php">User Profile</a></li>';
                echo '<li><a href="dashboard.php">Dashboard</a></li>';
                echo '<li><a href="department.php">Department</a></li>';
                echo '<li><a href="course.php">Course</a></li>';
                echo '<li><a href="section.php">Section</a></li>';
                echo '<li><a href="attendance.php">Attendance</a></li>';
                echo '<li><a href="grades.php">Grades</a></li>';
                echo '<li><a href="payment.php">Payment</a></li>';
                echo '<li><a href="message.php">Message</a></li>';
                echo '<li><a href="curriculum.php">Curriculum</a></li>';
                echo '<li><a href="assignment.php">Assignment</a></li>';
                echo '<li><a href="evaluation.php">Evaluation</a></li>';

                // Additional links for admin users
                if(isAdmin()) {
                    echo '<li><a href="admin_dashboard.php">Admin Dashboard</a></li>';
                    echo '<li><a href="user_management.php">User Management</a></li>';
                    echo '<li><a href="academic_management.php">Academic Management</a></li>';
                    echo '<li><a href="role_assignment.php">Role Assignment</a></li>';
                }
                echo '<li><a href="logout.php">Logout</a></li>';
            } else {
                // Navigation for guests
                echo '<li><a href="register.php">Register</a></li>';
                echo '<li><a href="login.php">Login</a></li>';
            }
        ?>
    </ul>
</body>
</html>
