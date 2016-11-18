<?php

for($angulos = 8;$angulos<=180;$angulos+=8){
	$comando = "../tp ../tests/testsAngulos/test_seno3Tita_$angulos.in ../resultados/testsAngulos/test_seno3Tita_$angulos.out 0";
	echo "$angulos\n";
	echo shell_exec($comando);
}

