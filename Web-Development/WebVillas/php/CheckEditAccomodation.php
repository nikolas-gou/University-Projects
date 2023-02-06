<?php
    session_start();
    require("db_param.php");
    $id = $_GET['id'];

    $title = $_POST['title'];
    $prefecture = $_POST['prefecture'];
    $address = $_POST['address'];
    $number = $_POST['number'];
    $guest = $_POST['size-guest'];
    $length = $_POST['float-length'];
    $width = $_POST['float-width'];
    $review = filter_input(INPUT_POST, 'review', FILTER_SANITIZE_STRING);
     

    try {
        $conn = new PDO($db_dsn, $db_user, $db_password);

        // set the PDO error mode to exception
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "UPDATE accomodation
                SET title=:title, prefecture=:prefecture, address=:address, number=:number, guest=:guest, length=:length, width=:width 
                WHERE id=:id";
        $stmt = $conn->prepare($sql); 
        $stmt->execute(['id' => $id, 'title' => $title, 'prefecture' => $prefecture, 'address' => $address, 'number' => $number, 'guest' => $guest, 'length' => $length, 'width' => $width]);

    }
    catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }

    header('Location: ../php/ViewUpload.php?msg=Your accomodation Updated successfully!');
?>