<?php  
$status = $_GET['status'];
if($status == "green") {  
  $file = fopen("status.json", "w") or die("can't open file");
  fwrite($file, '{"status": "green"}');
  fclose($file);
} 
else if ($status == "red") {  
  $file = fopen("status.json", "w") or die("can't open file");
  fwrite($file, '{"status": "red"}');
  fclose($file);
}
?>

<html>  
  <head>      
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Avid Cloud Platform Status</title>

    <script src="https://code.jquery.com/jquery-2.1.4.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/js/bootstrap.min.js"></script>
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">

  </head>
  <body>
    <div class="row" style="margin-top: 20px;">
      <div class="col-md-8 col-md-offset-2">
        <a href="?status=green" class="btn btn-success btn-block btn-lg">Avid Cloud Platform Status Green</a>
        <br />
        <a href="?status=red" class="led btn btn-danger btn-block btn-lg">Avid Cloud Platform Status Red</a>
        <br />
        <div class="status-status well" style="margin-top: 5px; text-align:center">
          <?php
            if($status=="green") {
              echo("Make it Green");
            }
            else if ($status=="red") {
              echo("See Red");
            }
            else {
              echo ("Do something.");
            }
          ?>
        </div>
      </div>
    </div>
  </body>
</html>
