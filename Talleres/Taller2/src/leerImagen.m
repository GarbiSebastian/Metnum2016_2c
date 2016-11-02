function I = leerImagen( arch )
    I = imread(arch);
    if (size(size(I), 2) > 2)
        I = I(:,:,1)/3 + I(:,:,2)/3 + I(:,:,3)/3;       
end

