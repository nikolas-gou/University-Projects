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
    <title>Search Villas</title>

    <link rel="stylesheet" type="text/css" href="../css/UploadAccomodation.css">

    <style type="text/css">
            a:link, a:visited {
                background-color: #58babf;
                color: white;
                margin-top: 5px;
                padding: 7px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
            }

            a:hover, a:active {
                background-color: #7692bf;
            }
        </style>
    </head>

    <body>
    <div class="sign-up-form">
    <?php

         $username = $_SESSION['username'];
         $prefecture = $_POST['location'];
         require('db_param.php');// include data for db connection.. ps. localhost, username...
         //Data base connection
         try {
             $conn = new PDO($db_dsn, $db_user, $db_password);
     
             // set the PDO error mode to exception
             $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        
             $sql = "SELECT * FROM accomodation WHERE prefecture=:prefecture";
             $stmt = $conn->prepare($sql); 
             $stmt->execute(['prefecture' => $prefecture]);
    
            echo_msg();
            while($row = $stmt -> fetch()) {
                if($row['pool'] == 1) $pool = 'Ναι';
                else    $pool = 'Όχι';
                if($row['sauna'] == 1) $sauna = 'Ναι';
                else    $sauna = 'Όχι';
                if($row['parking'] == 1) $parking = 'Ναι';
                else    $parking = 'Όχι';
                if($row['gym'] == 1) $gym = 'Ναι';
                else    $gym = 'Όχι';

                echo '<p class="result">' . 
                'Τίτλος : ' . $row['title'] . '</br>' .
                'Νομός : ' . $row['prefecture'] . '</br>' . 
                'Διεύθυνση : ' . $row['address'] . '</br>'.
                'Χωρητικότητα : ' . $row['guest'] . '</br>' .
                'Ποιότητα βίλας : ' . $row['review'] . '</br>' 
                ;
                
                echo '<a href="ViewSearch.php?id=' . $row['id'] . '" target="_blank">Show This</a>';

            }
        }       
         catch(PDOException $e) {
             echo "Connection failed: " . $e->getMessage();
         }

    ?>
</div>
</body>

</html>
