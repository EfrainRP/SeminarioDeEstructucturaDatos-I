//Efrain Robles Pulido
#include <iostream>
using namespace std;

int mayor (int *num);//prototipo
int vector[]= {78,5,7,9,20,15};

int main(){
    int *pv;
    pv = vector;//asignamos todo el arreglo hacia el apuntador pv

    int m = mayor(pv);

    cout<<"El numero mayor es:" << m;
    return 0;
}

int mayor(int *num){
    int may = num[0];

    for(int i=1; i<6; i++) {
        if(num[i] > may){
            may = num[i];
        }
    }
    return may;
}
