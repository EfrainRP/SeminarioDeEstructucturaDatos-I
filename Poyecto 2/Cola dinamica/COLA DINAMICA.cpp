#include <iostream>

#include <cstdlib>

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

class Nodo {
    public:
        int value;
        Nodo* next;

    };

bool cola_vacia(Nodo *frente) {
    return (frente == NULL)? true : false;
    };

void push(Nodo *&frente,Nodo *&fin,int n) {

    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->value = n;

    nuevo_nodo->next = NULL;

    if(cola_vacia(frente)) {

        frente = nuevo_nodo;

        }
    else {

        fin->next = nuevo_nodo;

        }

    fin = nuevo_nodo;
    };




void pop(Nodo *&frente,Nodo *&fin) {
    Nodo *aux = frente;

    if(frente == fin) {
        frente = NULL;
        fin = NULL;
        }
    else {
        frente = frente->next;
        }
    delete aux;
    };


void display(Nodo *&frente, int cont) {
    system("cls");
    Nodo *temp = frente;
    if(!cola_vacia(temp)){
    while(temp!=NULL) {
        if(temp==frente) {
            if(cont==1) {
                printf("\n\n\t\t%c%c%c%c%c  \n",201,205,205,205,187);//linea de arriba
                printf("  Frente %c\t%c ",175,186);//vertical derecha
                cout<<temp->value;
                printf(" %c\n",186);//verical izq
                printf("\t\t%c%c%c%c%c",200,205,205,205,188);//linea de abajo

                }
            else {
                //if()
                printf("\n\n\t\t%c%c%c%c%c  \n",201,205,205,205,187);//linea de arriba
                printf("   Frente %c\t%c ",175,186);
                cout<<temp->value;
                printf(" %c\n",186);
                printf("\t\t%c%c%c%c%c",204,205,205,205,185);//linea de abajo continuacion
                }

            temp=temp->next;
            }
        else {
            if (temp->next==NULL) {//formato de la primera caja
                printf("   Final %c\t%c ",175,186);
                cout<<temp->value;
                printf(" %c\n",186);
                printf("\t\t%c%c%c%c%c",200,205,205,205,188);

                }
            else {
                printf("\t\t%c ",186);
                cout<<temp->value;
                printf(" %c\n",186);
                printf("\t\t%c%c%c%c%c",204,205,205,205,185);

                }
            temp = temp->next;

            }

        cout << endl;
        }
    }else{
        cout<<"Cola Vacia"<<endl<<endl;
    }
    };


int menu() {

    int opc;

    cout <<endl;

    cout<<"Menu"<<endl;
    cout<<"[1]Encolar(push)"<<endl;
    cout<<"[2]Des-Encolar(pop)"<<endl;
    cout<<"[3]Mostrar frente"<<endl;
    cout<<"[4]Mostrar final"<<endl;
    cout<<"[5]Mostrar cola"<<endl;
    cout<<"[6]Salir"<<endl;

    opc = enterValue();

    return opc;

    };

int main() {

    Nodo *frente = NULL;

    Nodo *fin = NULL;

    int value, cont=0, opc=0;

    do {
        display(frente, cont);
        opc=menu();
        switch (opc) {

            case 1:
                push(frente, fin, enterValue());
                system("cls");
                cont++;
                display(frente, cont);


                break;

            case 2:
                if(!cola_vacia(frente)){
                pop(frente, fin);
                cont--;
                system("cls");
                display(frente, cont);
                }

                break;

            case 3:
                if(!cola_vacia(frente)){
                cout<<endl<<"El frente es: "<<frente->value<<endl<<endl;
                }else{
                cout<<endl<<"Cola vacia"<<endl<<endl;
                }
                system("pause");
                break;


            case 4:
                if(!cola_vacia(fin)){
                cout<<endl<<"El final es: "<<fin->value<<endl<<endl;
                }else{
                cout<<endl<<"Cola vacia"<<endl<<endl;
                }
                system("pause");
                break;

            case 5:
                display(frente, cont);
                system("pause");
                break;

            case 6:
                cout<<"FIN"<<endl;
                break;

            default:
                cout << "Opcion no disponible" <<endl;
                system("pause");

            }


        }
    while(opc!=6);

    return 0;

    };
