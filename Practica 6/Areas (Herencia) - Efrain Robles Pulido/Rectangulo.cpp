#include "Rectangulo.h"

using namespace std;

Rectangulo::Rectangulo(){}

Rectangulo::Rectangulo(Rectangulo& t):area(0){}

Rectangulo& Rectangulo::operator = (const Rectangulo& t){
    this->area= t.area;
    return *this;
}

double Rectangulo::getArea(){
    return this->area;
}
void Rectangulo::calcularArea(){
    this->area = (getBase())*(getAltura());
}
