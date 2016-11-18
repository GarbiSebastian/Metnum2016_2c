<?php
$salida ="";
for($radios = 5; $radios <= 100; $radios+=5){
	$salida.= "isoterma('../tests/testsRadios/test_circulos_$radios.in','../resultados/testsRadios/test_circulos_$radios.out','../resultados/testsRadios/test_circulos_$radios.isoterm');\n";
	//$salida.= "horno('../tests/testsRadios/test_circulos_$radios.in','../resultados/testsRadios/test_circulos_$radios.out','../resultados/testsRadios/test_circulos_$radios.isoterm','../graficos/testsRadios/');\n";
	echo "$radios\n";
}
file_put_contents("radios.m",$salida);