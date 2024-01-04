#include <iostream>
#include "List.h"

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
    int mydouble;
    char myChar[30], *ptrChar;
    do {
        cin>>myChar;
        ptrChar = &myChar[0];
        }
    while(!Validation(ptrChar));

    mydouble = atoi(ptrChar);

    return mydouble;
    }

void MENU() {
    cout<<"\t MENU \n";
    cout<<"1-.  Agregar \n";
    cout<<"2-.  Buscar por elemento\n";
    cout<<"3-.  Eliminar por posicion\n";
    cout<<"4-.  Eliminar Todo\n";
    cout<<"5-.  Buscar por posicion\n";
    cout<<"6-.  Ordenar ascendente\n";
    cout<<"7-.  Ordenar descendete\n";
    cout<<"8-.  Imprimir datos\n";
    cout<<"9-.  Modificar\n";
    cout<<"10-. Salir..\n";
    cout<<"Seleccione un opcion: ";
    }

int main() {
    List<int> mylist;
    List<int>::Position pos;
    int opc, myInt;
    do {
        system("cls");
        cout<<endl<<mylist.toString()<<endl<<endl;
        MENU();
        switch(opc=enterValue()) {
            case 1:
                if(mylist.isEmpty()) {
                    pos = nullptr;
                    mylist.insertData(pos,enterValue());
                    }
                else {
                    cout<<endl<<"Insertar al frente[1] o al final[2] o por posicion[3]: ";
                    myInt = enterValue();
                    if(myInt==1) {
                        pos = nullptr;
                        mylist.insertData(pos,enterValue());
                        }
                    else if(myInt==2) {
                        pos=mylist.getLastPos();
                        mylist.insertData(pos,enterValue());
                        }
                    else if(myInt==3) {
                        cout<<endl<<"Introduzca una posicion: ";
                        myInt = enterValue();
                        if((pos=mylist.getPos(myInt))!=nullptr) {
                            mylist.insertData(pos,enterValue());
                            }else{
                                cout<<"Posicion invalida"<<endl<<endl;
                            }
                        }
                    }

                break;

            case 2:
                if(mylist.isEmpty()) {
                    cout<<endl<<"Lista Vacia"<<endl;
                    }
                else {
                    cout<<endl<<"Inserte el elemento a buscar: ";
                    myInt = enterValue();
                    if((pos=mylist.findDataLinear(myInt))!=nullptr) {
                        cout<<endl<<"Es la posicion: "<<mylist.getPosInt(pos)<<endl;
                        }
                    else {
                        cout<<endl<<"No existe "<<endl;
                        }
                    }
                break;

            case 3:
                if(mylist.isEmpty()) {
                    cout<<endl<<"Lista Vacia"<<endl;
                    }
                else {
                    cout<<endl<<"Eliminar al frente[1] o al final[2] o por posicion[3]: ";
                    myInt = enterValue();
                    if(myInt==1) {
                        pos = mylist.getFirstPos();
                        mylist.deleteData(pos);
                        cout<<endl<<"Se elimino..."<<endl<<endl;
                        }
                    else if(myInt==2) {
                        pos=mylist.getLastPos();
                        mylist.deleteData(pos);
                        cout<<endl<<"Se elimino..."<<endl<<endl;
                        }
                    else if(myInt==3) {
                        cout<<endl<<"Introduzca una posicion: ";
                        myInt = enterValue();
                        if((pos=mylist.getPos(myInt))!=nullptr){
                            mylist.deleteData(pos);
                            cout<<endl<<"Se elimino..."<<endl<<endl;
                            }else{
                                cout<<endl<<"Posicion Invalida"<<endl<<endl;
                            }
                        }

                    }
                break;

            case 4:
                if(mylist.isEmpty()) {
                    cout<<endl<<"Lista Vacia"<<endl;
                    }
                else {
                    cout<<endl<<"Lista Eliminada"<<endl;
                    mylist.deleteAll();
                    }
                break;

            case 5:
                if(mylist.isEmpty()) {
                    cout<<endl<<"Lista Vacia"<<endl;
                    }
                else {
                    cout<<endl<<"Inserte la posicion a buscar: ";
                    myInt = enterValue();
                    if((pos=mylist.getPos(myInt))!=nullptr){
                            cout<<endl<<"Es el numero: "<<mylist.retrieve(pos)<<endl;
                            }else{
                                cout<<endl<<"Posicion Invalida"<<endl<<endl;
                            }

                    }
                break;
            case 6:

                break;

            case 7:

                break;

            case 8:
                cout<<endl<<mylist.toString()<<endl;
                break;

            case 9:
                if(mylist.isEmpty()) {
                    cout<<endl<<"Lista Vacia"<<endl;
                    }
                else {
                    cout<<endl<<"Inserte la posicion a modificar: ";
                    pos = mylist.getPos(enterValue());

                    cout<<endl<<"Ingrese valor a cambiar: ";
                    pos->setData(enterValue());

                    cout<<endl<<"Se modifico"<<endl<<endl;
                    }
                break;

            case 10:
                break;
            }
        system("pause");
        }
    while(opc!=10);
    /*mylist.insertData(nullptr, 20);
    mylist.insertData(nullptr,10);
    mylist.insertData(nullptr,40);
    mylist.insertData(nullptr,30);
    cout<<mylist.toString();
    cout << "First Node: " << mylist.retrieve(mylist.getFirstPos()) << endl;
    cout << "Last Node: " << mylist.retrieve(mylist.getLastPos()) << endl;
    cout << "Insert new nodes: 80,85"<<endl;
    mylist.insertData(nullptr,80);
    mylist.insertData(nullptr,85);
    cout<<mylist.toString()<<endl;
    cout << "First Node: " << mylist.retrieve(mylist.getFirstPos()) << endl;
    cout << "Last Node: " << mylist.retrieve(mylist.getLastPos()) << endl;
    cout << "remove Node: 40"<<endl;
    mylist.deleteData(mylist.findDataLinear(40));
    cout<<mylist.toString()<<endl;*/
    }
