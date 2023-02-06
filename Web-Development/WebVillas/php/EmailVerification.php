<?php
    require('../php/function.php');
    session_start();
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie-edge">
    <title>Sign Up</title>

    <link rel="stylesheet" type="text/css" href="../css/SignUpFormValidation.css">
    <script src="https://www.google.com/recaptcha/api.js"async defer></script>
    <script type="text/javascript">
        function validateForm() {
            var ver_code = document.getElementById('VerificationCode').value;
            
            if (ver_code.length != 5) {
                document.getElementById('message').innerHTML = "<br>**The password must have consisted of 5 digits <br>";
                return false;
            }
            else {
                document.getElementById("message").innerHTML = "";
            }
        }
    </script>
</head>

<body>
    <div class="sign-up-form">
        <img src="../img/user-icon2.png">
        <h1> We've sent a verification code on email</h1>
        <form id="form" method="POST" action="CheckEmailVerification.php" onsubmit="return validateForm();">
            <input id="VerificationCode" name="VerificationCode" type="username" class="input-box" placeholder="Verification code" required>
            <span id = "message" style="color:red"></span>
            <?php  echo_msg(); ?>
            <div class="g-recaptcha" data-sitekey="6LeHDfwdAAAAALNSwzm2p_aDfek2GNR4ei8xHVGK"></div>
            <button type="submit" class="sign-btn">Submit</button>
        </form>
    </div>
</body>

</html>