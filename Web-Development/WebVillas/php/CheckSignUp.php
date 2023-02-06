<?php 
    session_start();
    $username = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email']; 
    $flag = 0;  // An flag = 0 To onoma den uparxei ara mporoume na to kataxwrisoume. An flag = 1 tha tou emfanisoume ena mnm oti to name uparxei
    
  
    require('db_param.php');// include data for db connection.. ps. localhost, username...

    //Data base connection
    try {
        $conn = new PDO($db_dsn, $db_user, $db_password);

        // set the PDO error mode to exception
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
   
        $sql = "SELECT username FROM registration";
        $stmt = $conn->prepare($sql); 
        $stmt->execute(['username' => $username]);
        $row = $stmt->fetchALL();

        foreach($row as $rs) {
            if($rs['username'] == $username) {
                $flag = 1;
                echo "Username is unvailable.. Please choose another one..";
            }     
        }

        if($flag == 0) {
            $ver_code = rand(10001, 99999);

            $to = $email;
            $subject = 'Email verification';
            $message = "Your verification code : ". "<b>".$ver_code."</b>";
            $headers  = 'From: alphaenadio@gmail.come' . "\r\n" .
                        'MIME-Version: 1.0' . "\r\n" .
                        'Content-type: text/html; charset=utf-8';
            
            if(mail($to, $subject, $message, $headers)) {
                $_SESSION['ver_code'] = $ver_code;
                $_SESSION['username'] = $username;
                $_SESSION['password'] = $_POST['password'];
                $_SESSION['email'] = $_POST['email'];

                header('Location: EmailVerification.php');
            }
            else {
                echo "Sending email failed.. Try again!";
                echo  '<img src="../img/error2.jpg" style="height: 600px; display: block;margin-left: auto;margin-right: auto;width: 50%;"/>';
            }  
        }
    } catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
        echo  '<img src="../img/error2.jpg" style="height: 600px; display: block;margin-left: auto;margin-right: auto;width: 50%;"/>';
    }  
?>
