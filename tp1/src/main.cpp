#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "AlgoritmoLU.h"
#include "funcionesDeMatriz.h"
#include "AlgoritmoEG.h"

using namespace std;

//typedef vector<double> Vector;
//typedef vector< vector<double> > Matriz;

//Funciones
void cargarDatos(string pathEntrada);
void calcularMatriz();
void escribirFilaMatriz(int j, int tamMatriz,int radioActual);
void escribirSalida(string pathSalida, Vector vector);
double valor_J_MenosUno_K(int j);
double valor_J_K(int j);
double valor_J_MasUno_K(int j);
double valor_J_K_MasMenosUno(int j);
double convertirDeGradosARadianes(double grados);
void mostrarDatosCargados();
void mostrarVector(Vector vactor);
void mostrarMatriz(Matriz matriz, int tam);


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
double pi = 3.1415926535897;

int main(int argc, char *argv[]){
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
	
	
	/*LA RECONCHA DE TU MADRE C++ QUE NO TE DEJA HACER ESTAS COSAS*/
	/*AlgoritmoInterface alg;
	if(algoritmo == 0){
		AlgoritmoEG alg;
	}else if(algoritmo == 1){
		AlgoritmoLU alg;
	}else{
		cout << "Error en el parametro algoritmo" << endl; 
	}*/
	
	for(int instancia = 0; instancia<cantDeInstancias;instancia++){
		//Leer de archivDeEntrada las temperaturas para los radios internos y externos de la iesima instancia (linea i)
		Vector b(tamMatriz,0);
		Vector x(tamMatriz,0);
		//alg.resolver(b,x);
		if(algoritmo == "0"){
			algEG.resolver(b,x);
		}else if(algoritmo == "1"){
			algLU.resolver(b,x);
		}else{
			cout << "Error en el parametro algoritmo" << endl; 
		}
	}
		
	
	    //matriz = Matriz(2, 2);
	matriz = Matriz(2, Vector(2,0));
	
	matriz[0][0] = 1;
	matriz[0][1] = 2;
	matriz[1][0] = 3;
	matriz[1][1] = 4;
	
    cargarDatos("D:/SVN FACU/Metnum2016_2c/tp1/src/tests/testAle.in");
    calcularMatriz();
    mostrarDatosCargados();

    escribirSalida("D:/SVN FACU/Metnum2016_2c/tp1/src/tests/test3Ale.out",temperaturasInternas);
    

    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void cargarDatos(string pathEntrada){
	ifstream archivoDeEntrada;
	archivoDeEntrada.open(pathEntrada.c_str());
	archivoDeEntrada >> radioInterno;
	archivoDeEntrada >> radioExterno;
	archivoDeEntrada >> mMasUnoRadios;
	archivoDeEntrada >> nAngulos;
	archivoDeEntrada >> isoterma;
	archivoDeEntrada >> cantDeInstancias;

	deltaRadio = (double)(radioExterno - radioInterno) / (double)(mMasUnoRadios-1);
	deltaAngulo = convertirDeGradosARadianes((double)(360/nAngulos));
	deltaRadioCuadrado = deltaRadio * deltaRadio;
	deltaAnguloCuadrado = deltaAngulo * deltaAngulo;

	temperaturasInternas = Matriz(cantDeInstancias,Vector(nAngulos,0));
	temperaturasExternas = Matriz(cantDeInstancias,Vector(nAngulos,0));

	double temp;
	for(int j = 0 ; j< cantDeInstancias;j++){
		for(int i = 0; i < nAngulos; i++){
			archivoDeEntrada >> temp;       
			temperaturasInternas[j][i] = temp;
		}
		for(int i = 0; i < nAngulos; i++){
			archivoDeEntrada >> temp;       
			temperaturasExternas[j][i] = temp;
		}
	}
	archivoDeEntrada.close();
} 

void calcularMatriz(){
	int tamMatriz = nAngulos * mMasUnoRadios;
	int radioActual = 0;
	matriz = Matriz(tamMatriz, Vector(tamMatriz,0));
	for(int i = 0; i < tamMatriz; i++){
		escribirFilaMatriz(i, tamMatriz,radioActual);
		if(i > (radioActual)* (mMasUnoRadios-1)){
			radioActual++;
		}
	}     
}

void escribirFilaMatriz(int j, int tamMatriz, int radioActual){
     if(j < nAngulos || j > (tamMatriz-nAngulos-1)){
          matriz[j][j] = 1;
     }else{
          int posInicialDelRadio = (radioActual-1) * (mMasUnoRadios-1);
          int posFinalDelRadio = (posInicialDelRadio-1) + (mMasUnoRadios-1);
          matriz[j][j] = valor_J_K(radioActual);
          matriz[j][j-mMasUnoRadios+1] = valor_J_MasUno_K(radioActual);//-1;                                      
          matriz[j][j+mMasUnoRadios-1] = valor_J_MenosUno_K(radioActual);//1;                   
          double valorCaundoK_EsMasMenosUno =  valor_J_K_MasMenosUno(radioActual);
          if(j==posInicialDelRadio){
               matriz[j][posFinalDelRadio] = valorCaundoK_EsMasMenosUno;
          }else{
                matriz[j][j-1] = valorCaundoK_EsMasMenosUno;
          }
          if(j==posFinalDelRadio){
               matriz[j][posInicialDelRadio] = valorCaundoK_EsMasMenosUno;
          }else{
                matriz[j][j+1] = valorCaundoK_EsMasMenosUno;
          }        
          
     }

     
}


void escribirSalida(string pathSalida, Vector vector){
     
     ofstream archivoDeSalida;
     archivoDeSalida.open(pathSalida.c_str());
     for(int j = 0; j < vector.size(); j++){
             archivoDeSalida <<  vector[j] << endl;
     }
     archivoDeSalida.close();
}

double valor_J_MenosUno_K(int j){
      double radio = radioInterno + (deltaRadio * j);
      return (double)((1/deltaRadioCuadrado)-(1/(deltaRadio*radio)));
}

double valor_J_K(int j){
      double radio = radioInterno + (deltaRadio * j);
      double radioCuadarado = radio * radio;
      return (double)((-2/deltaRadioCuadrado)+(1/(deltaRadio*radio))-(2/(deltaAnguloCuadrado*radioCuadarado)));
}

double valor_J_MasUno_K(int j){
      return (double)(1/deltaRadioCuadrado);
}

double valor_J_K_MasMenosUno(int j){
      double radio = radioInterno + (deltaRadio * j);
      double radioCuadarado = radio * radio;
      
      return (double)(1/(deltaAnguloCuadrado*radioCuadarado));
}

double convertirDeGradosARadianes(double grados){
       return (grados * 2 /360) * pi;
}

void mostrarDatosCargados(){

    cout << "radioInterno: " << radioInterno << endl;
    cout << "radioExterno: " << radioExterno << endl;
    cout << "mMasUnoRadios: " << mMasUnoRadios << endl;
    cout << "nAngulos: " << nAngulos << endl;
    cout << "isoterma: " << isoterma << endl;
    cout << "cantDeInstancias: " << cantDeInstancias << endl;
    cout << "deltaRadio: " << deltaRadio << endl;
    cout << "deltaAngulo: " << deltaAngulo << endl;
    
    cout << "temperaturasInternas: ";
    mostrarVector(temperaturasInternas);
    cout << "temperaturasExternas: ";
    mostrarVector(temperaturasExternas);
    
    cout << "Matiz: " << endl; 
    mostrarMatriz(matriz, matriz.size());
}

void mostrarVector(Vector vactor){
     for(int j = 0; j < vactor.size(); j++){
             cout << vactor[j] << " ";
     } cout << endl;
}


void mostrarMatriz(Matriz matriz, int tam){
     for(int i = 0; i < tam; i++){
             for(int j = 0; j < tam; j++){
                     cout << matriz[i][j] << " ";
             } cout << endl;
     }cout << endl;
}
