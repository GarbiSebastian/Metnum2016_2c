#ifndef ALGORITMOINTERFACE_H
#define ALGORITMOINTERFACE_H

#include "typedefs.h"

class AlgoritmoInterface {
public:
	AlgoritmoInterface() {};
    virtual ~AlgoritmoInterface() {};
    virtual void inicializar(Matriz & matriz, int n)=0;
    virtual void resolver(Vector &b, Vector &x)=0;
protected:
    int n;

};
#endif /* ALGORITMOINTERFACE_H */

