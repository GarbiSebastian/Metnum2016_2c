function V = vectorizar(A)
%VECTORIZAR Vectoriza por filas la matriz A
    At = A';
    V = At(:)';
end

