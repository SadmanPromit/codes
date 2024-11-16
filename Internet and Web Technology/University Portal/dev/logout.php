<?php
    require_once 'utils.php';
    logoutUser();
    header("Location: login.php");
    exit;
?>
