#include <cstdlib>
#include "AlgoritmoLU.h"
#include "funcionesDeMatriz.h"
using namespace std;


int main(int argc, char** argv) {
	AlgoritmoLU algoritmoLU;
	int n = 4;
	Matriz matriz(n, vectorReal(n, 8.0));
	matriz[0][0]= 1;
	matriz[0][1]= 2;
	matriz[0][2]= 3;
	matriz[0][3]= 4;
	matriz[1][0]= 2;
	matriz[1][1]= 9;
	matriz[1][2]= 12;
	matriz[1][3]= 15;
	matriz[2][0]= 3;
	matriz[2][1]= 26;
	matriz[2][2]= 41;
	matriz[2][3]= 49;
	matriz[3][0]= 5;
	matriz[3][1]= 40;
	matriz[3][2]= 107;
	matriz[3][3]= 135;
	algoritmoLU.inicializar(matriz,n);
	imprimir(matriz);
	imprimir(algoritmoLU.lu());
    return 0;
}

