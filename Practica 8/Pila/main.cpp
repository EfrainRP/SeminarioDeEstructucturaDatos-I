#include <iostream>
#include "Stack.h"

using namespace std;

bool Validation(char* num) {
    if((char)*num>=48 && (char)*num<=57) {
        cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
        }
    else {
        cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
        }
    }

int enterValue() {
    double mydouble;
    char myChar[30], *ptrChar;
    do {
        cin>>myChar;
        ptrChar = &myChar[0];
        }
    while(!Validation(ptrChar));

    mydouble = atoi(ptrChar);

    return mydouble;
    }

void Menu() {
    system("cls");
    cout<<"\tMENU"<<endl;
    cout<<"1) Push (Apilar)"<<endl;
    cout<<"2) Pop (Des-apilar)"<<endl;
    cout<<"3) Mostrar Tope"<<endl;
    cout<<"4) Mostrar Pila"<<endl;
    cout<<"5) Salir"<<endl;

    cout<<"Seleccione opcion: ";
    }

int main() {
    Stack<int,10> myStack;
    int value;

    do {
        Menu();
        switch(value = enterValue()) {
            case 1:
                while(!myStack.isFull()) {
                    system("cls");
                    cout<<"Ingrese valor apilar: ";

                    try {
                        myStack.push(enterValue());
                        }
                    catch(AnyException ex) {
                        cout << endl << "\t\tOcurrio un error" << endl;
                        cout << "\t\tError de sistema:" << ex.what() << endl<< endl;
                        break;
                        }
                    system("pause");
                    }
                break;

            case 2:
                try {
                    cout<<"Se elimino el ("<<myStack.pop()<<") "<<endl<<endl;
                    }
                catch(AnyException ex) {
                    cout << endl << "\t\tOcurrio un error" << endl;
                    cout << "\t\tError de sistema:" << ex.what() << endl<< endl;
                    }
                system("pause");
                break;

            case 3:
                try {
                    cout<<endl<<"El numero que esta arriba de la pila es: "<<myStack.getTop()<<endl<<endl;
                    }
                catch(AnyException ex) {
                    cout << endl << "\t\tOcurrio un error" << endl;
                    cout << "\t\tError de sistema:" << ex.what() << endl<< endl;
                    }
                system("pause");
                break;

            case 4:
                if(myStack.isEmpty()) {
                    cout<< endl<<"Pila Vacia"<<endl<< endl;
                    }
                else {
                    while(!(myStack.isEmpty())) {
                        try {
                            cout<<myStack.pop()<<endl;
                            }
                        catch(AnyException ex) {
                            cout << endl << "\t\tOcurrio un error" << endl;
                            cout << "\t\tError de sistema:" << ex.what() << endl<< endl;
                            }
                        }
                    }
                system("pause");
                break;

            case 5:
                break;

            default:
                cout<<endl<<"\t\tERROR"<<endl<<"\tSeleccione opcion valida "<<endl<<endl;
                system("pause");
            }

        }
    while(value!=5);

    cout<<endl<<"FIN DEL PROGRAMA"<<endl;

    return 0;
    }
