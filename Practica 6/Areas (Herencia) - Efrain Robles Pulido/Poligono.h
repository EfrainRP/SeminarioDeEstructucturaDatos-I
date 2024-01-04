#ifndef POLIGONO_H_INCLUDED
#define POLIGONO_H_INCLUDED

#include "Figuras.h"

class Poligono: public Figuras{
private:
    int cantLados;//el lado es la base
    double apotema;
    double area;

public:
    Poligono ();
    Poligono(Poligono&);
    Poligono& operator = (const Poligono&);

    void setCantLados(double);
    void setApotema();
    void calcularArea();

    double getArea();
    double getCantLados();
    double getApotema();

};

#endif // POLIGONO_H_INCLUDED
