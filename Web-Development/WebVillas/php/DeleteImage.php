<?php
    session_start();
    require("db_param.php");
    require("function.php"); 

    
  if ( !isset( $_GET['file']) || $_GET['file']=='' ) {
    header('Location: ViewImage.php?msg=ERROR: Ανεπαρκή δεδομένα για διαγραφή!');
    exit();
  }

  //ο φάκελος στον server στον οποίο βρίσκεται το αρχείο (σε σχέση με τη σελίδα!)
  $filePath='..\img\Uploadimage/';
  //αν δεν υπάρχει το αρχείο έχουμε πρόβλημα
  if ( !file_exists($filePath.$_GET['file']) ) {
    header('Location: ViewImage.php?msg=ERROR: Δεν υπάρχει τέτοιο αρχείο στον φάκελο!');
    exit();
  }

  //Απόπειρα διαγραφής και επιτροφη στη home με το αποτέλεσμα!
  //Η unlink() επιστρέφει false αν δεν μπορέσει να διαγράψει το αρχείο.
  //Στην unlink πρέπει να βάλετε παράμετρο το προς διαγραφή αρχείο. Χρσιμοποιήστε
  //σχετική διεύθυνση (path) ως προς τον φάκελο του παρόντος αρχείου!!!
  $fileDelResult=unlink($filePath.$_GET['file']);
  if ($fileDelResult==true) {
    try {
        $conn = new PDO($db_dsn, $db_user, $db_password);
        // set the PDO error mode to exception
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $sql = "DELETE FROM image WHERE id=:id";
        $stmt = $conn->prepare($sql); 
        $stmt->execute(['id' => $_GET['file']]);
        
    } catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
    }  
    $msg= 'Έγινε διαγραφή';
  }
  else
    $msg= 'ERROR: Το αρχείο δεν διαγράφηκε!';
  header('Location: ViewImage.php?msg='.$msg);
  exit();
?>

?>