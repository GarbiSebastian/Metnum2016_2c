# título del gráfico
set title "Horno en coordenadas polares"
#tira el cuadro de referencias arriba a la izquierda
set key left top
#labels para X e Y
set xlabel "Ángulos (grados)"
set ylabel "Radios (cm)"

set term png size 1000,700
set output "banana.png"

set angles degrees;
#rangos 
set xrange [0:360]
set yrange [175:500]


#constantes
a = 20
b = 400

f(x) = sin(8*x)*a+b

interna(x)=200
externa(x)=450
peligro(x)=400
senoloco(x)=5

#plots
#plot	"../resultados/50_200.txt" using 2:3 with lines title "Isoterma 500ºC", \
#        interna(x) with lines title "Pared interna", \
#		externa(x) with lines title "Pared externa", \
#		peligro(x) with lines title "Límite peligroso"

#plot	"../resultados/50_200.txt" using 2:4 with lines title "Isoterma 500ºC", \
#        interna(x) with lines title "Pared interna", \
#		externa(x) with lines title "Pared externa", \
#		peligro(x) with lines title "Límite peligroso"

plot	"../resultados/60x64.txt" using 2:3 with lines title "Isoterma 500ºC", \
        interna(x) with lines title "Pared interna", \
		externa(x) with lines title "Pared externa", \
		peligro(x) with lines title "Límite peligroso"


pause -1