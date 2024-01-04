#ifndef FIGURAS_H_INCLUDED
#define FIGURAS_H_INCLUDED

#include "Figuras.h"

class Figuras{
private:
    double altura;
    double base;

public:
    void setAltura(double);
    void setBase(double);

    double getAltura();
    double getBase();
};

#endif // FIGURAS_H_INCLUDED
