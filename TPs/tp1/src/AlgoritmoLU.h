#ifndef ALGORITMOLU_H
#define ALGORITMOLU_H

#include "AlgoritmoInterface.h"

class AlgoritmoLU : public AlgoritmoInterface {
//class AlgoritmoLU{
public:
    AlgoritmoLU();
    virtual ~AlgoritmoLU();
    void inicializar(Matriz & matriz, int n);
    void resolver(Vector &b,Vector &x);
protected:
    Matriz LU;
    void resolver_Ly_b(Vector &b, Vector &y);
	void resolver_Ux_y(Vector &y, Vector &x);
};

#endif /* ALGORITMOLU_H */

