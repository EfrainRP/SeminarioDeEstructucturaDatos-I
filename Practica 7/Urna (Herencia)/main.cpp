#include <iostream>

#include "Voto(Padre).h"
#include "Porcentaje.h"

using namespace std;

char myChar[30], *ptrChar;

bool Validacion(char* num)
{
    if((char)*num>=48 && (char)*num<=57)
    {
        cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
    }
    else
    {
        cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
    }
}

int Display() {
    double opc;
    system("cls");
    cout<<"\tMENU"<<endl;
    cout<<"Candidato -> Atlas [1]"<<endl;
    cout<<"Candidato -> Chivas [2]"<<endl;
    cout<<"Candidato -> Toluca [3]"<<endl;
    if(opc>3){
        cout<<endl<<"ERROR: Ingrese uno nuevo: ";
    }else{
    cout<<"Seleccione opcion"<<endl;
    }
    do {
        cin>>myChar;
        ptrChar = &myChar[0];
        }
    while(!Validacion(ptrChar));

    opc = atoi(ptrChar);

    cout<<endl;
    return opc;
    }

int main()
{
    Voto Atlas, Chivas, Toluca;
    Porcentaje A, C, T;
    double a(0),b(0),c(0);
    int resp, menu;
    do {

        do {
            switch(menu = Display()) {
                case 1:
                    Atlas.setVoto();
                    a= Atlas.getVoto();
                    break;
                case 2:
                    Chivas.setVoto();
                    b= Chivas.getVoto();
                    break;
                case 3:
                    Toluca.setVoto();
                    c = Toluca.getVoto();
                    break;
                }
            }while(menu>3);

        cout<<endl;
        cout<<"*********VOTOS**********"<<endl;
        cout<<" Atlas: "<<a<<endl;
        cout<<" Chivas: "<<b<<endl;
        cout<<" Toluca: "<<c<<endl;
        cout<<endl;

        //Porcentaje Atlas;

        A.porcentajeTotal(a,a,b,c);

        //Porcentaje Chivas;
        C.porcentajeTotal(b,a,b,c);

        //Porcentaje Toluca;
        T.porcentajeTotal(c,a,b,c);


        cout<<"*****PORCENTAJES********"<<endl;
        cout<<" % Atlas "<<A.getPorcentaje()<<endl;
        cout<<" % Chivas "<<C.getPorcentaje()<<endl;
        cout<<" % Toluca "<<T.getPorcentaje()<<endl;
        cout<<endl;

        cout<<"Desea ingresar nuevo voto?   1[si] 2[no]: ";
            do {
                cin>>myChar;
                ptrChar = &myChar[0];

                }while(!Validacion(ptrChar));//confirmacion de valor que sea numero

            resp = atoi(ptrChar);
            cout<<endl;

        }while(resp!=2);

    cout<<"FIN del programa"<<endl;
    system("pause");
}
