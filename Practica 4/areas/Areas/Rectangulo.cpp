#include "Rectangulo.h"

using namespace std;

Rectangulo::Rectangulo(){}

Rectangulo::Rectangulo(Rectangulo& t):base(0),altura(0),area(0){}

Rectangulo& Rectangulo::operator = (const Rectangulo& t){
    this->base= t.base;
    this->altura= t.altura;
    this->area= t.area;
    return *this;
}

void Rectangulo::setBase(double b){
    this->base = b;
}

void Rectangulo::setAltura(double h){
    this->altura = h;
}

double Rectangulo::getBase(){
    return this->base;
}

double Rectangulo::getAltura(){
    return this->altura;
}

double Rectangulo::getArea(){
    return this->area;
}
void Rectangulo::calcularArea(){
    this->area = (this->base)*(this->altura);
}
