#include <iostream>
#include "Queue.h"

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
    cout<<"\tMENU"<<endl;
    cout<<"1) Push (Encolar)"<<endl;
    cout<<"2) Pop (Des-encolar)"<<endl;
    cout<<"3) Mostrar Frente"<<endl;
    cout<<"4) Mostrar Final"<<endl;
    cout<<"5) Salir"<<endl;

    cout<<"Seleccione opcion: ";
    }

int main(){
    Queue<int,10> myQueue;
    int value;

    do {
        system("cls");
        if(myQueue.isEmpty()){
            cout<<"Cola vacia"<<endl;
        }else{
        myQueue.showQueue();
        }
        Menu();
        switch(value = enterValue()) {
            case 1:
                if(!myQueue.isFull()){
                    cout<<"Ingrese valor encolar: ";

                    try {
                        myQueue.enqueue(enterValue());
                        }
                    catch(AnyException ex) {
                        cout << endl << "\t\tOcurrio un error" << endl;
                        cout << "\t\tError de sistema:" << ex.what() << endl<< endl;
                        break;
                    }
                }else{
                    system("cls");
                    cout<<"\tCola llena"<<endl;
                    system("pause");
                }
                    //system("pause");
                break;

            case 2:
                try {
                    cout<<"Se elimino el ("<<myQueue.dequeue()<<") "<<endl<<endl;
                    myQueue.eliminar();
                    }
                catch(AnyException ex) {
                    cout << endl << "\t\tOcurrio un error" << endl;
                    cout << "\t\tError de sistema:" << ex.what() << endl<< endl;
                    }
                //system("pause");
                break;

            case 3:
                try {
                    cout<<endl<<"El numero que esta en el frente de la cola es: "<<myQueue.getFrontPos()<<endl<<endl;
                    }
                catch(AnyException ex) {
                    cout << endl << "\t\tOcurrio un error" << endl;
                    cout << "\t\tError de sistema:" << ex.what() << endl<< endl;
                    }
                system("pause");
                break;

            case 4:
                if(myQueue.isEmpty()) {
                    cout<< endl<<"Cola Vacia"<<endl<< endl;
                    }
                else {
                    if(!(myQueue.isEmpty())) {
                        try {
                            cout<<endl<<"El numero que esta en el final de la cola es: "<<myQueue.dequeue()<<endl<<endl;
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
