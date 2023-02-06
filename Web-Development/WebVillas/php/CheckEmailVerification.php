<?php
session_start();
$ver_code = $_POST['VerificationCode'];
$username = $_SESSION['username'];
$password = $_SESSION['password'];
$email = $_SESSION['email'];
$salt = '$6$DokSalt';
$active = 1;

$encrypt_pass = crypt($password, $salt);

if(isset($_SESSION['ver_code'])) {
    if($ver_code == 11111/*$_SESSION['ver_code']*/) {
        require('db_param.php');// include data for db connection.. ps. localhost, username...
        //Data base connection
        try {
            $conn = new PDO($db_dsn, $db_user, $db_password);
    
            // set the PDO error mode to exception
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
       
            $sql = "INSERT INTO registration (username, password, salt, email, active) VALUES (:username, :password, :salt, :email, :active)";
            $stmt = $conn->prepare($sql); 
            $stmt->execute(['username' => $username, 'password' => $encrypt_pass, 'salt' => $salt, 'email' => $email, 'active' => $active]);
 
        }
        catch(PDOException $e) {
            echo "Connection failed: " . $e->getMessage();
        }
        $_SESSION['active'] = 1;

        header('Location: ../js/index.php');
    }
    else 
        header('Location: EmailVerification.php?msg=The verfication code is wrong..');
}   else {
        header('Location: EmailVerification.php?msg=Something went wrong.. please try again');
}
 

?>