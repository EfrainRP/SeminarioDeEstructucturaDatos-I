#ifndef PESO_H_INCLUDED
#define PESO_H_INCLUDED

#include "Moneda.h"

class Peso : public Moneda{
private:
    double peso;

public:
    Peso();
    Peso(Peso&);

    void setPeso(const double);
    double getPeso();

    void Adolar();
    void Aeuro();
    void Ayen();
    void Ayuan();
};


#endif // PESO_H_INCLUDED
