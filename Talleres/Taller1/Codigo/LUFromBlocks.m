function [L,U] = LUFromBlocks(A)
    % Inicializo L y U con ceros y Alu como auxiliar
    L = zeros(size(A,1),size(A,2));
    U = zeros(size(A,1),size(A,2));
    Alu = A;

    if not(CheckCondLU(A))
        error('No tiene LU')
    end
    
    % Calculo todos los subbloques de L y U
    for i = 1:size(A,1)
        L11 = ______
        U11 = ______
        U12 = ______
        L21 = ______
        A22 = ______

        L(i,i) = L11;
        U(i,i) = U11;
        U(i,i:size(Alu,2)) = U12;
        L(i:size(Alu,1),i) = L21;
        Alu(i:size(Alu,1),i:size(Alu,2)) = A22;
    end
    % Seteo del ultimo elemento en la diagonal de L
    L(size(A,1),size(A,2)) = 1;
    
    % Codigo para chequar que dio bien
    Alu = L*U;
    for i = size(A,1)
        for j = size(A,2)
            if abs(A(i,j)-Alu(i,j))>0.01
                error('no iguales')
            end
        end
    end
end
