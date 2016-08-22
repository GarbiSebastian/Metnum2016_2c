#ifndef ALGORITMOINTERFACE_H
#define ALGORITMOINTERFACE_H

#include "typedefs.h"

class AlgoritmoInterface {
public:
	AlgoritmoInterface() {};
    virtual ~AlgoritmoInterface() {};
    virtual void inicializar(matrizReal & matriz, int n)=0;
    virtual vectorReal resolver(vectorReal &b)=0;
protected:
    int n;

};
#endif /* ALGORITMOINTERFACE_H */

