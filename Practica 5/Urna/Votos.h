#ifndef VOTOS_H_INCLUDED
#define VOTOS_H_INCLUDED

#include <iostream>

class Votos {
    private:
        double voto;
        double porcentaje;

        char myChar[30], *ptrChar;
    public:
        Votos();
        Votos(Votos&);
        Votos& operator = (Votos&);

        void setVotos();
        void setPorcentaje(const double&);

        double getVotos();
        double getPorcentaje();

        int Display();
        bool Validacion(char*);

        void porcentajeTotal(const double&, const double&, const double&, const double&);

        void mainMenu();

    };

#endif // VOTOS_H_INCLUDED
