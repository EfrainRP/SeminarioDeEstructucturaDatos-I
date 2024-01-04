#ifndef CUADRADO_H_INCLUDED
#define CUADRADO_H_INCLUDED

#include "Figuras.h"

class Cuadrado: public Figuras{
private:
    double area;

public:
    Cuadrado ();
    Cuadrado(Cuadrado&);
    Cuadrado& operator = (const Cuadrado&);

    void calcularArea();

    double getArea();
};


#endif // CUADRADO_H_INCLUDED
