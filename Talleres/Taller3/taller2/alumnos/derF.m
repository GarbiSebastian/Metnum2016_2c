function dF = derF(t,a,b,Y,C)
%   function y = (t,a,b,x)
%
% t: valor en el rango [0,1]
% a: vector en R^3x1 (parametro de la recta)
% b: vector en R^3x1 (parametro de la recta)
% C: constante del nivel de aturdimiento
% Y: matriz de tamanio 3xN que representa N valores en R^3 (en cada col)

dF = ...