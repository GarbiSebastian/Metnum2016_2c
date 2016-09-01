#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "AlgoritmoLU.h"
#include "funcionesDeMatriz.h"
#include "AlgoritmoEG.h"
#include <math.h>
#include <time.h>

using namespace std;

//Funciones
void cargarDatos(string pathEntrada);
void calcularMatriz();

void escribirSalida(FILE * salida, Vector x);
int convertir_Tjk_a_indice(int j,int k);

//Variables
double radioInterno;
double radioExterno;
int mMasUnoRadios;
int nAngulos;
double isoterma;
int cantDeInstancias;
Matriz temperaturasInternas;
Matriz temperaturasExternas;
double deltaAngulo;
double deltaAnguloCuadrado;
double deltaRadio;
double deltaRadioCuadrado;
Matriz matriz;

//Constante
double pi = 3.14159265358979323846;

int main(int argc, char *argv[]) {
	if (argc < 4) {
		cout << "Debe llamar al programa con <archivoDeEntrada> <archivoDeSalida> <algoritmo>" << endl;
		return EXIT_SUCCESS;
	}
	string archivoDeEntrada = argv[1];
	string archivoDeSalida = argv[2];
	int algoritmo =atoi(argv[3]);

	cargarDatos(archivoDeEntrada);

	//Armar matriz de entrada
	calcularMatriz();
	AlgoritmoEG algEG;
	AlgoritmoLU algLU;
	
	//algEG.inicializar(matriz, matriz.size());
	//algLU.inicializar(matriz, matriz.size());
	
	clock_t inicioGlobal = clock();
	clock_t inicioInstancia,finInstancia;
	clock_t inicioInicializacion,finInicializacion;
	//vector< clock_t> mediciones;
	vector< double> diferenciasMediciones(2,0);
	
	if (algoritmo == 0) {
		algEG.inicializar(matriz, matriz.size());
	} else if (algoritmo == 1) {
		algLU.inicializar(matriz, matriz.size());
	} else {
		cout << "Error en el parametro algoritmo" << endl;
	}
	diferenciasMediciones[1] = (double) (clock() - inicioGlobal)  / CLOCKS_PER_SEC;
	FILE * salida = fopen(archivoDeSalida.c_str(), "w");
	
	for (int instancia = 0; instancia < cantDeInstancias; instancia++) {
		Vector b(matriz.size(), 0);
		for (int i = 0; i < nAngulos; i++) {
			b[i] = temperaturasInternas[instancia][i];
			b[b.size() - nAngulos + i] = temperaturasExternas[instancia][i];
		}
		Vector x(matriz.size(), 0);
		inicioInstancia = clock();
		//mediciones.push_back(inicioInstancia);
		if (algoritmo == 0) {
			algEG.resolver(b, x);
		} else if (algoritmo == 1) {
			algLU.resolver(b, x);
		} else {
			cout << "Error en el parametro algoritmo" << endl;
		}
		finInstancia = clock();
		//mediciones.push_back(finInstancia);
		diferenciasMediciones.push_back((double) (finInstancia-inicioInstancia) / CLOCKS_PER_SEC);
		escribirSalida(salida, x);
	}
	clock_t finGlobal = clock();
	diferenciasMediciones[0]=(double) (finGlobal-inicioGlobal) / CLOCKS_PER_SEC;
	//imprimir(mediciones);
	cout << matriz.size() << " ";
	imprimir(diferenciasMediciones, true);
	cout << endl;
		
	return EXIT_SUCCESS;
}

int convertir_Tjk_a_indice(int j, int k){
	int tam = mMasUnoRadios * nAngulos;
	return j*nAngulos + ((k + nAngulos)%nAngulos);
}

void cargarDatos(string pathEntrada) {
	ifstream archivoDeEntrada;
	archivoDeEntrada.open(pathEntrada.c_str());
	archivoDeEntrada >> radioInterno;
	archivoDeEntrada >> radioExterno;
	archivoDeEntrada >> mMasUnoRadios;
	archivoDeEntrada >> nAngulos;
	archivoDeEntrada >> isoterma;
	archivoDeEntrada >> cantDeInstancias;

	deltaRadio = (double) (radioExterno - radioInterno) / (double) (mMasUnoRadios - 1);//OK SEBA
	//deltaAngulo = convertirDeGradosARadianes((double) (360 / nAngulos));
	deltaAngulo = (2*pi)/nAngulos; //SEBA
	deltaRadioCuadrado = deltaRadio * deltaRadio;//OK SEBA
	deltaAnguloCuadrado = deltaAngulo * deltaAngulo;// OK SEBA

	temperaturasInternas = Matriz(cantDeInstancias, Vector(nAngulos, 0));
	temperaturasExternas = Matriz(cantDeInstancias, Vector(nAngulos, 0));

	double temp;
	for (int j = 0; j < cantDeInstancias; j++) {
		for (int i = 0; i < nAngulos; i++) {
			archivoDeEntrada >> temp;
			temperaturasInternas[j][i] = temp;
		}
		for (int i = 0; i < nAngulos; i++) {
			archivoDeEntrada >> temp;
			temperaturasExternas[j][i] = temp;
		}
	}
	archivoDeEntrada.close();
}

void calcularMatriz() {
	int tamMatriz = nAngulos * mMasUnoRadios;
	matriz = Matriz(tamMatriz, Vector(tamMatriz, 0));//Inicializo todo con 0
	for(int i=0;i<nAngulos;i++){
		matriz[i][i]=1;//Inicializo con identidad las posiciones correspondientes al radio interno para todos sus angulos
		matriz[tamMatriz -nAngulos + i][tamMatriz -nAngulos + i]=1;//Inicializo con identidad las posiciones correspondientes al radio externo para todos sus angulos
	}
	double r=radioInterno;
	double r2= 0.0;
	double a,b,c,d,e;
	int tjk,tj_1k,tjm1k,tjk_1,tjkm1;
	for(int radio = 1;radio < (mMasUnoRadios-1);radio++){//Para cada radio
		r += deltaRadio;//calculo el valor del radio para el radio actual
		r2= pow(r,2);//calculo el valor del radio al cuadrado para el radio actual
		//calculo los coeficientes para el radio actual
		a = (1/deltaRadioCuadrado)+(1/r)*(-1/deltaRadio);
		b = (-2/deltaRadioCuadrado)+(1/r)*(1/deltaRadio)+(1/r2)*(-2/deltaAnguloCuadrado);
		c = (1/deltaRadioCuadrado);
		d = (1/r2)*(1/deltaAnguloCuadrado);
		e = d;
		for(int angulo=0;angulo< nAngulos;angulo++){
			tjk=convertir_Tjk_a_indice(radio,angulo);
			tj_1k=convertir_Tjk_a_indice(radio-1,angulo);
			tjm1k=convertir_Tjk_a_indice(radio+1,angulo);
			tjk_1=convertir_Tjk_a_indice(radio,angulo-1);
			tjkm1=convertir_Tjk_a_indice(radio,angulo+1);
			matriz[tjk][tj_1k]=a;
			matriz[tjk][tjk]=b;
			matriz[tjk][tjm1k]=c;
			matriz[tjk][tjk_1]=d;
			matriz[tjk][tjkm1]=e;
		}
	}
}
//clock_t tStart = clock();
//clock_t tStop = clock();
//printf("Tiempo que tarda Gauss: %fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);




void escribirSalida(FILE * salida, Vector x) {
	string dato;
	for (int j = 0; j < x.size(); j++) {
		fprintf(salida, "%.06f\n", x[j]);
	}
}
