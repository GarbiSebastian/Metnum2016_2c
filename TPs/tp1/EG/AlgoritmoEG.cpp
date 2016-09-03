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
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j< n; j++){
			double mji = this->interna[j][i]/this->interna[i][i];
			//Ej = Ej - mji Ei
			//LU[j] = LU[j] - mji*LU[i]
			for(int k=i+1; k < n; k++){
				cout << "i,j,k " << i << ", " << j << ", " << k << endl;
				this->interna[j][k]= this->interna[j][k] - mji* this->interna[i][k];
				this->interna[j][i]=mji;
			}
			b[j] = b[j] - mji*b[i];
		}
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = i+1; j< n; j++){
			b[i] = b[i] - x[j]*this->interna[i][j];
		}
		x[i] = b[i]/this->interna[i][i];
	}
}

