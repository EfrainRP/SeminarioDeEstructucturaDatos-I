#include "Porcentaje.h"

Porcentaje::Porcentaje(){}

//Porcentaje::Porcentaje(const Porcentaje p): porce(0){}

void Porcentaje::setPorcentaje(double& p){
    this->porce = p;
}

double Porcentaje::getPorcentaje(){
    return this->porce;
}

void Porcentaje::porcentajeTotal(const double& p, const double& p1, const double& p2, const double& p3) {
    this->porce = (p*100)/(p1+p2+p3);
    }
