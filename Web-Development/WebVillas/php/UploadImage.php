<?php
    session_start();
    require("../php/function.php");
?>
<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie-edge">
    <title>Upload Image</title>

    <link rel="stylesheet" type="text/css" href="../css/UploadAccomodation.css">
    <link rel="icon" type="image/x-icon" href="../img/UploadImage.jpg">

    <style type="text/css">
        img {
            height: 5em;
        }    
        .btn {
            margin-top: 30px;
            color: #fff;
            width: 100%;
            padding: 10px;
            border-radius: 20px;
            font-size: 15px;
            margin: 10px 0;
            border: none;
            outline: none;
            cursor: pointer;
            background-color: #1c8adb;
        }
        textarea {
            width: 90%;
            margin-top: 20px;
        
        }
    </style>
</head>

<body>
    <div class="sign-up-form">
        <img src="../img/UploadImage.jpg">
        <h1>Upload Image</h1>
        <form action="CheckUploadImage.php" method="post" enctype="multipart/form-data" id="upload">
            Select image to upload:
            <input type="file" name="fileToUpload" id="fileToUpload" accept="image/jpeg">
            <textarea name="description" id="description" form="upload" placeholder="Add description image"></textarea>
            <input class="btn" type="submit" value="Continue to upload details of accomodation" name="submit">
        </form>    
    </div>
</body>

</html>
