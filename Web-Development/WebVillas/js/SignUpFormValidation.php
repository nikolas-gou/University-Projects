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
    <title>Sign Up Now</title>

    <link rel="stylesheet" type="text/css" href="../css/SignUpFormValidation.css">

    <script type="text/javascript">
        function validateForm() {
            var username = document.getElementById('username').value;
            var password = document.getElementById('password').value;
            var cpassword = document.getElementById('cpassword').value;

            if (password.length < 9 || password.legth > 25) {
                document.getElementById('message').innerHTML = "<br>**Password length must be at least 10 and 25 characters max";
                return false;
            }
            else {
                document.getElementById("message").innerHTML = "";
            }

            if(password != cpassword) {
                document.getElementById('cmessage').innerHTML = "<br>**Passwords are wrong";
                return false;
            }
            else {
                document.getElementById("cmessage").innerHTML = "";
            }

            var regex = new RegExp(/^[0-9a-zA-Z]+$/);

            a = regex.test(password); 

            return true;
        }

        function showHint(str) {
            if (str.length == 0) {
                document.getElementById("txtHint").innerHTML = "";
                return;
            } else {
                var xmlhttp = new XMLHttpRequest();
                xmlhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("txtHint").innerHTML = this.responseText;
                }
                };
                xmlhttp.open("GET", "../php/CheckUsename.php?username=" + str, true);
                xmlhttp.send();
            }
        }
    </script>
</head>

<body>
    <div class="sign-up-form">
        <img src="../img/user-icon2.png">
        <h1> Sign Up</h1>
        <form id="form" method="POST" action="../php/CheckSignUp.php" onsubmit="return validateForm();">
            <input id="username" name="username" type="username" class="input-box" placeholder="Username"  onkeyup="showHint(this.value)"required>
            <span id="txtHint" style="color:red"></span>
            <input id="password" name ="password" type="password" class="input-box" placeholder="Password" required>
            <span id = "message" style="color:red"></span>
            <input id="cpassword" name ="cpassword" type="password" class="input-box" placeholder="Confirm Password" required>
            <span id = "cmessage" style="color:red"></span> 
            <input id="email" name="email" type="email" class="input-box" placeholder="Your Email" required>
            <p><span><input type="checkbox" required></span> agree to the terms of services</p>
            <button type="submit" class="sign-btn">Sign Up</button>
            <hr>
            <p class="or">OR</p>
            <button type="button" class="google-btn">Log in with google</button>
            <p>Do you have an account? <a href="LogInFormValidation.php">Log in</a></p>
        </form>
    </div>
</body>

</html>