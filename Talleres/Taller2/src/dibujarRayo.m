function dibujarRayo(f_ini, c_ini, f_fin, c_fin)
%DIBUJARRAYO Dibuja un rayo desde (f_ini, c_ini) hasta (f_fin, c_fin) 
%   sobre la imagen activa
    
    plot([c_ini, c_fin], [f_ini, f_fin], 'Color', 'r', 'LineStyle', '-', 'LineWidth',1.5);

end

