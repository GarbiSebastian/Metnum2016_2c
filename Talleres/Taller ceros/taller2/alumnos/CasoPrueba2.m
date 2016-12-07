%% --------- CASO PRUEBA 2 ------------------

close all  %cierra todas las ventanas
clear all  %elimina variables del entorno
format long

%% CASO 2

%parametros de la recta
a = [1;2;3];
b = [1;1;1];

% coordenadas de las piedras
y=[       0.8          1.1          0.9;...
            1          0.6            1;...
          1.5          2.1          0.7;...
          2.3          2.1          1.5;...
          0.9          1.3          2.2;...
          1.5            2          2.2;...
          1.1          2.4          2.6;...
          1.6          1.9          2.5;...
          2.5          2.4          2.3;...
          2.9          2.5          2.9;...
          1.3          1.8          2.1;...
          1.5          1.9          3.4;...
          1.6          3.4            4;...
          1.9          2.5            4;...
          1.3            3          3.2;...
          1.6          2.4          4.1;...
          1.8          3.2          3.8]';

C=23;

%%
graficador(y,a,b)






%% NEWTON
x0 = 0.6; 
%tol = 0.00000001; 
tol = 0.000001;
maxnumit = 40;

xfinal = NewtonR(a, b, y, C, tol, maxnumit, x0);


%% BISECCION
x0 = 0.4; 
x11 = 0.9; 
tol = 0.000001;
maxnumit = 40;

p = Biseccion(a, b, y, C, tol, maxnumit, x0, x11);
