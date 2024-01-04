//Efrain Robles Pulido
#include <iostream>
#include <cstdlib>

using namespace std;

void binario(int *deci);

int main(int argc, char* argv) {
    system("cls");
    int num;
    int *ptr = NULL;

    cout<<"Ingrese numero: ";
    cin>>num;
    ptr = &num;
    binario(ptr);
    return 0;
}

void binario(int *deci) {
    int sizechart(12),i(0);
    int bin[sizechart];
    for(int i(0); i < sizechart; i++) {
        bin[i]=*deci%2;
        *deci=*deci/2;
    }
    cout<<"Numero binario es:";
    for(int i(sizechart-1); i >= 0; i--) {
        cout<<bin[i];
    }
    cout<<endl;
}
