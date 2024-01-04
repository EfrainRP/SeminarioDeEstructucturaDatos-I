#include "Moneda.h"
#include "Euro.h"

using namespace std;

Euro::Euro(){}

Euro::Euro(Euro&){}

void Euro::setEuro(const double _Euro)
{
    this->euro = _Euro;
}

double Euro::getEuro()
{
    return this->euro;
}

void Euro::Apeso()
{
    setValor(this->euro * 22.99);

}

