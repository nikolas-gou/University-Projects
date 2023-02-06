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
    <link rel="icon" type="image/x-icon" href="../img/favicon_villa3.jpg">
</head>

<body>
    <div class="sign-up-form">
        <img src="../img/icon_villa3.jpg" style="height: 100px; display: block;margin-left: auto;margin-right: auto;">
        <h1>Upload your accomodation</h1>
        <form id="form" method="POST" action="../php/CheckUploadAccomodation.php">
            <input id="title" name="title" type="title" class="input-box" placeholder="Τίτλος- Title" required>
            <input id="prefecture" name ="prefecture" type="prefecture" class="input-box" placeholder="Νομός - Prefecture" required>
            <input id="address" name="address" type="address" class="input-box" placeholder="Διεύθυνση - Address" required>
            <input id="number" name="number" type="number" class="input-box" placeholder="Τηλέφωνο - Telephone" required>
            <input id="size-guest" name="size-guest" type="size-guest" class="input-box" placeholder="Άτομα - Guests" required>
            <input id="float-length" name="float-length" type="float-length" class="input-box" placeholder="float-length" required>
            <input id="float-width" name="float-width" type="float-width" class="input-box" placeholder="float-width" required>
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
