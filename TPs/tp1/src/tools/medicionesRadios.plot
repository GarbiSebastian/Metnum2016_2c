# título del gráfico
set title "Costo temporal/Posición de la isoterma 500ºC respecto a la cantidad de radios"

#tira el cuadro de referencias arriba a la izquierda
set key left top

#labels para X e Y
set xlabel "Cantidad de radios"
set ylabel "Tiempo Transcurrido (seg)"
set y2label "Posición de la isorerma (cm)"

#constantes
ancho=1000
alto=500

set y2tics

#salida grafica
set term png size ancho,alto
set output "../graficos/medicionesRadios.png"

set arrow 1 from 60,0 to 60,60 nohead linestyle 0
set arrow 2 from 0,10 to 100,10 nohead linestyle 0
set arrow 3 from 0,55 to 100,55 nohead linestyle 0
#plots
plot	"../../radiosConIsoterma.txt" using 1:2 with points axes x1y2 title "Posición de la Isoterma 500ºC", \
        "../../radiosConIsoterma.txt" using 1:3 with points axes x1y1 title "Tiempo transcurrido", \


#pause -1

