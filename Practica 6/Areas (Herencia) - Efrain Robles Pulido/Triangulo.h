#ifndef TRIANGULO1_H_INCLUDED
#define TRIANGULO1_H_INCLUDED

#include "Figuras.h"

class Triangulo: public Figuras{
private:
    double area;

public:
    Triangulo ();
    Triangulo(Triangulo&);
    Triangulo& operator = (const Triangulo&);

    double getArea();

    void calcularArea();

};

#endif // TRIANGULO1_H_INCLUDED
