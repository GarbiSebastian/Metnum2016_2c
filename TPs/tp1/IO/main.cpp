#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>


using namespace std;

typedef vector<double> Vector;
typedef vector< vector<double> > Matrix;

//Funciones
void cargarDatos(string pathEntrada);
void calcularMatriz();
void escrivirFilaMatris(int j, int tamMatriz,int radioActual);
void escribirSalida(string pathSalida, Vector vector);
double valor_J_MenosUno_K(int j);
double valor_J_K(int j);
double valor_J_MasUno_K(int j);
double valor_J_K_MasMenosUno(int j);
double convertirDeGradosARadianes(double garados);
void mostrarDatosCargados();
void mostrarVector(Vector vactor);
void mostrarMatriz(Matrix matris, int tam);


//Variables
double radioInterno;
double radioExterno;
int mMasUnoRadios;
int nAngulos;
double isoterma;
int cantDeInstermas;
Vector temperaturasInternas;
Vector temperaturasExternas;
double daltaAngul;
double daltaAngulCuadrado;
double deltaRadio;
double deltaRadioCuadrado;
Matrix matriz; 

//Constante
double pi = 3.1415926535897;

int main(int argc, char *argv[])
{
    matriz = Matrix(2, 2);
	
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
       archivoDeEntrada >> cantDeInstermas;
       
       temperaturasInternas = Vector(nAngulos);
       temperaturasExternas = Vector(nAngulos);
       
       double temp;
       for(int i = 0; i < nAngulos; i++){
              archivoDeEntrada >> temp;       
              temperaturasInternas[i] = temp;
       }
       for(int i = 0; i < nAngulos; i++){
              archivoDeEntrada >> temp;       
              temperaturasExternas[i] = temp;
       }
       
       deltaRadio = (double)(radioExterno - radioInterno) / (double)mMasUnoRadios;
       daltaAngul = convertirDeGradosARadianes((double)(360/nAngulos));
       deltaRadioCuadrado = deltaRadio * deltaRadio;
       daltaAngulCuadrado = daltaAngul * daltaAngul;
       
       archivoDeEntrada.close();

} 

void calcularMatriz(){
     
     int tamMatriz = nAngulos * mMasUnoRadios;
     int radioActual = 1;
     matriz = Matrix(tamMatriz,tamMatriz);
     
     for(int i = 0; i < tamMatriz; i++){
             escrivirFilaMatris(i, tamMatriz,radioActual);
             if(i > (radioActual-1)* (mMasUnoRadios-1)){
                          radioActual++;
             }
     }
     
}

void escrivirFilaMatris(int j, int tamMatriz, int radioActual){
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
      return (double)((-2/deltaRadioCuadrado)+(1/(deltaRadio*radio))-(2/(daltaAngulCuadrado*radioCuadarado)));
}

double valor_J_MasUno_K(int j){
      return (double)(1/deltaRadioCuadrado);
}

double valor_J_K_MasMenosUno(int j){
      double radio = radioInterno + (deltaRadio * j);
      double radioCuadarado = radio * radio;
      
      return (double)(1/(daltaAngulCuadrado*radioCuadarado));
}

double convertirDeGradosARadianes(double garados){
       return (garados * 2 /360) * pi;
}

void mostrarDatosCargados(){

    cout << "radioInterno: " << radioInterno << endl;
    cout << "radioExterno: " << radioExterno << endl;
    cout << "mMasUnoRadios: " << mMasUnoRadios << endl;
    cout << "nAngulos: " << nAngulos << endl;
    cout << "isoterma: " << isoterma << endl;
    cout << "cantDeInstermas: " << cantDeInstermas << endl;
    cout << "deltaRadio: " << deltaRadio << endl;
    cout << "daltaAngul: " << daltaAngul << endl;
    
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


void mostrarMatriz(Matrix matriz, int tam){
     for(int i = 0; i < tam; i++){
             for(int j = 0; j < tam; j++){
                     cout << matriz[i][j] << " ";
             } cout << endl;
     }cout << endl;
}



