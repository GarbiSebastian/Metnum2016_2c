#include "AlgoritmoLU.h"
#include "iostream"
using namespace std;

AlgoritmoLU::AlgoritmoLU() {
}

AlgoritmoLU::~AlgoritmoLU() {
}

void AlgoritmoLU::inicializar(Matriz &matriz, int n) {
	this->LU = matriz;
	this->n=n;
	int asd=100;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j< n; j++){
			double mji = this->LU[j][i]/this->LU[i][i];
			//Ej = Ej - mji Ei
			//LU[j] = LU[j] - mji*LU[i]
			for(int k=i+1; k < n; k++){
				cout << "i,j,k " << i << ", " << j << ", " << k << endl;
				this->LU[j][k]= this->LU[j][k] - mji* this->LU[i][k];
				//this->LU[j][k] = asd++;
				this->LU[j][i]=-mji;
				//this->LU[j][i]=0;
			}
		}
	}
}

Matriz& AlgoritmoLU::lu(){
	return this->LU;
}

Vector AlgoritmoLU::resolver(Vector &b) {
}

