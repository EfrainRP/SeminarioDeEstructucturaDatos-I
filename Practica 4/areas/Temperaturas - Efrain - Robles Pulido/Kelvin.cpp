#include "Kelvin.h"

using namespace std;

Kelvin::Kelvin(){}

Kelvin::Kelvin(Kelvin& k): kel(0){}

Kelvin& Kelvin::operator =(const Kelvin& k){
    this->kel = k.kel;
}

double Kelvin::getKelvin(){
    return this->kel;
}

void Kelvin::setKelvin(const double& k){
    this->kel = k;
}

double Kelvin::convertToCels(){
    return this->kel - 273.15;
}
