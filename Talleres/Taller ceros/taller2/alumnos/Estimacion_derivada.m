function der = Estimacion_derivada(F, x)

h = sqrt(eps)*x;
xph = x + h;
dx = xph - x;
der = (F(xph) - F(x)) ./ dx;