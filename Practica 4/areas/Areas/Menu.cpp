#include "Menu.h"

using namespace std;

Menu::Menu(){}

Menu::Menu(Menu& m): t(m.t), c(m.c), r(m.r), p(m.p), ptrChar(nullptr) {}

int Menu::Display(){
    int opc(0);
    cout<<"\t Calculo de Areas de Figuras Geometricas"<<endl
    <<"1) Triangulo "<<endl
    <<"2) Cuadrado "<<endl
    <<"3) Rectangulo "<<endl
    <<"4) Poligono de N lados "<<endl
    <<"Ingrese una opcion: ";
    cin>>opc;

    cout<<endl;
    return opc;
}


double Menu::areaTriangulo(){
    double b (0), altu(0);

    cout<<"Triangulo"<<endl;

    cout<<endl<<"Ingrese Base: " ;
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    b = atof(ptrChar);
    t.setBase(b);

    cout<<endl<<"Ingrese Altura: " ;
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    altu = atof(ptrChar);
    t.setAltura(altu);

    t.calcularArea();
    cout<<endl<<"Area: "<<t.getArea()<<endl;
}

double Menu::areaCuadrado(){
    double b (0);

    cout<<"Cuadrado"<<endl;

    cout<<endl<<"Ingrese Base: " ;
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    b = atof(ptrChar);
    c.setBase(b);

    c.calcularArea();
    cout<<endl<<"Area: "<<c.getArea()<<endl;
}

double Menu::areaRectangulo(){
    double b (0), altu (0);

    cout<<"Rectangulo"<<endl;

    cout<<endl<<"Ingrese Base: " ;
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    b = atof(ptrChar);
    r.setBase(b);

    cout<<endl<<"Ingrese Altura: " ;
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    altu = atof(ptrChar);
    r.setAltura(altu);

    r.calcularArea();
    cout<<endl<<"Area: "<<r.getArea()<<endl;
}

double Menu::areaPoligono(){
    double  unLado(0), cantidadLados (0);

    cout<<"Poligono"<<endl;

    cout<<endl<<"Ingrese la longitud de un lado: " ;
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    unLado = atof(ptrChar);
    p.setLado(unLado);

    cout<<endl<<"Ingrese la cantidad de lados (de 5 a 10 lados): " ;
    do{
        cin>>myChar;
        ptrChar = &myChar[0];
    }while(!Validacion(ptrChar));

    cantidadLados = atof(ptrChar);
    p.setCantLados(cantidadLados);

    p.setApotema();
    cout<<endl<<"Apotema: "<<p.getApotema()<<endl;

    p.calcularArea();
    cout<<endl<<"Area: "<<p.getArea()<<endl;
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
    do {
        system("cls");
        switch(Display()) {
            case 1:
                areaTriangulo();
                break;
            case 2:
                areaCuadrado();
                break;
            case 3:
                areaRectangulo();
                break;
            case 4:
                areaPoligono();
                break;
            default:
                cout<<"ERROR: Ingrese opcion valida "<<endl;
            }
        cout<<endl<<"Desea continuar [S]i / [N]o"<<endl;
        cin>>opcM;
        opcM = toupper(opcM);
        }while(opcM != 'N');
    cout<<endl<<"FIN del programa"<<endl;
}

