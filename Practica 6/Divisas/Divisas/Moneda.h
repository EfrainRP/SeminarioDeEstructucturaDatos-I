#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

class Moneda{
private:
    double valor;

public:
    Moneda();
    Moneda(Moneda&);

    void setValor(const double);
    double getValor();
};

#endif // MONEDA_H_INCLUDED
