#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "AlgoritmoLU.h"
#include "funcionesDeMatriz.h"
#include "AlgoritmoEG.h"
#include <ctime>
#include <math.h>

using namespace std;

//typedef vector<double> Vector;
//typedef vector< vector<double> > Matriz;

//Funciones
void cargarDatos(string pathEntrada);
void calcularMatriz();
void escribirFilaMatriz(int j, int tamMatriz, int radioActual);
void escribirSalida(string pathSalida, Vector vector);
void escribirSalida(FILE * salida, Vector x);
double valor_J_MenosUno_K(int j);
double valor_J_K(int j);
double valor_J_MasUno_K(int j);
double valor_J_K_MasMenosUno(int j);
double convertirDeGradosARadianes(double grados);
void mostrarDatosCargados();
void mostrarVector(Vector vactor);
void mostrarMatriz(Matriz matriz, int tam);
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
	string algoritmo = argv[3];

	cargarDatos(archivoDeEntrada);

	//Armar matriz de entrada
	calcularMatriz();
	AlgoritmoEG algEG;
	AlgoritmoLU algLU;
	
//	imprimir(matriz);

/*	
//JARCODING POWA!!!!!!
	for(int i = 4;i<8;i++){
		for(int j=0;j<11;j++){
			matriz[i][j]=0;
		}
	}
	
	double r = 2;
	double r2 = pow(r,2);
	double dr = 1;
	double dr2 = pow(dr,2);
	double da = pi/2;
	double da2 = pow(da,2);
		
	double a = (1/dr2)+(1/r)*(-1/dr);
	double b = (-2/dr2)+(1/r)*(1/dr)+(1/r2)*(-2/da2);
	double c = (1/dr2);
	double d = (1/r2)*(1/da2);
	double e = d;
	
	matriz[4][0]=a;
	matriz[5][1]=a;
	matriz[6][2]=a;
	matriz[7][3]=a;
		
	matriz[4][4]=b;
	matriz[5][5]=b;
	matriz[6][6]=b;
	matriz[7][7]=b;
		
	matriz[4][8]=c;
	matriz[5][9]=c;
	matriz[6][10]=c;
	matriz[7][11]=c;
	
	matriz[4][7]=d;
	matriz[5][4]=d;
	matriz[6][5]=d;
	matriz[7][6]=d;
	
	matriz[4][5]=e;
	matriz[5][6]=e;
	matriz[6][7]=e;
	matriz[7][4]=e;
		
	imprimir(matriz);
	* */
	
	algEG.inicializar(matriz, matriz.size());
	algLU.inicializar(matriz, matriz.size());
	FILE * salida = fopen(archivoDeSalida.c_str(), "w");
	
	for (int instancia = 0; instancia < cantDeInstancias; instancia++) {
		Vector b(matriz.size(), 0);
		for (int i = 0; i < nAngulos; i++) {
			b[i] = temperaturasInternas[instancia][i];
			b[b.size() - nAngulos + i] = temperaturasExternas[instancia][i];
		}
		Vector x(matriz.size(), 0);
		if (algoritmo == "0") {
			algEG.resolver(b, x);
		} else if (algoritmo == "1") {
			algLU.resolver(b, x);
		} else {
			cout << "Error en el parametro algoritmo" << endl;
		}
		escribirSalida(salida, x);
	}
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
	/*
	for (int i = 0; i < tamMatriz; i++) {
		escribirFilaMatriz(i, tamMatriz, radioActual);
		if (i > (radioActual)* (mMasUnoRadios - 1)) {
			radioActual++;
		}
	}*/
}

void escribirFilaMatriz(int j, int tamMatriz, int radioActual) {
	if (j < nAngulos || j > (tamMatriz - nAngulos - 1)) {
		matriz[j][j] = 1;
	} else {
		int posInicialDelRadio = (radioActual) * (mMasUnoRadios - 1);
		int posFinalDelRadio = (posInicialDelRadio - 1) + (mMasUnoRadios - 1);
		matriz[j][j] = valor_J_K(radioActual);
		matriz[j][j - mMasUnoRadios + 1] = valor_J_MasUno_K(radioActual); //-1;                                      
		matriz[j][j + mMasUnoRadios - 1] = valor_J_MenosUno_K(radioActual); //1;                   
		double valorCaundoK_EsMasMenosUno = valor_J_K_MasMenosUno(radioActual);
		if (j == posInicialDelRadio) {
			matriz[j][posFinalDelRadio] = valorCaundoK_EsMasMenosUno;
		} else {
			matriz[j][j - 1] = valorCaundoK_EsMasMenosUno;
		}
		if (j == posFinalDelRadio) {
			matriz[j][posInicialDelRadio] = valorCaundoK_EsMasMenosUno;
		} else {
			matriz[j][j + 1] = valorCaundoK_EsMasMenosUno;
		}

	}


}

void escribirSalida(string pathSalida, Vector vector) {

	FILE * archivoDeSalida = fopen(pathSalida.c_str(), "w");
	string dato;
	//archivoDeSalida.open(pathSalida.c_str());
	for (int j = 0; j < vector.size(); j++) {
//		 sprintf(dato.c_str(),"%f.6", vector[j]);
//		 archivoDeSalida << dato << endl;
		fprintf(archivoDeSalida, "%.06f\n", vector[j]);
	}
	fclose(archivoDeSalida);
}

void escribirSalida(FILE * salida, Vector x) {
	string dato;
	for (int j = 0; j < x.size(); j++) {
		fprintf(salida, "%.06f\n", x[j]);
	}
}


double valor_J_MenosUno_K(int j) {
	double radio = radioInterno + (deltaRadio * j);
	return (double) ((1 / deltaRadioCuadrado)-(1 / (deltaRadio * radio)));
}

double valor_J_K(int j) {
	double radio = radioInterno + (deltaRadio * j);
	double radioCuadarado = radio * radio;
	return (double) ((-2 / deltaRadioCuadrado)+(1 / (deltaRadio * radio))-(2 / (deltaAnguloCuadrado * radioCuadarado)));
}

double valor_J_MasUno_K(int j) {
	return (double) (1 / deltaRadioCuadrado);
}

double valor_J_K_MasMenosUno(int j) {
	double radio = radioInterno + (deltaRadio * j);
	double radioCuadarado = radio * radio;

	return (double) (1 / (deltaAnguloCuadrado * radioCuadarado));
}

double convertirDeGradosARadianes(double grados) {
	return (grados * 2 / 360) * pi;
}

void mostrarDatosCargados() {

	cout << "radioInterno: " << radioInterno << endl;
	cout << "radioExterno: " << radioExterno << endl;
	cout << "mMasUnoRadios: " << mMasUnoRadios << endl;
	cout << "nAngulos: " << nAngulos << endl;
	cout << "isoterma: " << isoterma << endl;
	cout << "cantDeInstancias: " << cantDeInstancias << endl;
	cout << "deltaRadio: " << deltaRadio << endl;
	cout << "deltaAngulo: " << deltaAngulo << endl;

	cout << "temperaturasInternas: ";
	imprimir(temperaturasInternas);
	cout << "temperaturasExternas: ";
	imprimir(temperaturasExternas);

	cout << "Matiz: " << endl;
	mostrarMatriz(matriz, matriz.size());
}

void mostrarVector(Vector vactor) {
	for (int j = 0; j < vactor.size(); j++) {
		cout << vactor[j] << " ";
	}
	cout << endl;
}

void mostrarMatriz(Matriz matriz, int tam) {
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
