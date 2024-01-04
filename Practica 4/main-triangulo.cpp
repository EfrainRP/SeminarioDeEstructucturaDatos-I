#include <iostream>

using namespace std;

class Triangulo{
private:
    double base;
    double altura;
    double area;

public:
    void setBase(double);
    void setAltura(double);

    double getBase();
    double getAltura();

    void calcularArea();
    double getArea();
};

void Triangulo::setBase(double b){
    this->base = b;
}

void Triangulo::setAltura(double h){
    this->altura = h;
}

double Triangulo::getBase(){
    return this->base;
}

double Triangulo::getAltura(){
    return this->altura;
}

double Triangulo::getArea(){
    return this->area;
}
void Triangulo::calcularArea(){
    this->area = (this->base*this->altura)/2;
}
double b = 0, altu = 0;
int opc = 0;
int main(){
    Triangulo t;

    do{
        system("cls");
        cout<<"Ingrese Base: " ;
        cin>>b;
        cout<<"Ingrese Altura: " ;
        cin>>altu;

        t.setBase(b);
        t.setAltura(altu);

        cout<<"Area: "<<t.getArea()<<endl;
        cout<<"Continuar 1-si 2-no"<<endl;
        cin>>opc;
    }while(opc!=2);
    return 0;
}
