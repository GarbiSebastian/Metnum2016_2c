# título del gráfico
set title "Horno en coordenadas polares"
#tira el cuadro de referencias arriba a la izquierda
#set key left top
#labels para X e Y
#set xlabel "Ángulos (grados)"
#set ylabel "Radios (cm)"

#set term png size 1000,700
#set output "banana.png"

set polar
set angles degrees
set xzeroaxis
set yzeroaxis
set zzeroaxis

#rangos 
set trange [0:360]
#set yrange [175:500]


#constantes
a = 20
b = 400

f(x) = sin(8*x)*a+b
g(t) = sin(t)+b

interna(x)=200
externa(x)=450
peligro(x)=400
senoloco(x)=5

#plots

plot    200 with lines title "Pared interna", \
		400 with lines title "Límite peligroso", \
		450 with lines title "Pared externa", \
		g(t) with lines title "blah"
#plot	g(t,200) with lines title "Pared interna", \
#		g(t,450) with lines title "Pared externa"
		#externa(x) with lines title "Pared externa", \
		#peligro(x) with lines title "Límite peligroso"


#set clip points
#set bar 1.000000 front
#unset border
#set style circle radius graph 0.02, first 0.00000, 0.00000 
#set style ellipse size graph 0.05, 0.03, first 0.00000 angle 0 units xy
#set dummy t, y
#set style textbox transparent margins  1.0,  1.0 border
#unset logscale
#set polar
#set angles degrees
#set samples 160, 160
#set style data lines
#set xzeroaxis
#set yzeroaxis
#set zzeroaxis
#set xtics axis in scale 1,0.5 nomirror norotate  autojustify
#set ytics axis in scale 1,0.5 nomirror norotate  autojustify
#unset rtics
#set title "Three circles (with aspect ratio distortion)" 
#set trange [ 0 : 360 ] noreverse nowriteback
#set colorbox vertical origin screen 0.9, 0.2, 0 size screen 0.05, 0.6, 0 front bdefault




pause -1