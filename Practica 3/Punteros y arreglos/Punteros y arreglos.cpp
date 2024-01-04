//Efrain Robles Pulido
#include<iostream>
using namespace std;

int vector[]= {1,5,7,9,15,20};
int *P;

int main() {
    system("cls");
    P=&vector[0];

    for(int i=0; i<6; i++) {
        cout<<P[i]<<endl;
        }
    system("pause");
    return 0;
    }
