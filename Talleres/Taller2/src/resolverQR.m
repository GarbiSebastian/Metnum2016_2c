function x = resolverQR(A, b)

    cant_cols = size(A,2);

    if (abs(det(A'*A)) < 0.1e-10)
        error('A no tiene rango columna completo')
    end

    [Q,R] = qr(A);
    b_prima = (Q'*b);
    b_prima_1 = b_prima(1:cant_cols,1);
    R = R(1:cant_cols,1:cant_cols);
    x = R\b_prima_1;
    
end
