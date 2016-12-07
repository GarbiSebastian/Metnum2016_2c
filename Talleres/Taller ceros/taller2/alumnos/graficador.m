function graficador(y,a,b)
% Dados los puntos y=[y_1,y_2,...,y_n] en R^{3 x n} y los paramentros de la
% recta a*t+b, se grafica la trayectoria h(t) de Superman y 
% la funcion A(t) que indica el nivel de aturdimiento

figure;

t = 0 : 0.01 : 1;

% ---- grafico de trayectoria y kriptonita
subplot(1,2,1)
plot3([b(1);a(1)+b(1)],[b(2);a(2)+b(2)],[b(3);a(3)+b(3)]) %segmento
xlabel('X');ylabel('Y');zlabel('Z');
grid on,  hold on
plot3(y(1,:)',y(2,:)',y(3,:)','.g','MarkerSize',24); % kriptonita (verde)

% ---- grafico de nivel de aturdimiento A(t)
subplot(1,2,2)
plot(t, A(t,a,b,y))
xlabel('t');ylabel('Nivel de aturdimiento A(t)')
hold on




for indt = 1 : length(t),
    
    % Grafico izquierda: trayectoria de Superman (rojo)
    subplot(1,2,1)
    plot3(a(1)*t(indt)+b(1),a(2)*t(indt)+b(2),a(3)*t(indt)+b(3),'.-r')

    % Grafico derecha: Funcion de aturdimiento A(t)
    subplot(1,2,2)
    plot(t(indt), A(t(indt), a, b, y),'.r')
    
    pause(0.2);
end


 
%        **************************
%     .*##*:*####***:::**###*:######*.
%    *##: .###*            *######:,##*
%  *##:  :####:             *####*.  :##:
%   *##,:########**********:,       :##:
%    .#########################*,  *#*
%      *#########################*##:
%        *##,        ..,,::**#####:
%         ,##*,*****,        *##*
%           *#########*########:
%             *##*:*******###*
%              .##*.    ,##*
%                :##*  *##,
%                  *####:
%                    :,