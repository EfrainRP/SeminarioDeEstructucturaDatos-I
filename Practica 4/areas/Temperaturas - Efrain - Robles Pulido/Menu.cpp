#include "Menu.h"

using namespace std;

Menu::Menu(){}

Menu::Menu(Menu& m): c(m.c), k(m.k), f(m.f), myChar({ }), ptrChar(nullptr) {}

void Menu::Display(){
    system("cls");
    cout<<"\t Convertidor de Temperaturas"<<endl
    <<"1) Celsius - Kelvin "<<endl
    <<"2) Kelvin - Celsius "<<endl
    <<"3) Celsius - Fahrenheit "<<endl
    <<"4) Fahrenheit - Celsius "<<endl
    <<"5) Salir "<<endl
    <<"Ingrese una opcion: ";
}


void Menu::celsiusToKelvin(){
    double myDouble;

    cout<<"Ingrese valor en Celsius: ";
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    myDouble = atof(ptrChar);

    c.setCels(myDouble);

    cout<<endl<<"Kelvin: "<<c.convertToKel()<<endl;
}

void Menu::kelvinToCelsius(){
    double myDouble;

    cout<<"Ingrese valor en Kelvin: ";
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));
    myDouble = atof(ptrChar);

    k.setKelvin(myDouble);

    cout<<endl<<"Celsius: "<<k.convertToCels()<<endl;

}

void Menu::CelsiusToFahren(){
    double myDouble;

    cout<<"Ingrese valor en Celsius: ";
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));
    myDouble = atof(ptrChar);

    c.setCels(myDouble);

    cout<<endl<<"Fahrenheit: "<<c.convertToFahren()<<endl;
}

void Menu::FahrenToCelsius(){
    double myDouble;

    cout<<"Ingrese valor en Fahrenheit: ";
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));
    myDouble = atof(ptrChar);

    f.setFahren(myDouble);

    cout<<endl<<"Celsius: "<<f.convertToCels()<<endl;
}


bool Menu::Validacion(char* num){
	if((char)*num>=48 && (char)*num<=57){
        cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
    }else{
        cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
    }
}

void Menu::MainMenu(){
    char opcM;
    int opc(0);
    do{
        do{
        Display();
        do{
            cin>>myChar;
            ptrChar = &myChar[0];
        }while(!Validacion(ptrChar));//Validacion de que es un numero

        opc = atof(ptrChar);

        cout<<endl;
        switch(opc) {
            case 1:
                celsiusToKelvin();
                break;
            case 2:
                kelvinToCelsius();
                break;
            case 3:
                CelsiusToFahren();
                break;
            case 4:
                FahrenToCelsius();
                break;
            case 5:
                cout<<"Salida con exito! "<<endl;
                break;
            default:
                cout<<"ERROR: Ingrese opcion valida "<<endl<<endl;
                system("PAUSE");
            }
        }while(opc > 5);//Evita error de ingreso de opcion

        if(opc != 5){
        cout<<endl<<"Desea continuar [S]i / [N]o"<<endl;
        cin>>opcM;
        opcM = toupper(opcM);
        }else{
            break;
        }
        }while(opcM != 'N');
    cout<<endl<<"FIN del programa"<<endl;
}

