# título del gráfico
set title "Tiempo en función del producto de ángulos por radios"
#tira el cuadro de referencias arriba a la izquierda
set key left top
#labels para X e Y
set xlabel "Ángulos por Radios"
set ylabel "Tiempo Transcurrido (seg)"
set term png size 1000,500
set output "lalala.png"

#variables
a = 0.13e-7
b = 0.11e-7
f(x) = a*(x**3)
g(x) = b*(x**3)
#plots
plot	"xaa" using 1:2 with points title "LU", \
		"xab" using 1:2 with points title "GAUSS", \
		f(x) with lines title "0.13e-7 * x³", \
		g(x) with lines title "0.11e-7 * x³"

pause -1
