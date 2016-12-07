<?php

function senoXTita($tita,$x=8,$a=200,$b=200){
	return sin($x*$tita)*$a + $b;
}

$dosPI = 2*M_PI;

/*for($angulos = 8; $angulos <= 180; $angulos+=8){
	$salida = "200 450 15 $angulos 500 1\n";
	$salida.= str_repeat("1500 ",$angulos);
	$valoresExternos=[];
	$dosPiDivAng = $dosPI/$angulos;
	for($actual = 0; $actual < $angulos; $actual++){
		$valoresExternos[]= senoXTita($actual*$dosPiDivAng,8,200);
	}
	$salida.=implode(" ", $valoresExternos);
	file_put_contents("../tests/testsAngulos/test_seno3Tita_$angulos.in", $salida);
}*/

$angulos=32;
$salida = "200 450 40 $angulos 500 1\n";
$salida.= str_repeat("1500 ",$angulos);
$valoresExternos=[];
$dosPiDivAng = $dosPI/$angulos;
for($actual = 0; $actual < $angulos; $actual++){
	$valoresExternos[]= senoXTita($actual*$dosPiDivAng,8,75,125);
}
$salida.=implode(" ", $valoresExternos);
file_put_contents("../tests/test_50a200_$angulos.in", $salida);
