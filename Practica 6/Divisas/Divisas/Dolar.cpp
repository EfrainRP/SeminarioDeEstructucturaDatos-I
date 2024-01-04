#include "Moneda.h"
#include "Dolar.h"

using namespace std;

Dolar::Dolar(){}

Dolar::Dolar(Dolar&){}

void Dolar::setDolar(const double _Dolar)
{
    this->dolar = _Dolar;
}

double Dolar::getDolar()
{
    return this->dolar;
}

void Dolar::Apeso()
{
    setValor(this->dolar * 20.29);
}

