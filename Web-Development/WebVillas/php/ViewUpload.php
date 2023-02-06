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
    <title>Upload accomodation</title>

    <link rel="stylesheet" type="text/css" href="../css/UploadAccomodation.css">
</head>

<body>
    <div class="sign-up-form">
        <?php

             $username = $_SESSION['username'];
             $id_m = $_GET['id'];
             echo $id_m;
             require('db_param.php');// include data for db connection.. ps. localhost, username...
             //Data base connection
             try {
                 $conn = new PDO($db_dsn, $db_user, $db_password);
         
                 // set the PDO error mode to exception
                 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            
                 $sql = "SELECT * FROM accomodation WHERE id_img=:id_m";
                 $stmt = $conn->prepare($sql); 
                 $stmt->execute(['id_m' => $id_m]);
        
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
                    'Ιδιοκτήτης : ' . $row['username'] . '</br>' .
                    'Τίτλος : ' . $row['title'] . '</br>' .
                    'Νομός : ' . $row['prefecture'] . '</br>' . 
                    'Διεύθυνση : ' . $row['address'] . '</br>'.
                    'Κινητό : ' . $row['number'] . '</br>' .
                    'Χωρητικότητα : ' . $row['guest'] . '</br>' .
                    'Ποιότητα βίλας : ' . $row['review'] . '</br>' .
                    'Πισίνα : ' . $pool . '</br>' .
                    'Σάουνα : ' . $sauna . '</br>' .
                    'Πάρκινγκ : ' . $parking . '</br>' .
                    'Γυμναστήριο : ' . $gym . '</br>' 
                    ;

                    echo '<a href="EditAccomodation.php?id=' . $row['id'] . '"><img src="edit.png" alt =""></a>' . 
                    '<a href="DeleteAccomodation.php?id=' . $row['id'] . '"><img src="delete.gif" alt =""></a>'
                    ;
                }
            }       
             catch(PDOException $e) {
                 echo "Connection failed: " . $e->getMessage();
             }

             /*while($row = $stmt -> fetch())
                    echo '<p class="result">' . 
                    $row['username'] .
                    ' - ' .
                    $row['title'] .
                    ' <a href="page_dualform.php?mode=update&id='.
                    $row['id'] .
                    '"><img src="edit.png"/></a> <a onclick="return verify();" href="con_delete.php?id='.
                    $row['guest'] .
                    '"><img src="delete.gif"/></a>   </p>';
             }*/
        ?>
    </div>
</body>

</html>