<?php
    session_start();
    require("db_param.php");
    require("function.php");
?>

<!DOCTYPE html>
<html>
    <head>
        <title>ViewSearch Gallery</title>
        <style>
            * {
                box-sizing: border-box;
            }
            body {
                margin: 0px;
                background: #2984c8;
            }
            
            div.nav {
                background: white;
            }

            ul.links-container {
                background: #f5f5f5;
            }

            .container {
                max-width: 1200px;
                margin: auto;
                margin-top: 60px;
                background: #f2f2f2;
                overflow: auto;
            }


            .gallery {
                margin: 5px;
                border: 1px solid #ccc; 
                float: left;
                width: 390px;

            }

            .gallery img {
                width: 100%;
                height: auto;
            }

            .desc {
                padding: 15px;
                text-align: center;

            }
            img.favourite {
                width: 7%;
                display: block;
                float: right;
                margin-right: 10px;
                margin-bottom: 10px;
            }
            div.pagination {
                margin-left: 500px;
                margin-top: 0px;
            }
            .pagination a {
                color: black;
                float: left;
                padding: 8px 16px;
                text-decoration: none;
                transition: background-color .3s;
                margin-top: 10px;
                margin-bottom: 10px;
            }

            .pagination a.active {
            background-color: dodgerblue;
            color: white;
            }

            .pagination a:hover:not(.active) {background-color: #ddd;}
            </style>
    </head>
    <body>
        <?php 
            require("../js/part_nav.php");
        ?>
        <div class="container"> 
            <?php
                echo_msg();
                $fileArray= scandir('../img/UploadImage');  
                $i = 1;
                $username = $_SESSION['username'];
            
                if(isset($_GET['n'])) 
                    $k = 4 * $_GET['n'];                            
                else 
                    $k = 4;
                if(!isset($_GET['n']))
                    $_GET['n'] = 1;

                $filesInFolder= count($fileArray);
                
                if ( $filesInFolder>2 ) {
                    try {
                        $conn = new PDO($db_dsn, $db_user, $db_password);
                        // set the PDO error mode to exception
                        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                        $sql = "SELECT * FROM image WHERE username=:username";
                        $stmt = $conn->prepare($sql);  
                        $stmt -> execute(['username' => $username]); 
                        $row = $stmt->fetchALL();
                    } catch(PDOException $e) {
                        echo "Connection failed: " . $e->getMessage();
                    }  

                    foreach($row as $record) {    
                        $id = $record['id'];
                        $i++;
                        // αν δεν είναι φάκελος τυπωνουμε το όνομά του και links για delete-view
                        if (!is_dir('..\img\Uploadimage/'.$fileArray[$i]) && $i <= $k && $i > (4 * ($_GET['n'] - 1))) {
                            $url='..\img\Uploadimage/'.$record['id'];
                            echo "<div class='gallery'> 
                                    <img src=$url>
                                        <div class='desc'>$id</div>
                                        <a href='../js/LogInFormValidation.php'><img  class='favourite' src='../img/heart.png' alt =''></a>
                                    </div>";
                        }
                    }
                    } else {
                        echo 'Δεν βρέθηκαν αρχεία!';
                    }
                ?>
            <?php   
                echo '<div class="pagination">
                        <a href="#">&laquo;</a>';
                for($i=2; $i <= ($filesInFolder / 3) + 1; $i++) {
                    if($i-1 == $_GET['n'])
                        echo '<a class="active" href="Viewimage2.php?n=' . ($i-1) . '">' . ($i-1) .'</a>';
                    else 
                        echo '<a href="ViewUpload2.php?n=' . ($i-1) .'">'  . ($i-1) .'</a>';
                }
                echo '<a href="#">&raquo;</a></div>';
            ?>
        </div>
    </body>
</html>
