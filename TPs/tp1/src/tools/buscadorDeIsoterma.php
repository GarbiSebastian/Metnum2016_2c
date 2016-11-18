<?php

$isotermas =[];
$mediciones = file_get_contents("../../mediciones radios.txt");
$mediciones = explode("\n",$mediciones);
$tiempos = [];
for ($med=0; $med < floor(count($mediciones)/2); $med++) { 
	$valores = explode(" ", $mediciones[2*$med+1]);
	$tiempos[$mediciones[2*$med]] = $valores[1];
}

for($radios=5;$radios<=100;$radios+=5){
	$archivoIsoterma = fopen("../resultados/testsRadios/test_circulos_$radios.isoterm","r");
	$valor = stream_get_line($archivoIsoterma,100," \n");
	$isotermas[$radios]=$valor;
}

var_export($tiempos);
var_export($isotermas);
