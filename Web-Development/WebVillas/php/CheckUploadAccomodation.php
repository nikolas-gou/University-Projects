<?php
    session_start();
    require("db_param.php");
    $id_img = $_SESSION['id_img'];
    $username = $_SESSION['username'];
    $title = $_POST['title'];
    $prefecture = $_POST['prefecture'];
    $address = $_POST['address'];
    $number = $_POST['number'];
    $guest = $_POST['size-guest'];
    $length = $_POST['float-length'];
    $width = $_POST['float-width'];
    $review = filter_input(INPUT_POST, 'review', FILTER_SANITIZE_STRING);
    if(isset($_POST['pool'])) 
        $pool = 1;
    else
        $pool = 0;  
    if(isset($_POST['sauna'])) 
        $sauna = 1;
    else
        $sauna = 0; 
    if(isset($_POST['parking'])) 
        $parking = 1;
    else
        $parking = 0; 
    if(isset($_POST['gym'])) 
        $gym = 1;
    else
        $gym = 0;   

    try {
        $conn = new PDO($db_dsn, $db_user, $db_password);

        // set the PDO error mode to exception
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "INSERT INTO accomodation (username, title, prefecture, address, number, guest, length, width, review, pool, sauna, parking, gym, id_img) 
            VALUES (:username, :title, :prefecture, :address, :number, :guest, :length, :width, :review, :pool, :sauna, :parking, :gym, :id_img) ";
        $stmt = $conn->prepare($sql); 
        $stmt->execute(['username' => $username, 'title' => $title, 'prefecture' => $prefecture,'address' =>$address, 'number' => $number, 'guest' => $guest, 'length' => $length, 'width' => $width, 'review' => $review, 'pool' => $pool, 'sauna' => $sauna, 'parking' => $parking, 'gym' => $gym, 'id_img' => $id_img]);

    }
    catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }
    
    header('Location: ../js/index.php');
?>