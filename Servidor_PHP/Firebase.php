<?php

$humedad = $_GET ['humedad'];
$temperatura = $_GET ['temperatura'];

//$data = '{"Temperatura":"27","Humedad":"15"}';
$data = '{"Temperatura":"'.$temperatura.'","Humedad":"'.$humedad.'"}';
$url = "https://zf-sachs-painting-room-default-rtdb.firebaseio.com/data.json";

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
    echo "Datos insertados";
}
?>