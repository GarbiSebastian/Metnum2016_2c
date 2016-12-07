F = @(x,a,b,Y,C)  C - A(x,a,b,Y);

t = 0 : 0.01 : 1;
a = [3;1;0];
b = [1;1;0];

Y = [ [2;3;0] , [2;0.5;0] ];  
C = 1.8;

G = @(x_ant)  x_ant -  F(x_ant,a,b,Y,C) / derF(x_ant,a,b,Y,C);

z = zeros(size(t))
for indt = 1 : length(t),
    z(indt) = G(t(indt))
end

plot(t, z)
hold on
plot(t, t)
hold on

x1 = 0.210;
x2 = 0.215;

line([x1 x1], [x1 x2])
line([x2 x2], [x1 x2])
line([x1 x2], [x1 x1])
line([x1 x2], [x2 x2])