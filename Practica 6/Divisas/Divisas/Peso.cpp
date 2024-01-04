#include "Moneda.h"
#include "Peso.h"

using namespace std;

Peso::Peso(){}

Peso::Peso(Peso&){}

void Peso::setPeso(const double _Peso)
{
    this->peso = _Peso;
}

double Peso::getPeso()
{
    return this->peso;
}

void Peso::Adolar()
{
    setValor(this->peso * 0.049);
}

void Peso::Aeuro()
{

    setValor(this->peso * 0.043);
}

void Peso::Ayen()
{
    setValor(this->peso * 5.67);
}
void Peso::Ayuan()
{
    setValor(this->peso * 0.31);
}

