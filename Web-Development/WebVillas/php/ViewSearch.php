<?php
    session_start();
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie-edge">
    <title>Upload accomodation</title>

    <link rel="stylesheet" type="text/css" href="../css/UploadAccomodation.css">

    <style>
          * {
              margin: 0;
              padding: 0;
          }
          #map {
              height: 300px;
              width: 300px;
          }
      </style>
</head>

<body>
    <div class="sign-up-form">
        <?php
            require('db_param.php');// include data for db connection.. ps. localhost, username...
             //Data base connection
             try {
                 $conn = new PDO($db_dsn, $db_user, $db_password);
         
                 // set the PDO error mode to exception
                 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            
                 $sql = "SELECT * FROM accomodation WHERE id=:id";
                 $stmt = $conn->prepare($sql); 
                 $stmt->execute(['id' => $_GET['id']]);
        
    
                while($row = $stmt -> fetch()) {
                    if($row['pool'] == 1) $pool = 'Ναι';
                    else    $pool = 'Όχι';
                    if($row['sauna'] == 1) $sauna = 'Ναι';
                    else    $sauna = 'Όχι';
                    if($row['parking'] == 1) $parking = 'Ναι';
                    else    $parking = 'Όχι';
                    if($row['gym'] == 1) $gym = 'Ναι';
                    else    $gym = 'Όχι';

                    echo '<div class="div-result"><p class="result">' . 
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
                    'Γυμναστήριο : ' . $gym . '</br>' .
                    '</div>' 
                    ;
                }
            }       
             catch(PDOException $e) {
                 echo "Connection failed: " . $e->getMessage();
             }
    ?>

    
<script>
    function initMap() {
        var location = {lat: -25.363, lng: 131.044};
        var map = new google.maps.Map(document.getElementById("map"), {
            zoom: 4, 
            center: location
        });
    }
</script>
<script async defer src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCL4iIyj1aIwIqTfcUOsgsgGJ1sv3r6xeE&callback=initMap"></script>
    </div>
</body>

</html>