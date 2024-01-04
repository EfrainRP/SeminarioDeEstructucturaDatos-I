#include "Poligono.h"
#include <math.h>

using namespace std;

Poligono::Poligono(){}

Poligono::Poligono(Poligono& t):cantLados(0), lado(0),apotema(0),area(0){}

Poligono& Poligono::operator = (const Poligono& t){
    this->cantLados= t.cantLados;
    this->lado= t.lado;
    this->apotema= t.apotema;
    this->area= t.area;
    return *this;
}

void Poligono::setCantLados(double c){
    this->cantLados = c;
}

void Poligono::setLado(double l){
    this->lado = l;
}


void Poligono::setApotema(){
    this->apotema = this->lado/(2*tan(360/(2*this->cantLados)));
}

double Poligono::getCantLados(){
    return this->cantLados;
}

double Poligono::getLado(){
    return this->lado;
}

double Poligono::getApotema(){
    return this->apotema;
}

void Poligono::calcularArea(){
    this->area = ((this->cantLados)*(this->lado)*(this->apotema))/2;
}

double Poligono::getArea(){
    return this->area;
}



