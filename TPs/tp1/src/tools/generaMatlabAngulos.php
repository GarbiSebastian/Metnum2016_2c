<?php
$salida ="";
for($angulos = 8;$angulos <= 180; $angulos += 8){
	$salida.= "isoterma('../tests/testsAngulos/test_seno3Tita_$angulos.in','../resultados/testsAngulos/test_seno3Tita_$angulos.out','../resultados/testsAngulos/test_seno3Tita_$angulos.isoterm');\n";
	$salida.= "horno('../tests/testsAngulos/test_seno3Tita_$angulos.in','../resultados/testsAngulos/test_seno3Tita_$angulos.out','../resultados/testsAngulos/test_seno3Tita_$angulos.isoterm','../graficos/testsAngulos/');\n";
	echo "$angulos\n";
}
file_put_contents("angulos.m",$salida);