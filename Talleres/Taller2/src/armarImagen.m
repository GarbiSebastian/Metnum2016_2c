function X = armarImagen(x, n, m)
%ARMARIMAGEN Arma una imagen X (matriz) a partir de una solución x (vector)
    X = zeros(n,m);
    for i = 1:n
        desde = m*(i-1) + 1;
        hasta = m*i;
        X(i,:) = x(desde:hasta)';
    end

    % satura los valores de la imagen
    X = max(0, min(255, X));
end

