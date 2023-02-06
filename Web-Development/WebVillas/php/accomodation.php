<?php
     $db_dsn = 'mysql:dbname=db124752_thesisgate;host=127.0.0.1';
     $db_user ='root';
     $db_password = '';
     $instID = 1;
    try {
        $conn = new PDO($db_dsn, $db_user, $db_password);

        // set the PDO error mode to exception
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "SELECT * FROM departments";
        $stmt = $conn->prepare($sql); 
        // $stmt->execute(['id' => $id, 'title' => $title, 'prefecture' => $prefecture, 'address' => $address, 'number' => $number, 'guest' => $guest, 'length' => $length, 'width' => $width]);
        //$stmt->execute(['instID' => $instID]);
        //$record = $stmt -> fetchAll();

        while($row = $stmt -> fetch()) {
          echo($row['depName']);
      }
    

    }
    catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }

    // header('Location: ../php/ViewUpload.php?msg=Your accomodation Updated successfully!');
?>