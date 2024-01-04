#include<iostream>

using namespace std;

int factorial(int *n){
    int i=*n;
    for(int x=1; x<i; x++){
        *n=x*(*n);
    }
    return *n;
}

int main(){
    int num;
    cout<<"Numero factorial"<<endl<<"Dame un numero a calcular:"<<endl;
    cin>>num;
    cout<<"El resultado es: "<<factorial(&num)<<endl;
    return 0;
}