<?php
$angulos = 16;

for($radios = 5; $radios <= 100; $radios+=5){
	$comando = "../tp ../tests/testsRadios/test_circulos_$radios.in ../resultados/testsRadios/test_circulos_$radios.out 0";
	echo "$radios\n";
	echo shell_exec($comando);
}

