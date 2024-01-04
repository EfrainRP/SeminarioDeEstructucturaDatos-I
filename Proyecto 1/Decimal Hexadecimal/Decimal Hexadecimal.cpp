//Efrain Robles Pulido
#include <iostream>
#include <cstdlib>

using namespace std;

void Hexadecimal (int* hex);

int main() {
    system("cls");
    int dec(0);
    int *a_ptr = NULL;
    cout<<"Ingrese el numero: ";
    cin>>dec;
    a_ptr = &dec;
    Hexadecimal (a_ptr);
    return 0;
    }

void Hexadecimal (int *hex) {
    int dig[20],residuo,resultado,i,j;

    do{
        residuo=*hex%16;
        resultado=*hex/16;
        dig[i]=residuo;
        *hex=resultado;
        i++;
    }while(resultado>16);

    dig[i]=resultado;

    cout<<"\nNumero hexadecimal es: ";
    for(j=i;j>=0;j--){
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
    cout<<endl;
}
