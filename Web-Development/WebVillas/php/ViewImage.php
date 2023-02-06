<?php
    session_start();
    require("db_param.php");
    require("function.php");
    require("../js/part_nav.php");

    echo_msg();

    $fileArray= scandir('../img/UploadImage');                              
    //μέτρημα αρχείων (στοιχείων του πίνακα)
    $filesInFolder= count($fileArray);
    //αν θέλετε να δείτε τι επιστρέφει η scandir, βγάλτε τα επόμενα σχόλια
    //print_r($fileArray);
    if ( $filesInFolder>2 ) {
      for ($i=2; $i<=$filesInFolder-1;  $i++) {
        // αν δεν είναι φάκελος τυπωνουμε το όνομά του και links για delete-view
        if (!is_dir('..\img\Uploadimage/'.$fileArray[$i])) {
          // γραφή HTML ως ενιαίου string σε διπλά quotes, με εμβόλιμες
          // PHP μεταβλητές (που θα αντικατασταθούν από την τιμή τους)
          // Εδώ η HTML χρησιμοποιεί τα μονά quotes και η PHP τα διπλά.
          echo "<p><img style='vertical-align: middle;' src='..\img\Uploadimage/$fileArray[$i]' width='150' /> -
                [ <a href='DeleteImage.php?file=$fileArray[$i]'>Del</a> ]
                [ <a target='_blank' href='..\img\Uploadimage/$fileArray[$i]'>View</a> ]
                </p> ";
        }
      }

    } else {
      echo 'Δεν βρέθηκαν αρχεία!';
    }

    /*
        echo "<p><img style='vertical-align: middle;' src='..\img\Uploadimage/$fileArray[$i]' width='150' /> -
                   [ <a href='DeleteImage.php?file=$fileArray[$i]'>Del</a> ]
                   [ <a target='_blank' href='..\img\Uploadimage/$fileArray[$i]'>View</a> ]
               </p> ";

                echo "<img style='vertical-align: middle; margin-right: 20px; size: 8em;' src='..\img\Uploadimage/$fileArray[$i]' width='150' />
                ";
        }
      }
      echo "</br>";
      for ($i=2; $i<=$filesInFolder-1;  $i++) {
        if (!is_dir('..\img\Uploadimage/'.$fileArray[$i])) {
          echo "-  [ <a href='DeleteImage.php?file=$fileArray[$i]'>Del</a> ]
                   [ <a target='_blank' href='..\img\Uploadimage/$fileArray[$i]'>View</a> ]
                ";
        }
      }
    */
?>