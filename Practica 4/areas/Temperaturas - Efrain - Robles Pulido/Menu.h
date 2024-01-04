#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Celsius.h"
#include "Kelvin.h"
#include "Fahrenheit.h"

#include <iostream>
#include <cstdlib>//atoi y atof

class Menu{
private:
    Celsius c;
    Kelvin k;
    Fahrenheit f;

    char myChar[2], *ptrChar;

    void Display();

public:
    Menu ();
    Menu(Menu&);

    void celsiusToKelvin();
    void kelvinToCelsius();
    void CelsiusToFahren();
    void FahrenToCelsius();

    bool Validacion(char*);

    void MainMenu();

};

#endif // MENU_H_INCLUDED
