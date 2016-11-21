function z = A(t,a,b,y)
%
%   function z = A(t,a,b,y)
%
% Funcion de aturdimiento sum_i (1 / ||a*t + b - y_i||)
% t: valor (o vector de Mx1 de valores) en el rango [0,1]
% a: vector en R^3x1 (parametro de la recta)
% b: vector en R^3x1 (parametro de la recta)
% x: matriz de tamanio 3xN que representa N valores en R^3 (en cada col)
% C: cota del nivel de aturdimiento
% z: se retorna el valor de la funcion que indica el nivel de aturdimiento.
% (si t es un vector, entonces y es un vector de la misma dimension)

z =  zeros(size(t));

for k = 1 : numel(t),
    
    ft = a * t(k) + b;
    resta = repmat(ft,1,size(y,2)) - y;
    norm2 = sqrt(sum(resta.*resta,1));
    z(k) = sum(1./norm2);

end

