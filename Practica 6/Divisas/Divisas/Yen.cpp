#include "Moneda.h"
#include "Yen.h"

using namespace std;

Yen::Yen(){}

Yen::Yen(Yen&){}

void Yen::setYen(const double _Yen)
{
    this->yen = _Yen;
}

double Yen::getYen()
{
    return this->yen;
}

void Yen::Apeso()
{
    setValor(this->yen * 0.18);
}

