# título del gráfico
set title "Costo temporal respecto a la cantidad de ángulos"

#tira el cuadro de referencias arriba a la izquierda
set key left top

#labels para X e Y
set xlabel "Cantidad de ángulos"
set ylabel "Tiempo Transcurrido (seg)"

#constantes
a=0.45e-4 #a = 0.000045
b=0.40e-4 #b = 0.00004
ancho=1000
alto=500

#funciones
f(x) = a*(x**3)
g(x) = b*(x**3)

#salida grafica
set term svg size ancho,alto
set output "../graficos/medicionesAngulos.svg"

#plots
plot	"../../medicionesAngulos.txt" using 1:3 with points title "Mediciones", \
		f(x) with lines title "0.45e-4 * x³", \
		g(x) with lines title "0.40e-4 * x³"

set term png size ancho,alto
set output "../graficos/medicionesAngulos.png"
plot	"../../medicionesAngulos.txt" using 1:3 with points title "Mediciones", \
		f(x) with lines title "0.45e-4 * x³", \
		g(x) with lines title "0.40e-4 * x³"

