<?php
    require("../php/function.php");
?>
<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie-edge">
    <title>Log in</title>

    <link rel="stylesheet" type="text/css" href="../css/LogInFormValidation.css">
    <script type="text/javascript">
        function validateForm() {
            var username = document.getElementById('username').value;
            var password = document.getElementById('password').value;
            
            if(username == 'test') {
                document.getElementById('message').innerHTML = "<br>**username";
                return false;
            }
            if (password.length < 10 || password.length > 15) {
                document.getElementById('message').innerHTML = "<br>**Password length must be at least 10 and 15 characters max";
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
        <h1> Log in</h1>
        <form id="form" method="POST" action="../php/CheckLogIn.php" onsubmit="return validateForm();">
            <input id="username" name="username" type="username" class="input-box" placeholder="Your Username" required>
            <input id="password" name ="password" type="password" class="input-box" placeholder="Your Password" required>
            <span id = "message" style="color:red"></span> 
            <?php echo_msg(); ?>
            <p class="remember"><a href="#">I don't remember my password</a></p>
            <button type="submit" class="sign-btn">Log in</button>
            <hr>
            <p class="or">OR</p>
            <button type="button" class="google-btn">Log in with google</button>
            <p>If you not have an account <a href="SignUpFormValidation.php">Sign in</a></p>
        </form>
    </div>
</body>

</html>
