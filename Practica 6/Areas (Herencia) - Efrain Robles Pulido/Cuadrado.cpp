#include "Cuadrado.h"

using namespace std;

Cuadrado::Cuadrado(){}

Cuadrado::Cuadrado(Cuadrado& c):area(0){ }

Cuadrado& Cuadrado::operator=(const Cuadrado& c){
    this->area = c.area;
    return *this;
}

void Cuadrado::calcularArea(){
    this->area = (getBase())*(getBase());
}

double Cuadrado::getArea(){
    return this->area;
}
