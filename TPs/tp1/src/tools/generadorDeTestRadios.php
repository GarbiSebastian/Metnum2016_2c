<?php

$angulos = 16;

/*
for($radios = 5; $radios <= 100; $radios+=5){
	$salida = "200 450 $radios $angulos 500 1\n";
	$salida.= str_repeat("1500 ",$angulos);
	$salida.= substr(str_repeat("0 ",$angulos),0,-1);
	file_put_contents("../tests/testsRadios/test_circulos_$radios.in", $salida);
}*/

$radios = 1000;
$salida = "200 450 $radios $angulos 500 1\n";
$salida.= str_repeat("1500 ",$angulos);
$salida.= substr(str_repeat("0 ",$angulos),0,-1);
file_put_contents("../tests/testsRadios/test_circulos_$radios.in", $salida);
