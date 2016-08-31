#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>


#include <iostream>
#include <string>
#include <sstream>
//#include <queue>
#include <stdio.h>
//#include <windows.h>




using namespace std;


int main(int argc, char *argv[]) {

	int radioInterno = 20;
	int radioExterno = 100;
	int mMasUnoRadios = 0;
	int nAngulos = 0;
	int isoterma = 500;
	int cantInsts = 1;

	int temperaturaInterna = 1500;
	int temperaturaExterna = 0;


	int radio = 38;
	int angulo = 36;
	string pathSalida = "./r";
	stringstream radioActual;
	radioActual << radio + 2;
	stringstream anguloActual;
	anguloActual << angulo + 4;
	pathSalida = pathSalida + radioActual.str() + "a" + anguloActual.str() + ".in";

	ofstream archivoDeSalida;
	archivoDeSalida.open(pathSalida.c_str());


	archivoDeSalida << radioInterno << " ";
	archivoDeSalida << radioExterno << " ";
	archivoDeSalida << radioActual.str() << " "; //mMasUnoRadios;
	archivoDeSalida << anguloActual.str() << " "; //nAngulos;
	archivoDeSalida << isoterma << " ";
	archivoDeSalida << cantInsts << endl;

	temperaturaExterna = 0;
	for (int inst = 0; inst < cantInsts; inst++) {
		for (int i = 0; i < (angulo + 4); i++) {
			archivoDeSalida << temperaturaInterna << " ";
		}
		for (int j = 0; j < (angulo + 4); j++) {
			archivoDeSalida << temperaturaExterna << " ";
		}
		temperaturaExterna = temperaturaExterna + 50;
		archivoDeSalida << endl;
	}
	archivoDeSalida.close();




	return EXIT_SUCCESS;
}
