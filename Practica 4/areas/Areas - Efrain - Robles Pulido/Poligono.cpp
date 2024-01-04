#include "Poligono.h"
#include <math.h>
#include <iostream>

using namespace std;

Poligono::Poligono(){}

Poligono::Poligono(Poligono& p):cantLados(p.cantLados), lado(p.lado),apotema(p.apotema),area(p.area){}

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
    double angulo(0), radAngulo(0);
    angulo = 360/(2*this->cantLados);
    radAngulo = angulo*(3.14159265/180);//Conversion de grados a radianes

    this->apotema = this->lado/(2*tan(radAngulo));//La tangente necesita radianes
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



