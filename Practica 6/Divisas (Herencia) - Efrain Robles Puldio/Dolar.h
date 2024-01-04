#ifndef DOLAR_H_INCLUDED
#define DOLAR_H_INCLUDED

#include "Moneda.h"

class Dolar:public Moneda{
private:
    double dolar;

public:
    Dolar();
    Dolar(Dolar&);

    void setDolar(const double);
    double getDolar();

    void Apeso();
};

#endif // DOLAR_H_INCLUDED
