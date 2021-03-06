function [resultados,datos] = isoterma (inputfile, outputfile, isofile)
ifid = fopen(inputfile);
datos = fscanf(ifid,'%d',6);
fclose(ifid);
outfid = fopen(outputfile);
valores= fscanf(outfid,'%f',inf);
fclose(outfid);


angulos = datos(4);
radios = datos(3);
ri = datos(1);
re = datos(2);
isoterma = datos(5);
instancias = datos(6);

puntos = angulos * radios;
sizeSalida =angulos*instancias;

deltaradio = (re - ri) / radios;
resultados = repmat(re, angulos*instancias,1);

for k = 1 : instancias
  for x = 0 : radios - 2
    for y = 0 : angulos - 1 
      pTrj = y + (angulos * x) + ((k-1) * (puntos));
      pTrj1 = pTrj + angulos;
      Trj = valores(int32(pTrj)+1 );
      Trj1 = valores(int32(pTrj1)+1);
      
      if (Trj >= isoterma && Trj1 < isoterma)
        proporcional = (deltaradio * (isoterma - Trj)) / (Trj1 - Trj);
        final = ri + (proporcional + (x * deltaradio));
        resultados(y+1+ ((k-1) * (angulos))) = final;
        
      end
    end
  end
end
isofid = fopen(isofile,'w');
for y = 1 : sizeSalida
	fprintf(isofid,'%f \n', resultados(y));
end
fclose(isofid);
end