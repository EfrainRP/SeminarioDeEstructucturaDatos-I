#include "Triangulo.h"

using namespace std;

Triangulo::Triangulo(){}

Triangulo::Triangulo(Triangulo& t):base(0),altura(0),area(0){}

Triangulo& Triangulo::operator = (const Triangulo& t){
    this->base= t.base;
    this->altura= t.altura;
    this->area= t.area;
    return *this;
}

void Triangulo::setBase(double b){
    this->base = b;
}

void Triangulo::setAltura(double h){
    this->altura = h;
}

double Triangulo::getBase(){
    return this->base;
}

double Triangulo::getAltura(){
    return this->altura;
}

double Triangulo::getArea(){
    return this->area;
}
void Triangulo::calcularArea(){
    this->area = ((this->base)*(this->altura))/2;
}
