#include "Moneda.h"
using namespace std;

Moneda::Moneda(){}

Moneda::Moneda(Moneda&){}

void Moneda::setValor(const double _valor)
{
    this->valor = _valor;
}

double Moneda::getValor()
{
    return this->valor;
}
