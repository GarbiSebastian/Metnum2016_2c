function dA = derA(t,a,b,y)
%   function y = A(t,a,b,x)
%
% t: valor en el rengo [0,1]
% a: vector en R^3x1
% b: vector en R^3x1
% y: matriz de tamanio 3xN que representa N valores en R^3 (en cada col)
%    (N vectores correspondientes a la kriptonita)

da = zeros(1, size(y,2));

for i = 1 : size(y,2),
    da(i) = derM_i(t,a,b,y(:,i)) / M_i(t,a,b,y(:,i))^(3/2);
end

dA = -0.5 * sum(da);


function y = M_i(t,a,b,x)

    ft_x = a * t + b - x;
    y = ft_x' * ft_x;


function dM = derM_i(t,a,b,x)

    ft = a * t + b ;
    dM = 2 * ( a' * (ft - x) );


