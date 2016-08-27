#include "AlgoritmoEG.h"
#include "iostream"

using namespace std;

AlgoritmoEG::AlgoritmoEG() {
}

AlgoritmoEG::~AlgoritmoEG() {
}

void AlgoritmoEG::inicializar(Matriz &matriz, int n) {
	this->interna = matriz;
	this->n=n;
	
}

Matriz& AlgoritmoEG::matriz(){
	return this->interna;
}

void AlgoritmoEG::resolver(Vector &b,Vector &x) {
	//Ax==b
	int n = this->n;
	Matriz matrizr = this->interna;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j< n; j++){
			double mji = matrizr[j][i]/matrizr[i][i];
			//Ej = Ej - mji Ei
			//LU[j] = LU[j] - mji*LU[i]
			for(int k=i+1; k < n; k++){
				//cout << "i,j,k " << i << ", " << j << ", " << k << endl;
				matrizr[j][k]= matrizr[j][k] - mji* matrizr[i][k];
				matrizr[j][i]=mji;
			}
			b[j] = b[j] - mji*b[i];
		}
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = i+1; j< n; j++){
			b[i] = b[i] - x[j]*matrizr[i][j];
		}
		x[i] = b[i]/matrizr[i][i];
	}
}

