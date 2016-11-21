%% --------- CASO PRUEBA 1 ------------------

close all  %cierra todas las ventanas
clear variables  %elimina variables del entorno

%% CASO 1

%parametros de la recta
a = [3;1;0];
b = [1;1;0];

%y = [2;3;0];                     %ejemplo con 1 roca
y = [ [2;3;0] , [2;0.5;0] ];   %ejemplo con 2 rocas

%%
graficador(y,a,b)


% %% NEWTON
% 
% x0 = 0.9; 
% tol = 0.000001; 
% maxnumit = 40;
% 
% xfinal = NewtonR(a, b, y, C, tol, maxnumit, x0);
% 
% %% BISECCION
% 
% x0 = 0.45; 
% x1 = 1;
% tol = 0.000001; 
% maxnumit = 40;
% 
% xfinal = Biseccion(a, b, y, C, tol, maxnumit, x0, x1);

