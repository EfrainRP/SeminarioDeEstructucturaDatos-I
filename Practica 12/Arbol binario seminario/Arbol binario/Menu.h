#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "BTree.h"
#include "Info.h"

#include <iostream>
#include <random>
#include <chrono>
#include <conio.h>
#include <functional>

class Menu {
    private:
        ///Atributos
        BTree<Info>* myBTree;

        ///Metodos Privados
        void InsertData();
        void findData();
        void editData();
        void deleteData();

        void displayMenu();
        void enterMenu();

    public:
        ///Constructor
        Menu(BTree<Info>&);

        ///Metodo publico
        void mainMenu();
    };


#endif // MENU_H_INCLUDED
