#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED

#include "Moneda.h"

class Euro:public Moneda{
private:
    double euro;

public:
    Euro();
    Euro(Euro&);

    void setEuro(const double);
    double getEuro();

    void Apeso();
};


#endif // EURO_H_INCLUDED
