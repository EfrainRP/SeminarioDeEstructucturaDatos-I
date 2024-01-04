#include "Voto(Padre).h"

Voto::Voto(){}

Voto::Voto(Voto& v):voto(0){}

void Voto::setVoto(){
    this->voto=this->voto+1;
}

double Voto::getVoto(){
    return this->voto;
}
