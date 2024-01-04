/*#include <iostream>
using namespace std;

int main (){
    int numero = 0;
    int *ptr = nullptr;//se declara un puntero
    cout<<"Ingrese un numero :"<<endl;
    cin>>numero;
    ptr = &numero;
    cout<<"Valor de la variable : "<<*ptr<<endl;
    cout<<"Direccion de la variable : "<<&ptr<<endl;

    return 0;
}*/
/*#include <iostream>
using namespace std;

void funcion(int *q);

int main() {
   int a;
   int *p;

   a = 100;
   p = &a;
   // Llamamos a funcion con un puntero
   funcion(p); // (1)
   cout << "Variable a: " << a << endl;
   cout << "Variable *p: " << *p << endl;
   // Llamada a funcion con la dirección de "a" (constante)
   funcion(&a);  // (2)
   cout << "Variable a: " << a << endl;
   cout << "Variable *p: " << *p << endl;

   return 0;
}

void funcion(int *q) {
   // Cambiamos el valor de la variable apuntada por
   // el puntero
   *q += 50;
   q++;
}*/
#include <iostream>
using namespace std;

void sumar(int *);

int main()
{
    int n = 4;
    sumar(&n);
    std::cout << n << std::endl;
    system("pause");
    return 0;
}
void sumar(int *x)
{
    *x = *x + 1;
    std::cout << *x << std::endl;
}