
<!DOCTYPE html>
<html lang='en'>
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-COMPATIBLE" content="IE=edge">
        <meta name="viewport" content="widtg=device-width, initial-scale=1.0">
        <title>Web Villas - Best Choice</title>

        <link rel="stylesheet" href="../css/ViewSearch2.css">

        <script type="text/javascript">
            function myFunction(imgs) {
                // Get the expanded image
                var expandImg = document.getElementById("expandedImg");
                // Get the image text
                var imgText = document.getElementById("imgtext");
                // Use the same src in the expanded image as the image being clicked on from the grid
                expandImg.src = imgs.src;
                // Use the value of the alt attribute of the clickable image as text inside the expanded image
                imgText.innerHTML = imgs.alt;
                // Show the container element (hidden with CSS)
                expandImg.parentElement.style.display = "block";
            } 
        </script>
    </head>

    <body>
        <!-- The grid: four columns -->
        <div class="row">
        <div class="column1">
            <img src="../img/headervila1.1.png" alt="Nature" onclick="myFunction(this);">
            <img src="../img/headervila1.1.png" alt="Snow" onclick="myFunction(this);">
            <img src="../img/headervila1.1.png" alt="Snow" onclick="myFunction(this);">
        </div>
        <div class="column2">
            <img src="../img/headervila1.1.png" alt="Snow" onclick="myFunction(this);">
        </div>
        <div class="column3">
            <img src="../img/headervila1.1.png" alt="Mountains" onclick="myFunction(this);">
        </div>
        <div class="column4">
            <img src="../img/headervila1.1.png" alt="Lights" onclick="myFunction(this);">
        </div>
        </div>

        <!-- The expanding image container -->
        <div class="container">
        <!-- Close the image -->
        <span onclick="this.parentElement.style.display='none'" class="closebtn">&times;</span>

        <!-- Expanded image -->
        <img id="expandedImg" style="width:100%">

        <!-- Image text -->
        <div id="imgtext"></div>
        </div> 
        </body>
</html>
