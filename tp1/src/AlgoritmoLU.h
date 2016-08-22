#ifndef ALGORITMOLU_H
#define ALGORITMOLU_H

#include "AlgoritmoInterface.h"

class AlgoritmoLU : public AlgoritmoInterface {
//class AlgoritmoLU{
public:
    AlgoritmoLU();
    virtual ~AlgoritmoLU();
    void inicializar(Matriz & matriz, int n);
    Vector resolver(Vector &b);
    Matriz& lu();
protected:
    Matriz LU;
};

#endif /* ALGORITMOLU_H */

