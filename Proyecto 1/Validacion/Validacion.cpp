#include <iostream>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool Validar_Numeros(double* dato);
double *ptr=NULL;
int main(int argc, char** argv) {
        system("cls");
        double a;
        cout<<"Ingresa un numero: ";
        cin>>a;
        ptr=&a;
        if(Validar_Numeros(ptr))
                cout<<"El caracter ES numero";

        else
                cout<<"El caracter NO ES numero";
                 system("pause>>cls");
        return 0;
}

bool Validar_Numeros(double* dato){
   bool ban=false;
        if(char(*dato)>=48 && char(*dato)<=57){
                ban=true;
        }
}
