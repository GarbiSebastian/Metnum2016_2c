close all;
clear all;
x_nr = [0.600000 0.371934 0.299572 0.398220 0.417559 0.487227 0.529541 0.501510 0.503417 0.503349];
x_b = [0.650000 0.525000 0.462500 0.493750 0.509375 0.501563 0.505469 0.503516 0.502539 0.503027 0.503271 0.503394 0.503333 0.503363 0.503348 0.503355 0.503352 0.503350]

r = 0.503350;
e_nr = abs(x_nr - ones(size(x_nr))*r)
e_b = abs(x_b - ones(size(x_b))*r)

i_nr = 1:1:size(x_nr,2);
i_b = 1:1:size(x_b,2);


figure1 = figure;

% Create axes
axes1 = axes('Parent',figure1,'YScale','log');
box(axes1,'on');
hold(axes1,'on');

% Create semilogy
semilogy(i_nr,e_nr,'DisplayName','Método Newton-Raphson','Marker','diamond');

% Create semilogy
semilogy(i_b,e_b,'DisplayName','Método Bisección','Marker','^');

% Create xlabel
xlabel('Itetación');

% Create ylabel
ylabel('Error (logscale)');

% Create legend
legend(axes1,'show');