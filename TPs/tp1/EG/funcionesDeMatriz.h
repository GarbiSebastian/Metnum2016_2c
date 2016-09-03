#ifndef FUNCIONESDEMATRIZ_H
#define FUNCIONESDEMATRIZ_H

#include <cstdlib>
#include <vector>
#include "typedefs.h"
#include <iostream>

using namespace std;

void imprimir(matrizReal& M);
void imprimir(vectorReal& v, bool transpuesto);
void imprimir(vectorReal& v);
void imprimir(matrizEntero& M);
void imprimir(vectorEntero& v, bool transpuesto);
void imprimir(vectorEntero& v);
void imprimir(matrizReal& M, ostream& out);
void imprimir(vectorReal& v, bool transpuesto, ostream& out);
void imprimir(vectorReal& v, ostream& out);
void imprimir(matrizEntero& M, ostream& out);
void imprimir(vectorEntero& v, bool transpuesto, ostream& out);
void imprimir(vectorEntero& v, ostream& out);
#endif /* FUNCIONESDEMATRIZ_H */

