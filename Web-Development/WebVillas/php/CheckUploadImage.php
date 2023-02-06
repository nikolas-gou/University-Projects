<?php
session_start();//  session star && connect
require("db_param.php");// db files for connection
require("function.php");// Mechanism printing error

$username = $_SESSION['username'];
$description = $_POST['description'];
$id = basename($_FILES["fileToUpload"]["name"]);
$flag = 0;

$target_dir = "C:\wamp64\www\Public2\img\UploadImage";


if(file_exists($target_dir . "\\" . $username))
  $flag = 1;
else if(mkdir($target_dir . "\\" . $username, 0777))
  $flag = 1;
else if(!file_exists($target_dir . "\\" . $username)) {
  $flag = 0;
  echo "Folder not created.. Try again!";
  echo  '<img src="../img/error2.jpg" style="height: 600px; display: block;margin-left: auto;margin-right: auto;width: 50%;"/>';
}

if($flag == 1) {
  $target_file = $target_dir . "\\" . $username . "/" . basename($_FILES["fileToUpload"]["name"]);
  $uploadOk = 1;
  $imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));

  // Check if image file is a actual image or fake image
  if(isset($_POST["submit"])) {
    $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
    if($check !== false) {
      echo "File is an image - " . $check["mime"] . ".";
      $uploadOk = 1;
    } else {
      echo "File is not an image.";
      $uploadOk = 0;
    }
  }

  // Check if file already exists
  if (file_exists($target_file)) {
    echo "Sorry, file already exists.";
    $uploadOk = 0;
  }

  // Check file size
  if ($_FILES["fileToUpload"]["size"] > 500000) {
    echo "Sorry, your file is too large.";
    $uploadOk = 0;
  }

  // Allow certain file formats
  if($imageFileType != "jpg" ) {
    echo "Sorry, only JPG files are allowed.";
    $uploadOk = 0;
  }

  // Check if $uploadOk is set to 0 by an error
  if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded.";
    echo  '<img src="../img/error2.jpg" style="height: 600px; display: block;margin-left: auto;margin-right: auto;width: 50%;"/>';
  // if everything is ok, try to upload file
  } else {
    if(move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
      try {
          $conn = new PDO($db_dsn, $db_user, $db_password);
          // set the PDO error mode to exception
          $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

          $sql = "INSERT INTO image (id, username, description) VALUES (:id, :username, :description)";
          $stmt = $conn->prepare($sql); 
          $stmt->execute(['id' => $id, 'username' => $username, 'description' => $description]);
          
      } catch(PDOException $e) {
          echo "Connection failed: " . $e->getMessage();
      }  
      //echo "The file ". htmlspecialchars( basename( $_FILES["fileToUpload"]["name"])). " has been uploaded.";
      $_SESSION['id_img'] = $id;
      header('Location: UploadAccomodation.php');
    } else {
      echo "Sorry, there was an error uploading your file.";
    }
  }
} else {
  echo "Folder not created.. Try again!";
  echo  '<img src="../img/error2.jpg" style="height: 600px; display: block;margin-left: auto;margin-right: auto;width: 50%;"/>';
}
?>
