#include<iostream>
#include<stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;

 bool Validation(char* num) {
    if((char)*num>=48 && (char)*num<=57) {
        cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
        }
    else {
        cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
        }
    }

int enterValue() {
    int mydouble;
    char myChar[30], *ptrChar;
    do {
        cin>>myChar;
        ptrChar = &myChar[0];
        }
    while(!Validation(ptrChar));

    mydouble = atoi(ptrChar);

    return mydouble;
    }


class cola{
	private:
		int inicio,fin;
		 int dato[10];

	public:
	           cola();
	           int lleno();
	           int vacio();
               void llenar( );
               void consultar_inicio();
               void consultar_final();
               void mostrar_cola();
               void eliminar();


};
cola::cola(){
	fin=-1;
	inicio=0;
}
 void cola::llenar(){
 	int x;
	 if(lleno()==0){
	 	fin ++;
	 	cout<<"Ingrese valor:  ";
 		dato[fin]=enterValue();

	 }
 }

void cola::consultar_inicio(){
	if(vacio()==0){

		cout<<"\nEL inicio es  "<<dato[0]<<endl;
		system("pause");
	}
}

void cola::consultar_final(){
	if(vacio()==0){
		cout<<"\nEl final es  "<<dato[fin]<<endl;
		system("pause");
	}
}
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }


void cola::mostrar_cola(){
	int cont=1,i;
    if(vacio()==0){
        system("cls");

        for(i=fin;i>=0;i--){
            cont+=4;
            gotoxy(cont,2);

            if(i==fin){
                printf("%c%c%c%c%c ", 201,205,205,205,187);}//impresion de cerradura
                else{
                    printf("%c%c%c%c%c ",203,205,205,205,187);}//impresion de interseccion
                gotoxy(cont,3), printf("%c ",186);   cout<<dato[i];  printf(" %c",186);
                if(i==fin){
                        gotoxy(cont,4);printf("%c%c%c%c%c\n",200,205,205,205,188);}
                else{
                    gotoxy(cont,4);printf("%c%c%c%c%c\n",202,205,205,205,188);}
            }
            cout<<"       ^ \n       | \n       | \n  Final";
            gotoxy(cont,5);cout<<"   ^";gotoxy(cont,6);cout<<"   |";gotoxy(cont,7);cout<<"  Inicio";
    }
    cout<<endl<<endl;

}

void cola::eliminar(){
	if(vacio()==0){
		for(int i=0;i<=fin;i++){
			dato[i]=dato[i+1];
		}
		dato[fin]=-1;
		fin--;
	}
}

int cola::lleno(){
	if(fin==9){
		cout<<"LA COLA ESTA LLENA"<<endl;
		system("pause");
		return 1;
	}else{
		return 0;
	}
}
int cola::vacio(){
	if(fin==-1){
		cout<<"LA COLA ESTA VACIA"<<endl;
		system("pause");
		return 1;
	} else{
		return 0;
	}
}




int main(){
   int dato;
   	int opcion;
   	cola c;
do{
	system("cls");
    c.mostrar_cola();
    cout<<""<<endl;
    cout<<"Menu"<<endl;
   	cout<<"[1]Encolar(push)"<<endl;
	cout<<"[2]Mostrar inicio"<<endl;
	cout<<"[3]Mostrar fin"<<endl;
	cout<<"[4]Des-Encolar(pop)"<<endl;
	cout<<"[5]Mostrar cola"<<endl;
	cout<<"[6].Salir"<<endl;

   	switch(opcion=enterValue()){
   		case 1:
   		        c.llenar();
   		        break;
   		case 2: c.consultar_inicio();
		        break;
		case 3: c.consultar_final();
		        break;
   		case 4: c.eliminar();
		          break;
		case 5:
		    system("cls");
		    c.mostrar_cola();
		    system("pause");
		         break;

	   }

       }while(opcion!=6);
   }
