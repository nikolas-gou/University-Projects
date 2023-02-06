<?php
    session_start();
    require("../php/function.php");
    require("db_param.php");

    $id = $_GET['id'];
    $url = "../php/CheckEditAccomodation.php?id=$id";

    try {
        $conn = new PDO($db_dsn, $db_user, $db_password);
        // set the PDO error mode to exception
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "SELECT * FROM accomodation WHERE id=:id";
        $stmt = $conn->prepare($sql); 
        $stmt->execute(['id' => $id]);
        
        if($stmt == true) {
            $row = $stmt -> fetch();
        } 
        else {
            header('Location: ViewUpload.php?msg=Something gone wrong Try again!');
        }
    } catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }  
?>
<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie-edge">
    <title>Update Accomodation</title>

    <link rel="stylesheet" type="text/css" href="../css/UploadAccomodation.css">
</head>

<body>
    <div class="sign-up-form">
        <img src="../img/user-icon2.png">
        <h1>Update your accomodation</h1>
        <form id="form" method="POST" action="<?php echo $url; ?>">
            <input id="title" name="title" type="title" class="input-box" value="<?php echo $row['title']; ?>" required>
            <input id="prefecture" name ="prefecture" type="prefecture" class="input-box" value="<?php echo $row['prefecture']; ?>" required>
            <input id="address" name="address" type="address" class="input-box" value="<?php echo $row['address']; ?>" required>
            <input id="number" name="number" type="number" class="input-box" value="<?php echo $row['number']; ?>" required>
            <input id="size-guest" name="size-guest" type="size-guest" class="input-box" value="<?php echo $row['guest']; ?>" required>
            <input id="float-length" name="float-length" type="float-length" class="input-box" value="<?php echo $row['length']; ?>" required>
            <input id="float-width" name="float-width" type="float-width" class="input-box" value="<?php echo $row['width']; ?>" required>
            <p class="quality">Quality accomodation from 0 to 5 :</p>
            <select name="review" id="review" class="scale-rating" multiple="multiple">
                <option value="-1" selected="selected">Επέλεξε</option>
                <option value="1">1</option>
                <option value="2">2</option>
                <option value="3">3</option>
                <option value="4">4</option>
                <option value="5">5</option>
            </select>
            <p class="activity">Τι εξοπλισμό διαθέτει η βίλα :</p>
            <hr>
            <ul class="list-activity">
                <li><input type="checkbox" name="pool" value="1"> Πισίνα</li>
                <li><input type="checkbox"name="sauna" value="1"> Σάουνα</li>
                <li><input type="checkbox"name="parking" value="1"> Πάρκινγκ</li>
                <li><input type="checkbox"name="gym" value="1"> Γυμναστήριο</li>
            </ul>
            <span id = "message" style="color:red"></span> 
            <?php echo_msg(); ?>
            <button type="submit" class="sign-btn">Upload accomodation  </button>
            
        </form>
    </div>
</body>

</html>
