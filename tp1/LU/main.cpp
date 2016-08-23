#include <cstdlib>
#include "AlgoritmoLU.h"
#include "funcionesDeMatriz.h"
using namespace std;


int main(int argc, char** argv) {
	AlgoritmoLU algoritmoLU;
	int n = 3;
	Matriz matriz(n, vectorReal(n, 0));
	matriz[0][0]= 1;
	matriz[0][1]= 2;
	matriz[0][2]= 3;
	matriz[1][0]= 2;
	matriz[1][1]= 8;
	matriz[1][2]= 11;
	matriz[2][0]= 3;
	matriz[2][1]= 22;
	matriz[2][2]= 35;
	algoritmoLU.inicializar(matriz,n);
	imprimir(matriz);
	cout << "LU" << endl; 
	imprimir(algoritmoLU.lu());
	cout <<endl << "LU" << endl; 
	Vector b(n,0);
	b[0]=14;
	b[1]=51;
	b[2]=152;
	Vector x(n,0);
	algoritmoLU.resolver(b,x);
	imprimir(b);
	imprimir(x);
    return 0;
}

