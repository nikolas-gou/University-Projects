<?php
    session_start();
    $active = 0;
    $username = $_POST['username'];
    $password = $_POST['password'];

    //Data base connection
    require('db_param.php');// include data for db connection.. ps. localhost, username...
    try {
        $conn = new PDO($db_dsn, $db_user, $db_password);
        // set the PDO error mode to exception
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "SELECT * FROM registration WHERE username=:username";
        $stmt = $conn->prepare($sql); 
        $stmt->execute(['username' => $username]);
        
        $record = $stmt -> fetch();
        if ($record['username'] == $username && $record['password'] == crypt($_POST['password'], $record['salt'])) {
            $_SESSION['active'] = 1;
            $_SESSION['username'] = $username;
            header('Location: ../js/index.php');
        } 
        else {
            header('Location: ../js/LogInFormValidation.php?msg=Username or password is wrong..');
        }
    } catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }  

?>