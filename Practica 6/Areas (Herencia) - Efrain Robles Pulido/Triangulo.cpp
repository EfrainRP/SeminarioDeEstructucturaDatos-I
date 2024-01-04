#include "Triangulo.h"

using namespace std;

Triangulo::Triangulo(){}

Triangulo::Triangulo(Triangulo& t):area(0){}

Triangulo& Triangulo::operator = (const Triangulo& t){
    this->area= t.area;
    return *this;
}

double Triangulo::getArea(){
    return this->area;
}
void Triangulo::calcularArea(){
    this->area = ((getBase())*(getAltura()))/2;
}
