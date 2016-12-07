F = @(x,a,b,Y,C) A(x,a,b,Y) - C;
%t = 0:0.01:1;
t = 0.2 : 0.001 : 0.22;
a = [3;1;0];
b = [1;1;0];
Y = [ [2;3;0] , [2;0.5;0] ];  

C = 1.8;
G = @(x_ant)  x_ant -  F(x_ant,a,b,Y,C) / derF(x_ant,a,b,Y,C);
n= size(t,2);

z=zeros(n,1);

for i=1:n
    z(i) = G(t(i));
end 

figure1 = figure;

% Create axes
axes1 = axes('Parent',figure1);
box(axes1,'on');
hold(axes1,'on');

% Create multiple lines using matrix input to plot
plot1= plot(t, z);
set(plot1(1),'DisplayName','Método Newton-Raphson');
plot2= plot(t, t);
set(plot2(1),'DisplayName','Recta x=y');
% Create xlabel
xlabel('t');

% Create ylabel
ylabel('G(t)');

% Create legend
legend(axes1,'show');
