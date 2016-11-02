function R = generarRayos(arch_img, n, m, k, arch_ray)
%GENERARRAYOS Genera un archivo con datos de rayos aleatorios sobre una
%imagen
%   R = generarRayos(arch_img, n, m, k, arch_ray)
%   
%   Simula k emisiones de rayos sobre la imagen del archivo arch_img,
%   discretizada en n filas y m columnas.
%   El resultado R es una matriz de k filas, una por cada rayo generado
%   y de (m*n)+1 columnas. Cada fila contiene la informaci�n
%   correspondiente a cada rayo; el primer elemento es el tiempo que tard�
%   el rayo en recorrer la imagen y el resto de los elementos es la
%   cantidad de pixeles que recorri� el rayo en cada una de las n*m celdas
%   de la discretizaci�n.
%   Esta matriz se devuelve y, si el parametro arch_ray est� presente, 
%   se almacenan los rayos en el archivo arch_ray.

    I = leerImagen(arch_img);
    [f, c] = size(I);

    R = zeros(k, n*m+1);
    p = fix(k/20);
    for i = 1:k
        if mod(i,p) == 0
            disp(['Generados ', num2str(i), ' rayos...']);
        end
        % elijo un lado para entrar y otro para salir 
        %   (0: izq, 1: arr, 2: der, 3: aba)
        entra = fix(rand()*4);
        sale = mod(entra + fix(rand()*3) + 1, 4);
        
        % genero puntos aleatorios sobre esos lados y simulo el rayo
        [f_ini, c_ini] = randPos(entra, f, c);
        [f_fin, c_fin] = randPos(sale, f, c);
        [t, D] = simularRayo(I, n, m, f_ini, c_ini, f_fin, c_fin, 0); % El cero final es para que no lo dibuje
        
        % agrego el rayo simulado a mis datos
        R(i,:) = [t vectorizar(D)];
    end
    
    if nargin > 4
        dlmwrite(arch_ray, [n m zeros(1,n*m-1); R]);
    end
end

function [f, c] = randPos(lado, filas, columnas)
    if lado == 0 % izquierdo
        f = rand()*filas;
        c = 0;
    elseif lado == 1 % arriba
        f = 0;
        c = rand()*columnas;
    elseif lado == 2 % derecha
        f = rand()*filas;
        c = columnas;
    elseif lado == 3 % abajo
        f = filas;
        c = rand()*columnas;
    end
end

