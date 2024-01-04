#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "List.h"
#include "Cancion.h"

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>

#include<cstdlib>
#include<windows.h>
#include<ctime>

#include <mmsystem.h>


class Menu {
    private:
        ///Atributos
        List<Cancion>* myList;

        ///Metodos Privados
        bool Validation(char*);
        int enterValue();

        void hideCursor();
        void gotoxy(int,int);

        void newElement(List<Cancion>::Position&, int&);
        void deleteElement(const List<Cancion>::Position&);
        void EditElement(const List<Cancion>::Position&);

        void playMusic(const Cancion&);

        double showListMenu(const int, const List<Cancion>::Position);
        void showList();
        void findAnElement();
        void invertList();

        void displayMenu();
        void enterMenu();
        void clearScreen();

    public:
        ///Constructor
        Menu(List<Cancion>&);

        ///Metodo
        void mainMenu();
    };

#endif // MENU_H_INCLUDED
