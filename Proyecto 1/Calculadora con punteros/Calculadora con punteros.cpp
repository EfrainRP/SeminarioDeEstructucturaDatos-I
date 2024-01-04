//Efrain Robles Pulido

#include <ctype.h> //toupper y isdigit
#include <iostream>
#include <cstdlib>//atoi y atof
#include <math.h>//pow
#include <string>
#include<string.h>

using namespace std;

int opc(0), *opcPtr=nullptr;
char mychart, *mychar=nullptr;

double numeroC=0;
double *ptrnumeroC=nullptr;

char n1[30],n2[30];
char *ptr1 = nullptr;
char *ptr2 = nullptr, *P;

double num1=0;
double num2=0;
double *ptrnum1 = nullptr;
double *ptrnum2 = nullptr;

void Basico (double*, double*, int* );
int *factorial(double*);
int *potencia_(int*, int*);
void decimal_binario(double*);
void binario_decimal(double*);
void decimal_octal(double*);
void octal_decimal(double*);
void decimal_hexadecimal(double*);
void hexadecimal_decimal(char, int);

void Display();
void Menu();
bool Ingresar();
double *IngresarUnNumero();
int caracterHexadecimalADecimal(char );
bool Validacion(char*);

void Pausar();

int a=0;

int main(int argc, char** argv) {
    system("cls");
    while(opc!=13){
        Menu();
        Pausar();
        system("cls");
    }
    return 0;
}

void Basico (double *n1, double *n2, int *basic){
    double *resultado = (double*)malloc(sizeof(double));//malloc asignacion dinamica de punteros, es de tipo largo como puntero, puntero local
    switch(*basic){
    	case 1://Suma
    		*resultado = *n1 + *n2;
    		break;

    	case 2://Resta
            *resultado = *n1 - *n2;
    		break;
    	case 3://Multiplicacion
            *resultado = *n1 * *n2;
    		break;
        case 4://Division
            *resultado = *n1 / *n2;
            break;
	}
    cout<<endl<<"Resultado = "<<*resultado;
}

int *factorial(double *a) {
    int *r = (int*)malloc(sizeof(int));
    *r = *a;
    for(int i = 1; i < *a; i++) {
        *r = (*r)*(i);
    }
    cout<<endl<<"Factorial es: ";
    return r;
}

int *potencia_(double *a, double *b) {
    int *r = (int*)malloc(sizeof(int));
    *r = 1;
    for(int i = 0; i < *b; i++) {
        *r *= (*a);
    }
    cout<<endl<<"Potencia es: ";
    return r;
}

void decimal_binario(double *a) {
    int bin[12];
    for(int i(0); i < 12; i++) {
        bin[i]=(int)*a%2;
        *a=*a/2;
    }
    cout<<endl<<"Numero binario es:";
    for(int i(12-1); i >= 0; i--) {
        cout<<bin[i];
    }
}

void binario_decimal(double *a){
    int *digito=(int*)malloc(sizeof(int));
    int *decimal=(int*)malloc(sizeof(int));
    *decimal = 0, *digito = 0;
    int exp=0;

    while(*a !=0){
           *digito = (int)*a % 10;
           *a=*a/10;
           *decimal += (*digito) * pow(2,exp);
           exp++;
    }
    cout << endl<< "Decimal: " << *decimal << endl;

}

void decimal_octal(double *a){
    int *residuo = (int*)malloc(sizeof(int));
    int *octal = (int*)malloc(sizeof(int));
    *octal=0;

    for (int i(1); *a > 0; i*=10){
        *residuo = (int) *a % 8;
        *a /= 8;
        *octal += *residuo * i;
    }
    cout << endl<<"Numero Octal: " << *octal << endl;
}

void octal_decimal(double *a){
    int *decimal = (int*)malloc(sizeof(int));
    int *residuo = (int*)malloc(sizeof(int));
    *decimal = 0;

    for (int i(0); *a > 0; i++){
        *residuo = (int)*a % 10;
        *a /= 10;
        *decimal  += *residuo * pow(8, i);
    }
    cout << endl<< "Decimal: " << *decimal << endl;
}

void decimal_hexadecimal(double *a){
    int dig[20];
    int *residuo =(int*)malloc(sizeof(int));

    int i=0;

    do{
        *residuo=(int)*a%16;
        *a=*a/16;
        dig[i]=*residuo;
        i++;
    }while(*a>16);
    dig[i]=*a;

    cout<<endl<<"Numero hexadecimal es: ";
    for(int j=i;j>=0;j--){
        switch(dig[j]){
        case 10:
            cout<<"A";
            break;
        case 11:
            cout<<"B";
            break;
        case 12:
            cout<<"C";
            break;
        case 13:
            cout<<"D";
            break;
        case 14:
            cout<<"E";
            break;
        case 15:
            cout<<"F";
            break;
        default:
            cout<<dig[j];
        }
    }
}

void hexadecimal_decimal(char *a, int longitud){
    double *decimal = (double*)malloc(sizeof(double));
    *decimal=0;
    int potencia = 0;

    for (int i = longitud - 1; i >= 0; i--) {
        int valorActual = caracterHexadecimalADecimal(a[i]);
        int elevado = pow(16, potencia) * valorActual;
        *decimal += elevado;
        potencia++;
    }
    cout<<endl<<"Numero decimal es: "<<*decimal;
}

void Display(){
    cout<<" M E N U"<<endl
        <<"1)Suma"<<endl
        <<"2)Resta"<<endl
        <<"3)Multiplicacion"<<endl
        <<"4)Division"<<endl
        <<"5)Potencia"<<endl
        <<"6)Factorial"<<endl
        <<"7)Decimal - Binario"<<endl
        <<"8)Binario - Decimal"<<endl
        <<"9)Decimal - Octal"<<endl
        <<"10)Octal - Decimal"<<endl
        <<"11)Decimal - Hexadecimal"<<endl
        <<"12)Hexadecimal - Decimal"<<endl
        <<"13)Salir"<<endl;
}
void Menu() {
    Display();
    cin>>opc;

    switch(opc) {
        case 1:
            cout<<endl<<"\tSuma"<<endl;
            if(Ingresar()){
            opcPtr = &opc;
            num1 = atof(ptr1);
            num2 = atof(ptr2);

            ptrnum1 = &num1;
            ptrnum2 = &num2;

            Basico(ptrnum1,ptrnum2,opcPtr);
            }
            break;

        case 2:
            cout<<endl<<"\tResta"<<endl;
            if(Ingresar()){
            opcPtr = &opc;
            num1 = atof(ptr1);
            num2 = atof(ptr2);

            ptrnum1 = &num1;
            ptrnum2 = &num2;

            Basico(ptrnum1,ptrnum2,opcPtr);
            }
            break;

        case 3:
            cout<<endl<<"\tMultiplicacion"<<endl;
            if(Ingresar()){
            opcPtr = &opc;
            num1 = atof(ptr1);
            num2 = atof(ptr2);

            ptrnum1 = &num1;
            ptrnum2 = &num2;

            Basico(ptrnum1,ptrnum2,opcPtr);
            }
            break;
        case 4:
            cout<<endl<<"\tDivision"<<endl;
            if(Ingresar()){
            opcPtr = &opc;
            num1 = atof(ptr1);
            num2 = atof(ptr2);

            ptrnum1 = &num1;
            ptrnum2 = &num2;

            Basico(ptrnum1,ptrnum2,opcPtr);
            }
            break;
        case 5:
            cout<<endl<<"\tPotencia"<<endl;
            if(Ingresar()){
            num1 = atof(ptr1);
            num2 = atof(ptr2);

            ptrnum1 = &num1;
            ptrnum2 = &num2;

            cout<< *potencia_(ptrnum1,ptrnum2)<<endl;
            }
            break;
        case 6:
            cout<<endl<<"\tFactorial"<<endl;
            cout<< *factorial(IngresarUnNumero())<<endl;
            break;
        case 7:
            cout<<endl<<"\tDecimal - Binario"<<endl;
            decimal_binario(IngresarUnNumero());
            break;
        case 8:
            cout<<endl<<"\tBinario - Decimal"<<endl;
            binario_decimal(IngresarUnNumero());
            break;
        case 9:
            cout<<endl<<"\tDecimal - Octal"<<endl;
            decimal_octal(IngresarUnNumero());
            break;
        case 10:
            cout<<endl<<"\tOctal - Decimal"<<endl;
            octal_decimal(IngresarUnNumero());
            break;
        case 11:
            cout<<endl<<"\tDecimal - Hexadecimal"<<endl;
            decimal_hexadecimal(IngresarUnNumero());
            break;
        case 12:
            cout<<endl<<"\tHexadecimal - Decimal"<<endl;
            cout<<endl<<"Ingrese un numero: ";
            cin>> n1;
            cin.ignore();
            ptr1 = &n1[0];
            hexadecimal_decimal(ptr1, strlen(ptr1));
            break;

        case 13:
            cout<< endl<<"FIN DEL PROGRAMA"<<endl;
            break;
        default:
        	cout<< endl<<"ERROR: ingrese valor valido"<<endl;
    }
}


bool Ingresar(){
    bool ban = false;
    cout<< endl<<"Ingrese numero 1: ";
    cin>> n1;
    cin.ignore();
    ptr1 = &n1[0];

    cout<< endl<<"Ingrese numero 2: ";
    cin>> n2;
    cin.ignore();
    ptr2 = &n2[0];

    if(Validacion(ptr1) && Validacion(ptr2)){
        ban=true;
    }
    return ban;
}

bool Validacion(char* num){
	bool resul = false;

	if(char(*num)>=48 && char(*num)<=57){
        cout<< endl<< "El dato ingresado ES un numero"<<endl;
        resul = true;
    }else{
        cout<< endl<<"El dato ingresado NO ES un numero"<<endl<<"Ingrese numero valido"<<endl;
    }
    return resul;
}

double *IngresarUnNumero(){

    do{
        cout<<endl<<"Ingrese un numero: ";
        cin>> n1;
        ptr1 = &n1[0];
        numeroC= atof(n1);
        ptrnumeroC = &numeroC;

    }while(!Validacion(ptr1));

    return ptrnumeroC;
}

int caracterHexadecimalADecimal(char caracter) {
  if (isdigit(caracter)){
    return caracter - '0';
  }
    return 10 + (toupper(caracter) - 'A');
}

void Pausar(){
    system("pause>>cls");
}

