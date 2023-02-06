
<?php
  session_start();
  $username = $_REQUEST["username"];
  require('db_param.php');// include data for db connection.. ps. localhost, username...

  //Data base connection
  try {
      $conn = new PDO($db_dsn, $db_user, $db_password);

      // set the PDO error mode to exception
      $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

      $sql = "SELECT username FROM registration";
      $stmt = $conn->prepare($sql); 
      $stmt->execute(['username' => $username]);
      $row = $stmt->fetchALL();

      foreach($row as $rs) {
          if($rs['username'] == $username) {
              $flag = 1;
              echo "Username is unvailable.. Please choose another one..";
              }     
          }
        } catch(PDOException $e) {
          echo "Connection failed: " . $e->getMessage();
      } 
?> 