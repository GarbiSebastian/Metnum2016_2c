#ifndef AlgoritmoEG_H
#define AlgoritmoEG_H

#include "AlgoritmoInterface.h"

class AlgoritmoEG : public AlgoritmoInterface {
//class AlgoritmoEG{
public:
    AlgoritmoEG();
    virtual ~AlgoritmoEG();
    void inicializar(Matriz & matriz, int n);
    void resolver(Vector &b,Vector &x);
    Matriz& matriz();
protected:
    Matriz interna;
};

#endif /* AlgoritmoEG_H */

