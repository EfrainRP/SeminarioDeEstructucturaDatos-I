#ifndef CUADRADO_H_INCLUDED
#define CUADRADO_H_INCLUDED

class Cuadrado{
private:
    double base;
    double area;

public:
    Cuadrado ();
    Cuadrado(Cuadrado&);
    Cuadrado& operator = (const Cuadrado&);

    void setBase(double);
    void calcularArea();

    double getBase();
    double getArea();
};


#endif // CUADRADO_H_INCLUDED
