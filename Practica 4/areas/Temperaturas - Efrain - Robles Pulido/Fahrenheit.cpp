#include "Fahrenheit.h"

using namespace std;

Fahrenheit::Fahrenheit(){}

Fahrenheit::Fahrenheit(Fahrenheit& f): Fahren(0){}

Fahrenheit& Fahrenheit::operator=(const Fahrenheit& f){
    this->Fahren = f.Fahren;
}

double Fahrenheit::getFahren(){
    return this->Fahren;
}

void Fahrenheit::setFahren(const double& f){
    this->Fahren = f;
}

double Fahrenheit::convertToCels(){
    return (this->Fahren - 32) * 5/9;
}
