#ifndef RECTANGULO_H_INCLUDED
#define RECTANGULO_H_INCLUDED

#include "Figuras.h"

class Rectangulo: public Figuras{
private:
    double area;

public:
    Rectangulo ();
    Rectangulo(Rectangulo&);
    Rectangulo& operator = (const Rectangulo&);

    void calcularArea();

    double getArea();

};

#endif // RECTANGULO_H_INCLUDED
