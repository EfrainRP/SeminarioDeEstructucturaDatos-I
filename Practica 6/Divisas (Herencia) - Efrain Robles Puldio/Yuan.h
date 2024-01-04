#ifndef YUAN_H_INCLUDED
#define YUAN_H_INCLUDED

#include "Moneda.h"

class Yuan:public Moneda{
private:
    double yuan;

public:
    Yuan();
    Yuan(Yuan&);

    void setYuan(const double);
    double getYuan();

    void Apeso();
};

#endif // YUAN_H_INCLUDED
