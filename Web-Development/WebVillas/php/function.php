<?php

// echo_msg(): τυπώνει πιθανό μήνυμα που έρχετε μέσω URL
// στην παράμετρο msg (άρα είναι στον πίνακα $_GET )
function echo_msg() {

  // η συνάρτηση προϋποθέτει ότι δεν θα έχουμε στείλει message
  // και με τους δύο τρόπους. 

  if (isset($_SESSION['msg'])) { 
    echo '<p style="color:red;">'.$_SESSION['msg'].'</p>';
    unset($_SESSION['msg']);
  } elseif (isset($_GET['msg'])) { 
    $sanitizedMsg= filter_var($_GET['msg'], FILTER_SANITIZE_STRING);
    echo '<p style="color:red;">'.$sanitizedMsg.'</p>';
  }
    
}
?>