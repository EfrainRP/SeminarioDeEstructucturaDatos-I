#include <iostream>
#include <cstdlib>

using namespace std;

double *ptr1=NULL, *ptr2=NULL;
double numero1 = 0, numero2 = 0;

double* Suma(double *n1, double *n2) {
    double *res=(double*)malloc(sizeof(double));
    *res = *n1 + *n2;
    return res;
}

int main(int argc, char* argv) {
    system("cls");

    cout<<"Ingrese numero 1: ";
	cin>>numero1;

    cout<<"Ingrese numero 2: ";
    cin>>numero2;

    ptr1=&numero1;
    ptr2=&numero2;

    cout<<"Resultado: "<<*Suma(ptr1,ptr2);
    return 0;
}
