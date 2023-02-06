<?php   
    session_start();
    $_SESSION['active'] = 0;
    header('Location: ../js/index.php');
?>