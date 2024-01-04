#ifndef POLIGONO_H_INCLUDED
#define POLIGONO_H_INCLUDED

class Poligono{
private:
    int cantLados;
    double lado;
    double apotema;
    double area;

public:
    Poligono ();
    Poligono(Poligono&);
    Poligono& operator = (const Poligono&);

    void setCantLados(double);
    void setLado(double);
    void setApotema();

    void calcularArea();
    double getArea();

    double getCantLados();
    double getLado();
    double getApotema();

};

#endif // POLIGONO_H_INCLUDED
