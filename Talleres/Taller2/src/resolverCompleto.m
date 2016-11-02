function resolverCompleto(arch_img, n, m, k)
    % genero los rayos y armo el sistema
    disp('Generando los rayos aleatoriamente...');
    R = generarRayos(arch_img, n, m, k);
    A = R(:, 2:end);
    b = R(:, 1);
    
    % resuelvo el sistema por CM
    disp('Resolviendo el sistema directo con matlab...');
    tic
    x = A\b;
    toc
    X = armarImagen(x, n, m);
    
    disp('Resolviendo el sistema por CM usando ecuaciones normales...');
    tic
    x = resolverEN(A, b);
    toc
    XEN = armarImagen(x, n, m);
    
    disp('Resolviendo el sistema por CM usando QR...');
    tic
    x = resolverQR(A, b);
    toc
    XQR = armarImagen(x, n, m);
    
    % muestro las imagenes    
    I = imread(arch_img);
    colormap(gray(256));
    subplot(2,2,1), image(I);
    title('Original')
    subplot(2,2,2), image(X);
    title('Reconstruccion Matlab')
    subplot(2,2,3), image(XEN);
    title('Reconstruccion EN')
    subplot(2,2,4), image(XQR);
    title('Reconstruccion QR')
end

