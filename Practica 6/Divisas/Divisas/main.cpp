#include <iostream>

#include "Moneda.h"
#include "Peso.h"
#include "Dolar.h"
#include "Euro.h"
#include "Yen.h"
#include "Yuan.h"

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

double IngresarDatos()
{

    cout<<endl<<"Ingrese Dato: " ;
    do
    {
        cin>>myChar;
        cin.ignore();
        ptrChar = &myChar[0];
    }
    while(!Validacion(ptrChar));

    return atof(ptrChar);
}

int Display()
{
    double opc(0);
    cout<<"\t Calculo de Divisas"<<endl
        <<"1) Peso a Dolar "<<endl
        <<"2) Dolar a Peso "<<endl
        <<"3) Peso a Euro "<<endl
        <<"4) Euro a Peso "<<endl
        <<"5) Peso a Yen"<<endl
        <<"6) Yen a Peso"<<endl
        <<"7) Peso a Yuan"<<endl
        <<"8) Yuan a Peso"<<endl
        <<"9) Salir"<<endl
        <<"Ingrese una opcion: ";
    do
    {
        cin>>myChar;
        cin.ignore();
        ptrChar = &myChar[0];
    }
    while(!Validacion(ptrChar));

    opc = atof(ptrChar);

    cout<<endl;
    return opc;
}

void PesoDolar()
{
    Peso p;
    cout<<"\tPESO A DOLAR"<<endl;
    p.setPeso(IngresarDatos());
    p.Adolar();

    cout<<endl<<"\tRESULTADO: "<<p.getValor()<<endl<<endl;
}

void DolarPeso()
{
    Dolar d;
    cout<<"\tDOLAR A PESO"<<endl;
    d.setDolar(IngresarDatos());
    d.Apeso();

    cout<<endl<<"\tRESULTADO: "<<d.getValor()<<endl<<endl;
}

void PesoEuro()
{
    Peso p;
    cout<<"\tPESO A EURO"<<endl;
    p.setPeso(IngresarDatos());
    p.Aeuro();

    cout<<endl<<"\tRESULTADO: "<<p.getValor()<<endl<<endl;
}
void EuroPeso()
{
    Euro e;
    cout<<"\tEURO A PESO"<<endl;
    e.setEuro(IngresarDatos());
    e.Apeso();

    cout<<endl<<"\tRESULTADO: "<<e.getValor()<<endl<<endl;
}
void PesoYen()
{
    Peso p;
    cout<<"\tPESO A YEN"<<endl;
    p.setPeso(IngresarDatos());
    p.Ayen();

    cout<<endl<<"\tRESULTADO: "<<p.getValor()<<endl<<endl;
}

void YenPeso()
{
    Yen ye;
    cout<<"\tYEN A PESO"<<endl;
    ye.setYen(IngresarDatos());
    ye.Apeso();

    cout<<endl<<"\tRESULTADO: "<<ye.getValor()<<endl<<endl;
}

void PesoYuan()
{
    Peso p;
    cout<<"\tPESO A YUAN"<<endl;
    p.setPeso(IngresarDatos());
    p.Ayuan();

    cout<<endl<<"\tRESULTADO: "<<p.getValor()<<endl<<endl;
}
void YuanPeso()
{
    Yuan yu;
    cout<<"\tYUAN A PESO"<<endl;
    yu.setYuan(IngresarDatos());
    yu.Apeso();

    cout<<endl<<"\tRESULTADO: "<<yu.getValor()<<endl<<endl;
}

int main()
{
    char opcM;
    int opc(0);
    do
    {
        do
        {
            system("cls");
            switch(opc = Display())
            {
            case 1:
                PesoDolar();

                break;
            case 2:
                DolarPeso();

                break;
            case 3:
                PesoEuro();

                break;
            case 4:
                EuroPeso();
                break;

            case 5:
                PesoYen();

                break;

            case 6:
                YenPeso();

                break;
            case 7:
                PesoYuan();

                break;
            case 8:
                YuanPeso();

                break;

            case 9:
                cout<<"Salida con EXITO"<<endl;
                break;

            default:
                cout<<"ERROR: Ingrese opcion valida "<<endl;
            }
            system("PAUSE");

        }
        while(opc<9);

        if(opc!=9)
        {
            cout<<endl<<"Desea continuar [S]i / [N]o"<<endl;
            cin>>opcM;
            cin.ignore();
            opcM = toupper(opcM);
        }
        else
        {
            opcM = 'N';
        }

    }
    while(opcM != 'N');
    cout<<endl<<"FIN del programa"<<endl;
    return 0;
}
