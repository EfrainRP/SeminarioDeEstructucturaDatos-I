#ifndef YEN_H_INCLUDED
#define YEN_H_INCLUDED

#include "Moneda.h"

class Yen:public Moneda{
private:
    double yen;

public:
    Yen();
    Yen(Yen&);

    void setYen(const double);
    double getYen();

    void Apeso();
};


#endif // YEN_H_INCLUDED
