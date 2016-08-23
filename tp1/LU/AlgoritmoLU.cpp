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
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j< n; j++){
			double mji = this->LU[j][i]/this->LU[i][i];
			//Ej = Ej - mji Ei
			//LU[j] = LU[j] - mji*LU[i]
			for(int k=i+1; k < n; k++){
				cout << "i,j,k " << i << ", " << j << ", " << k << endl;
				this->LU[j][k]= this->LU[j][k] - mji* this->LU[i][k];
				this->LU[j][i]=mji;
			}
		}
	}
}

Matriz& AlgoritmoLU::lu(){
	return this->LU;
}

void AlgoritmoLU::resolver(Vector &b,Vector &x) {
	//Ax=LUx=b
	//Ly=b
	//Ux=y
	Vector y(this->n,0);
	this->resolver_Ly_b(b,y);
	this->resolver_Ux_y(y,x);
}

void AlgoritmoLU::resolver_Ly_b(Vector &b, Vector &y){
	y[0] = b[0];
	for(int i=1;i<this->n;i++){
		double suma = 0;
		for(int j = 0;j<i;j++){
			suma+= y[j]*this->LU[i][j];
		}
		y[i]= b[i]-suma;
	}
	/*cout << "Y" << endl;
	for(int i= 0; i<n; i++ ){
		cout << y[i] << " " ;
	}
	cout << endl;*/
}

void AlgoritmoLU::resolver_Ux_y(Vector &y, Vector &x){
	x[this->n-1]= y[this->n-1]/this->LU[this->n-1][this->n-1];
	for(int i=this->n-2;i>=0;i--){
		double suma = 0;
		for(int j = i+1;j<this->n;j++){
			cout << "i " << i  << " j "<< j << endl;
			suma+= x[j]*this->LU[i][j];
		}
		x[i]= (y[i]-suma)/this->LU[i][i];
	}
	cout << "X" << endl;
	for(int i= 0; i<n; i++ ){
		cout << x[i] << " " ;
	}
	cout << endl;
}


