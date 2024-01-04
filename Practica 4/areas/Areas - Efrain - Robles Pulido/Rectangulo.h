#ifndef RECTANGULO_H_INCLUDED
#define RECTANGULO_H_INCLUDED

class Rectangulo{
private:
    double base;
    double altura;
    double area;

public:
    Rectangulo ();
    Rectangulo(Rectangulo&);
    Rectangulo& operator = (const Rectangulo&);

    void setBase(double);
    void setAltura(double);

    void calcularArea();

    double getBase();
    double getAltura();
    double getArea();

};

#endif // RECTANGULO_H_INCLUDED
