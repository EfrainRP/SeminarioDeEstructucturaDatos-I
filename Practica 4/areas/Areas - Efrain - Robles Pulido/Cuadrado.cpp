#include "Cuadrado.h"

using namespace std;

Cuadrado::Cuadrado(){}

Cuadrado::Cuadrado(Cuadrado& c):base(0),area(0){ }

Cuadrado& Cuadrado::operator=(const Cuadrado& c){
    this->base = c.base;
    return *this;
}

void Cuadrado::setBase(double b){
    this->base = b;
}

void Cuadrado::calcularArea(){
    this->area = (this->base)*(this->base);
}

double Cuadrado::getBase(){
    return this->base;
}

double Cuadrado::getArea(){
    return this->area;
}
