#include "funcionesDeMatriz.h"
#include <cmath>
#include <assert.h>
#include <cstdlib>
#include <iostream>

using namespace std;

void imprimir(matrizReal& M, ostream& out) {
	out << endl;
	int n = M.size();
	int m = M[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << M[i][j] << "  ";
		}
		out << endl;
	}
	out << endl;
}

void imprimir(vectorReal& v, bool transpuesto, ostream& out) {
	int n = v.size();
	out << endl;
	if (transpuesto) {
		for (int i = 0; i < n; i++) {
			out << v[i] << ' ';
		}
	} else {
		for (int i = 0; i < n; i++) {
			out << v[i] << endl;
		}
	}
	out << endl;
}

void imprimir(vectorReal& v, ostream& out) {
	imprimir(v, false, out);
}

void imprimir(matrizEntero& M, ostream& out) {
	out << endl;
	int n = M.size();
	int m = M[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << M[i][j] << "  ";
		}
		out << endl;
	}
	out << endl;
}

void imprimir(vectorEntero& v, bool transpuesto, ostream& out) {
	int n = v.size();
	out << endl;
	if (transpuesto) {
		for (int i = 0; i < n; i++) {
			out << v[i] << ' ';
		}
	} else {
		for (int i = 0; i < n; i++) {
			out << v[i] << endl;
		}
	}
	out << endl;
}

void imprimir(vectorEntero& v, ostream& out) {
	imprimir(v, false, out);
}

void imprimir(matrizReal& M) {
	imprimir(M, cout);
}

void imprimir(vectorReal& v, bool transpuesto) {
	imprimir(v, transpuesto, cout);
}

void imprimir(vectorReal& v) {
	imprimir(v, cout);
}

void imprimir(matrizEntero& M) {
	imprimir(M, cout);
}

void imprimir(vectorEntero& v, bool transpuesto) {
	imprimir(v, transpuesto, cout);
}

void imprimir(vectorEntero& v) {
	imprimir(v, cout);
}
