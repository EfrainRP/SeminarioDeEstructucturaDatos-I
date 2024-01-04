#ifndef PORCENTAJE_H_INCLUDED
#define PORCENTAJE_H_INCLUDED

#include "Voto(Padre).h"

class Porcentaje: public Voto{
private:
    double porce;
public:
    Porcentaje();
    //Porcentaje(Porcentaje);
    void setPorcentaje(double&);
    double getPorcentaje();

    void porcentajeTotal(const double& p, const double& p1, const double& p2, const double& p3);
};


#endif // PORCENTAJE_H_INCLUDED
