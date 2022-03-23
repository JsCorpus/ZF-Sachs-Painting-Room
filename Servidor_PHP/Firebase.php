<?php
$humedad = $_GET ['humedad'];
$temperatura = $_GET ['temperatura'];
$tempid =  $_GET ['tempid'];
$humid = $_GET ['humid'];
$tim = $_GET ['tim'];
$timer = $_GET ['timer'];
$at = $_GET ['at'];
$bh = $_GET ['bh'];
$E1 = $_GET ['E1'];
$E2 = $_GET ['E2'];

$data = '{"Temperatura":"'.$temperatura.'","Humedad":"'.$humedad.'","tempid":"'.$tempid.'","humid":"'.$humid.'","tim":"'.$tim.'","timer":"'.$timer.'","at":"'.$at.'","bh":"'.$bh.'","E1":"'.$E1.'","E2":"'.$E2.'"}';
$url = "https://zf-sachs-painting-room-default-rtdb.firebaseio.com/data/last_data.json";

$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_POST, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: text/plain'));
curl_setopt( $ch, CURLOPT_CUSTOMREQUEST, "PATCH" );

$response = curl_exec($ch);
if( curl_errno($ch)){
    echo 'Error: '.curl_errno($ch);
}else{
    echo "Último registro actualizado";
}
?>

<?php
$humedad = $_GET ['humedad'];
$temperatura = $_GET ['temperatura'];
$tempid =  $_GET ['tempid'];
$humid = $_GET ['humid'];
$tim = $_GET ['tim'];
$timer = $_GET ['timer'];
$at = $_GET ['at'];
$bh = $_GET ['bh'];
$E1 = $_GET ['E1'];
$E2 = $_GET ['E2'];

$data = '{"Temperatura":"'.$temperatura.'","Humedad":"'.$humedad.'","tempid":"'.$tempid.'","humid":"'.$humid.'","tim":"'.$tim.'","timer":"'.$timer.'","at":"'.$at.'","bh":"'.$bh.'","E1":"'.$E1.'","E2":"'.$E2.'"}';
$url = "https://zf-sachs-painting-room-default-rtdb.firebaseio.com/log.json";

$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_POST, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: text/plain'));

$response = curl_exec($ch);
if( curl_errno($ch)){
    echo 'Error: '.curl_errno($ch);
}else{
    echo "</br>Nuevo registro en guardado en Log";
}
?>



