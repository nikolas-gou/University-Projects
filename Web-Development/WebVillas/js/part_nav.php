<?php
    //session_start();

    function getCSS() {  
        if ( !isset( $_COOKIE['css'] ) )
           $css='../css/home.css';
        else
          $css= $_COOKIE['css'];
        return $css;
      }
?>

<!DOCTYPE html>
<html lang='en'>
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-COMPATIBLE" content="IE=edge">
        <meta name="viewport" content="widtg=device-width, initial-scale=1.0">
        <title>Web Villas - Best Choice</title>

        <!--<link rel="stylesheet" href="../css/home.css">-->
        <link rel="stylesheet" href="<?php echo getCSS();?>">
        <!--<link rel="stylesheet" href="../css/footer.css">-->
        <style>
            .hello {
                color: #2984c8;
                padding-left: 20px;
            }
        </style>
    </head>

    <body>
        <nav class="navbar"></nav>
        <div class="nav">
        <a href="../js/index.php"><img src="../img/Logo2.jpg" class="brand-logo" alt=""></a>
            <div class="nav-items">
                <div class="search">
                    <form action="../php/ViewSearch2.php" method="post" class="search">
                        <input id="location" name="location" type="text" class="search-box" placeholder="search by City or Country">
                        <button type="submit" class="search-btn">Search</button>
                    </form>
                </div>
                <a href="../js/LogInFormValidation.php"><img src="../img/user.png" alt =""></a>
                <a href="#"><img src="../img/heart.png" alt =""></a>
                <!--coment moy-->
                <a href="../php/store.php?style=1"><img src="../img/light-mode.png"></a>
                <a href="../php/store.php?style=2"><img src="../img/night-mode.png"></a>
                
                <?php 
                    if(isset($_SESSION['active'])) 
                        if($_SESSION['active']) {
                            echo '<a href="../php/LogOut.php"><img src="../img/LogOut.png" alt=""></a>';
                            echo '<p class="hello">Hello ' . $_SESSION["username"] . '</p>';
                        }
                ?>
            </div>
        </div>
        <ul class="links-container">
            <li class="link-item"> <a href="../js/index.php" class="link">Home</a></li>
            <!-- dokimes gia sundesi db apo thesisgate -->
            <li class="link-item"> <a href="../php/accomodation.php" class="link">Accomodation</a></li>
            <li class="link-item"> <a href="#" class="link">Bookings</a></li>
            <li class="link-item"> <a href="../php/ViewImage2.php?n=1" class="link">Gallery</a></li>
            <?php 
                    if(isset($_SESSION['active'])) 
                        if($_SESSION['active'])
                            echo '<li class="link-item"> <a href="../php/show_upload.php" class="link">Your Uploads</a></li>';
            ?>
            
        </ul>