#include "Celsius.h"

using namespace std;

Celsius::Celsius(){}

Celsius::Celsius(Celsius& c): cels(0){}

Celsius& Celsius::operator =(const Celsius& c){
    this->cels = c.cels;
}

double Celsius::getCels(){
    return this->cels;
}

void Celsius::setCels(const double& c){
    this->cels = c;
}

double Celsius::convertToKel(){
    return this->cels + 273.15;
}

double Celsius::convertToFahren(){
    return (this->cels* 9/5) + 32;
}
