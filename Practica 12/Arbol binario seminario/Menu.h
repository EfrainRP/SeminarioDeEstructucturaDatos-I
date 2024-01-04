#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "BTree.h"
#include "Info.h"

#include <iostream>
#include <random>
#include <chrono>
#include <conio.h>
#include <functional>
#include <windows.h>

class Menu {
    private:
        ///Atributos
        BTree<Info>* myBTree;

        ///Metodos Privados
        void gotoxy(int, int);
        bool Validation(char*&);
        bool ValidationNum(const string&);
        bool ValidationLetter(const string&);
        bool ValidationAlphaNum(const string&);
        bool ValidationEmail(const string&);

        void InsertData();
        void findData();
        void editData();
        void deleteData();
        void getPrevius(BTree<Info>::Position);
        void getNextPos(BTree<Info>::Position);

        void displayMenu();

    public:
        ///Constructor
        Menu(BTree<Info>&);

        ///Metodo publico
        void mainMenu();
    };


#endif // MENU_H_INCLUDED
