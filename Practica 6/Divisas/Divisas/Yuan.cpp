#include "Moneda.h"
#include "Yuan.h"

using namespace std;

Yuan::Yuan(){}

Yuan::Yuan(Yuan&){}

void Yuan::setYuan(const double _Yuan)
{
    this->yuan = _Yuan;
}

double Yuan::getYuan()
{
    return this->yuan;
}

void Yuan::Apeso()
{
    setValor(this->yuan * 3.21);
}

