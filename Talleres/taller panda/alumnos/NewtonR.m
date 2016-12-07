function x = NewtonR (a, b, Y, C, tol, CantIt, x0)
%
% x0 = punto inicial 
% a,b= parametros de ecuacion de la recta
% Y  = puntos en R^{3 x n} donde se ubican las rocas de kriptonita
% C  = cota del valor de aturdimiento 
% tol= valor de tolerancia
% CantIt = cantidad maxima de iteraciones 
%


%definicion de la funcion F a encontrar la raiz:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
F = @(x,a,b,Y,C)  C - A(x,a,b,Y)  ;%%%%%%%% COMPLETAR  %%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

x_ant = x0;
indit = 0;

fprintf(1,'x(%d):%f f(x):%f\n', indit, x0, F(x0,a,b,Y,C) );


while abs(F(x_ant,a,b,Y,C)) > tol && indit < CantIt,
    
    x = x_ant -  F(x_ant,a,b,Y,C) / derF(x_ant,a,b,Y,C);

    indit = indit+1;
    
    fprintf(1,'x(%d):%f f(x):%f x(%d)-x(%d):%f\n',...
        indit, x, F(x,a,b,Y,C), indit, indit-1, x-x_ant);

    x_ant = x;

end


fprintf(1,'numero iteraciones: %d\n',indit);

