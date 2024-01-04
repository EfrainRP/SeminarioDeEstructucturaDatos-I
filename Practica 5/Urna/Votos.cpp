#include "Votos.h"

using namespace std;

Votos::Votos() {}

Votos::Votos(Votos& v):voto(0),porcentaje(0) {}

Votos& Votos::operator=(Votos& v) {
    voto = v.voto;
    porcentaje = v.porcentaje;
    }

void Votos::setVotos() {
    this->voto=this->voto+1;
    }

void Votos::setPorcentaje(const double& p) {
    this->porcentaje = p;
    }

double Votos::getVotos() {
    return this->voto;
    }

double Votos::getPorcentaje() {
    return this->porcentaje;
    }

int Votos::Display() {
    double opc;
    system("cls");
    cout<<"\tMENU"<<endl;
    cout<<"Candidato -> Atlas [1]"<<endl;
    cout<<"Candidato -> Chivas [2]"<<endl;
    cout<<"Candidato -> Toluca [3]"<<endl;
    if(opc>4){
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

bool Votos::Validacion(char* num) {
    if((char)*num>=48 && (char)*num<=57) {
        cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
        }
    else {
        cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
        }
    }

void Votos::porcentajeTotal(const double& p, const double& p1, const double& p2, const double& p3) {
    this->porcentaje = (p*100)/(p1+p2+p3);
    }

void Votos::mainMenu() {
    Votos Atlas, Chivas, Toluca;
    double a(0),b(0),c(0);
    int resp, menu;
    do {

        do {
            switch(menu = Display()) {
                case 1:
                    Atlas.setVotos();
                    a= Atlas.getVotos();
                    break;
                case 2:
                    Chivas.setVotos();
                    b= Chivas.getVotos();
                    break;
                case 3:
                    Toluca.setVotos();
                    c = Toluca.getVotos();
                    break;
                }
            }while(menu>3);

        cout<<endl;
        cout<<"*********VOTOS**********"<<endl;
        cout<<" Atlas: "<<a<<endl;
        cout<<" Chivas: "<<b<<endl;
        cout<<" Toluca: "<<c<<endl;
        cout<<endl;

        Atlas.porcentajeTotal(a,a,b,c);

        Chivas.porcentajeTotal(b,a,b,c);

        Toluca.porcentajeTotal(c,a,b,c);


        cout<<"*****PORCENTAJES********"<<endl;
        cout<<" % Atlas "<<Atlas.getPorcentaje()<<endl;
        cout<<" % Chivas "<<Chivas.getPorcentaje()<<endl;
        cout<<" % Toluca "<<Toluca.getPorcentaje()<<endl;
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

