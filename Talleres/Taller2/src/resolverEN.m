function x = resolverEN(A, b)    
    
    cant_cols = size(A,2);

    if (abs(det(A'*A)) < 0.1e-10)
        error('A no tiene rango columna completo')
    end

    L = chol(A'*A,'lower');
    y = (L\(A'*b));
    x = L'\y;
    
end
