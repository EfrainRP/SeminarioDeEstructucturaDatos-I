#ifndef TRIANGULO1_H_INCLUDED
#define TRIANGULO1_H_INCLUDED

class Triangulo{
private:
    double base;
    double altura;
    double area;

public:
    Triangulo ();
    Triangulo(Triangulo&);
    Triangulo& operator = (const Triangulo&);

    void setBase(double);
    void setAltura(double);

    double getBase();
    double getAltura();
    double getArea();

    void calcularArea();

};

#endif // TRIANGULO1_H_INCLUDED
