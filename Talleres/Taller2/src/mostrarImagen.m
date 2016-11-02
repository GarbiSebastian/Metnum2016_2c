function H = mostrarImagen(I)
%MOSTRARIMAGEN Muestra la imagen en escala de grises y devuelve el handle.
    H = image(I);
    colormap(gray(256));
end

