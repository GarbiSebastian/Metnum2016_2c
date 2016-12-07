function p = Biseccion( a, b, Y, C, tol, CantIt, x0, x1)
%
% x0 = punto inicial 
% a,b= parametros de ecuacion de la recta
% Y  = puntos en R^{3 x n} donde se ubican las rocas de kriptonita
% C  = cota del valor de aturdimiento 
% tol= valor de tolerancia
% CantIt = cantidad maxima de iteraciones 
%
% fcn es una funcion, invocar como p = Biseccion(@mifuncion, a, b, tol, maxiter)


%definicion de la funcion F a encontrar la raiz:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
F = @(x,a,b,Y,C) A(x,a,b,Y) - C ; %%%%%%%% COMPLETAR  %%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

iter = 1;


while iter <= CantIt,
    
   % calcular punto medio p entre a y b 
   p = x0 + (x1-x0)/2;
   
   fp = F(p,a,b,Y,C);
   
   if abs(fp) < tol || (x1-x0)/2 < tol,
       fprintf(1,'numero iteraciones: %d\n',iter);
       return;    
   end
   
   fprintf(1,'x(%d):%f f(x):%f |x(%d)-x(%d)|:%f\n',...
        iter, p, fp, iter, iter-1, abs(x0-p));

   if F(x0,a,b,Y,C) * F(p,a,b,Y,C) > 0,       
       x0 = p;       
   else       
       x1 = p;       
   end
   
   iter = iter + 1;
       
end

error('no se llego a la raiz luego de la cant max de iteraciones')