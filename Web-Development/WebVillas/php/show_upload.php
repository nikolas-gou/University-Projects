<?php
    require("../php/function.php");
?>
<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie-edge">
    <title>choose</title>

    <link rel="stylesheet" type="text/css" href="../css/LogInFormValidation.css">

    <style type="text/css">  
        .img-btn {
            background-color: #a4ce6d;
        }
    </style>
</head>

<body>
    <div class="sign-up-form">
        <h1> Choose</h1>
        <form action="ViewImage2.php?n=1">
            <button type="submit" class="sign-btn">Show your uploads</button>
        </form>
            <hr>
            <p class="or">OR</p>
        <form action="UploadImage.php">
            <button type="submit" class="google-btn">Upload new accomodation</button>
        </form>
    </div>
</body>

</html>
