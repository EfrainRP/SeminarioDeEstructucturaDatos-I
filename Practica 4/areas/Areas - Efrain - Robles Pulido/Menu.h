#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Poligono.h"

#include <iostream>
#include <cstdlib>//atoi y atof

class Menu{
private:
    Triangulo t;
    Cuadrado c;
    Rectangulo r;
    Poligono p;

    char myChar[30], *ptrChar;

    int Display();

public:
    Menu ();
    Menu(Menu&);

    double areaTriangulo();
    double areaCuadrado();
    double areaRectangulo();
    double areaPoligono();
    bool Validacion(char*);
    bool ValidacionLetra(char*);

    void MainMenu();

};

#endif // MENU_H_INCLUDED
