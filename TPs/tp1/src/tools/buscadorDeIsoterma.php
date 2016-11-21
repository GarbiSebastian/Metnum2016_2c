<?php

$isotermas =[];
$mediciones = file_get_contents("../../medicionesRadios.txt");
$mediciones = explode("\n",$mediciones);
$tiempos = [];
for ($med=0; $med < count($mediciones); $med++) { 
	$valores = explode(" ", $mediciones[$med]);
	if(count($valores)>2){
		$tiempos[$valores[0]] = $valores[2];
	}
}

for($radios=5;$radios<=100;$radios+=5){
	$archivoIsoterma = fopen("../resultados/testsRadios/test_circulos_$radios.isoterm","r");
	$valor = stream_get_line($archivoIsoterma,100," \n");
	$isotermas[$radios]=$valor;
}

/*
var_export($mediciones);
var_export($tiempos);
var_export($isotermas);
*/
$salida = "";
for($radios=5;$radios<=100;$radios+=5){
	$salida.="$radios {$isotermas[$radios]} {$tiempos[$radios]}\n";
}
file_put_contents("../../radiosConIsoterma.txt",$salida);