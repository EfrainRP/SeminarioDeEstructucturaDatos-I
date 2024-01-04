#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include <random>
#include <chrono>
#include <functional>

using namespace std;
using namespace std::chrono;

class Nodo{
	private:
		int cont;
        string nombre;
        string destino;
        int ID;
        string fecha;
        int ticket;
        int maleta;

		Nodo *siguiente;

	public:
		bool vacia(Nodo*);
		void comprarBoleto(Nodo*&,Nodo*&,int);
		int recogerBoleto(Nodo*&,int);
		void pop(Nodo*&,Nodo*&);
		void salirBoleto(int);
		void asientoReservado(Nodo*&,int);
		void revisionMaletas(Nodo*&,int);
		void salirRevisionMaletas(Nodo*&,int);
		void abordarAvion(Nodo*&,int);
		void vuelo();
		void desabordarAvion(int);
		void pedirUber(Nodo*&,int);
		bool validarDatos(char[]);
		void gotoxy(int,int);
		int enterValue();
		bool Validation(char*);
		void Menu();
};

bool Nodo::vacia(Nodo* frente){
	return (frente == NULL)? true : false;
}

void Nodo::gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void Nodo::comprarBoleto(Nodo *&frente, Nodo *&fin, int num){
	Nodo *nuevo_nodo = new Nodo();

	cout<<endl<<"Nombre del Pasajero "<<num<<": ";
	cin>>nuevo_nodo->nombre;

	nuevo_nodo->destino = "Canada";
	nuevo_nodo->fecha = "17/03/22";

	std::default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0,5);
    auto rand = bind(distribution, generator);
	nuevo_nodo->maleta = rand();

	/*default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(1111,9999);
    auto rand = bind(distribution, generator);
	nuevo_nodo->ID = rand();
	nuevo_nodo->ticket = rand();*/

	nuevo_nodo->siguiente = NULL;

	if(vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;

}

int Nodo::recogerBoleto(Nodo *&frente, int cont){
	system("cls");
	Nodo *temp = frente;
	int ban=0, i=0,rango=50;

	cout<<"\n\t\t''AEROPUERTO INTERNACIONAL DE GUADALAJARA''"<<endl<<endl;
	do{
		cout<<"Pasajero "<<temp->cont<<" | "<<temp->nombre<<" | Maletas "<<temp->maleta<<"    "<<endl;
		temp = temp->siguiente;
	}while(temp != NULL);

		gotoxy(55, 8); cout<<"  ___________";
		gotoxy(55, 9); cout<<"  |    O    |";
		gotoxy(55, 10); cout<<"  |   /|\\   |";
		gotoxy(55, 11); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
		gotoxy(55, 12); printf("%c%c  BOLETOS  %c%c",176,176,176,176);

		for(int j=0;j<cont;j++){
			for(i=0; i<rango;i++){
				gotoxy(i,9); cout<<"  "<<j+1;
				gotoxy(i,10); cout<<"  O";
				gotoxy(i,11); cout<<" /|\\";

				if(ban == 1){
					gotoxy(i,12); cout<<" / ";
					ban = 0;
				}
				else{
					gotoxy(i,12); cout<<"   \\";
				    ban = 1;
				}
				Sleep(80);
			}
			if(i >= 10){
				rango -= 10; cout<<"\\ ";
			}
		}
		return rango;
}

void Nodo::pop(Nodo *&frente, Nodo *&fin){
	if(vacia(frente) == false){
		Nodo *aux = frente;
		if(frente = fin){
			frente == NULL;
			fin == NULL;
		}
		else{
			frente = frente->siguiente;
		}
		delete aux;
	}
	else{
		cout<<"Todos a Bordo!"<<endl;
	}
}

void Nodo::salirBoleto(int rango){
	int aux = rango;
	for(int i=rango; i<=50; i+=10){
		gotoxy(i,9); cout<<"      ";
	}
	for(int i=aux; i<=50; i+=10){
		gotoxy(i, 9); cout<<"     ";
		gotoxy(i, 10); cout<<"     ";
		gotoxy(i, 11); cout<<"     ";
		gotoxy(i, 12); cout<<"     ";
		Sleep(1500);
	}
}

void Nodo::asientoReservado(Nodo *&frente, int cont){
	system("cls");
	cout<<"\n\t\t\t  Vuelo con Destino: Canada"<<endl;
	srand(time(NULL));
	int random;
	Nodo *temp = frente;
	while(temp!=NULL){
		random = 1+rand()%(101-1);
		cout<<"\n\tPasajero "<<temp->cont<<": "<<endl<<endl;
		cout<<"Nombre: "<<temp->nombre<<endl;
		cout<<"Equipaje: "<<temp->maleta<<" maletas"<<endl;
		cout<<"Hora de Salida: 6:00 pm"<<endl;
		cout<<"Asiento: "<<random;
		temp = temp->siguiente;
		cout<<"\n\n";
	}
	cout<<endl<<endl;
	system("pause");
}

void Nodo::revisionMaletas(Nodo *&frente, int cont){
	system("cls");
	Nodo *temp = frente;
	int ban=0, i=0, rango=50;
	temp = frente;
	cout<<"\n\t\t\t\tArea de Revision: "<<endl<<endl;
	while(temp!=NULL){
		cout<<"\nPasajero "<<temp->cont<<" | "<<"Nombre: "<<temp->nombre<<" | "<<"Cantidad de Maletas: "<<temp->maleta;
		temp = temp->siguiente;
	}
	gotoxy(60, 10); cout<<"  ___________";
	gotoxy(60, 11); cout<<"  /   ___   \\";
	gotoxy(60, 12); cout<<"  |    O    |";
	gotoxy(60, 13); cout<<"  |   /|\\   |";
	gotoxy(60, 14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(60, 15); printf("%c%c  REVISION  %c%c",219,219,219,219,219);

	for(int j=0; j<cont; j++){
		for(i=0;i<rango;i++){
			gotoxy(i, 12); cout<<"  "<<j+1;
			gotoxy(i, 13); cout<<"  O";
			gotoxy(i, 14); cout<<" /|\\";

			if(ban == 1){
					gotoxy(i,15); cout<<" / ";
					ban = 0;
			}
			else{
					gotoxy(i,15); cout<<"   \\";
				    ban = 1;
			}
			Sleep(60);
		}
		if(i >= 10){
			rango -= 10; cout<<"\\ ";
		}
	}
	cout<<endl;
}

void Nodo::salirRevisionMaletas(Nodo *&frente, int rango){
	Nodo *temp = frente;
	srand(time(NULL));
	int maletero = 0,aux;
	aux=rango;
	for(int i=rango; i<=50; i += 10){
		gotoxy(i, 12); cout<<"     ";
	}
	for(int i=aux; i<=50; i += 10){
		gotoxy(i, 13); cout<<"      ";
		gotoxy(i, 14); cout<<"      ";
		gotoxy(i, 15); cout<<"      ";
		maletero = rand()%20;

		if(maletero >=0 and maletero <=5){
			Sleep(1200);
		}
		else if(maletero >= 6 and maletero <= 10){
				Sleep(1800);
		}
		else{
			Sleep(2400);
		}
	}
	cout<<endl;
}

void Nodo::abordarAvion(Nodo *&frente, int cont){
	system("cls");
	int aux = 9, i;
	cout<<"\n\t\t\tABORDAR AVION "<<endl;
		gotoxy(0,1); cout<<"     ____\n";
		gotoxy(0,2); cout<<"     \\  `.\n";
		gotoxy(0,3); cout<<"      \\   `.\n";
		gotoxy(0,4); cout<<"       \\    `.\n";
		gotoxy(0,5); cout<<"        \\     `.\n";
		gotoxy(0,6); cout<<"         \\_________________________________.-~|~~-._\n";
		gotoxy(0,7); cout<<"         \\                                ---'-----`-._\n";
		gotoxy(0,8); cout<<"         /""""""""/             _...---------..               ~-._________\n";
		gotoxy(0,9); cout<<"        //     .`_________  .-`         \\ .-~           /\n";
		gotoxy(0,10); cout<<"      //    .'       ||__.~             .-~_____________/\n";
		gotoxy(0,11); cout<<"      //___.`           .~            .-~\n";
		gotoxy(0,12); cout<<"                      .~           .-~\n";
		gotoxy(0,13); cout<<"                    .~         _.-~\n";
		gotoxy(0,14); cout<<"                    `-_____.-~'\n";

	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;
	cout<<" \t    |       |"<<endl;

	for(int j=0; j<cont;j++){
		for(i=20;i>aux; i--){
			gotoxy(14, i+1); cout<<"  O";
			gotoxy(14, i+2); cout<<" /|\\";
			gotoxy(14, i+3); cout<<" / \\";
			gotoxy(14, i+4); cout<<"     ";
			Sleep(150);
		}
		if(i <= 12){
			aux += 3;
		}
	}
	aux = 9;
	for(i=20; i>aux; i -= 3){
		gotoxy(14, i); cout<<"   ";
		gotoxy(14, i+1); cout<<"    ";
		gotoxy(14, i+2); cout<<"    ";
		gotoxy(14, i+3); cout<<"    ";
		Sleep(1000);
	}
}

void Nodo::vuelo(){
	system("cls");
	cout<<"\n\t\t\tHORA DE DESPEGUE: 6:00 pm"<<endl;
	cout<<"\n\t\t\tHORA DE DESTINO: 12:48 am"<<endl;
	int i, rango = 50;
	for(i=0;i<rango;i++){
		gotoxy(i,16); cout<<"     ____\n";
		gotoxy(i,17); cout<<"     \\  `.\n";
		gotoxy(i,18); cout<<"      \\   `.\n";
		gotoxy(i,19); cout<<"       \\    `.\n";
		gotoxy(i,20); cout<<"        \\     `.\n";
		gotoxy(i,21); cout<<"         \\_________________________________.-~|~~-._\n";
		gotoxy(i,22); cout<<"         \\                                ---'-----`-._\n";
		gotoxy(i,23); cout<<"         /""""""""/             _...---------..               ~-._________\n";
		gotoxy(i,24); cout<<"        //     .`_________  .-`         \\ .-~           /\n";
		gotoxy(i,25); cout<<"      //    .'       ||__.~             .-~_____________/\n";
		gotoxy(i,26); cout<<"      //___.`           .~            .-~\n";
		gotoxy(i,27); cout<<"                      .~           .-~\n";
		gotoxy(i,28); cout<<"                    .~         _.-~\n";
		gotoxy(i,29); cout<<"                    `-_____.-~'\n";
		Sleep(120);
	}
	if(i >= 20){
		rango-=33;
	}
}

void Nodo::desabordarAvion(int cont){
	system("cls");
	cout<<"\n\t\t\t\tLLEGADA:"<<endl;

	gotoxy(0,1); cout<<"     ____\n";
	gotoxy(0,2); cout<<"     \\  `.\n";
	gotoxy(0,3); cout<<"      \\   `.\n";
	gotoxy(0,4); cout<<"       \\    `.\n";
	gotoxy(0,5); cout<<"        \\     `.\n";
	gotoxy(0,6); cout<<"         \\_________________________________.-~|~~-._\n";
	gotoxy(0,7); cout<<"         \\                                ---'-----`-._\n";
	gotoxy(0,8); cout<<"         /""""""""/             _...---------..               ~-._________\n";
	gotoxy(0,9); cout<<"        //     .`_________  .-`         \\ .-~           /\n";
	gotoxy(0,10); cout<<"      //    .'       ||__.~             .-~_____________/\n";
	gotoxy(0,11); cout<<"      //___.`           .~            .-~\n";
	gotoxy(0,12); cout<<"                      .~           .-~\n";
	gotoxy(0,13); cout<<"                    .~         _.-~\n";
	gotoxy(0,14); cout<<"                    `-_____.-~'\n";


	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;

	int aux = 20, i;
	for(int j=0; j<cont; j++){
		for(i=0; i<aux; i++){
			gotoxy(13, i+10); cout<<"      ";
			gotoxy(13, i+11); cout<<"   O "<<char(191);
			gotoxy(13, i+12); cout<<"  /|\\";
			gotoxy(13, i+13); cout<<"  / \\"<<char(178);
			Sleep(180);
		}
		if(i >= 10){
			aux -= 3;
		}
	}
	aux = 20;
	for(i=0; i<aux; i += 3){
		gotoxy(13, i+11); cout<<"     ";
		gotoxy(13, i+12); cout<<"      ";
		gotoxy(13, i+13); cout<<"      ";
		gotoxy(13, i+14); cout<<"      ";
		Sleep(800);
	}
}

void Nodo::pedirUber(Nodo *&frente, int cont){
	system("cls");
	Nodo *temp = frente;
	int ban=0,i=0,rango=50;

	cout<<"\t\tWelcome to Canada - Enjoy your Journey! "<<endl;

	for(int j=0; j<cont; j++){
		for(i=0;i<rango;i++){
			gotoxy(i, 9); cout<<"  "<<j+1;
			gotoxy(i, 10); cout<<"  O";
			gotoxy(i, 11); cout<<" /|\\";

			if(ban == 1){
				gotoxy(i,12); cout<<" / ";
				ban = 0;
			}
			else{
				gotoxy(i,12); cout<<"   \\";
				ban = 1;
			}
			Sleep(60);
		}
		if(i >= 10){
			rango -= 10; cout<<"\\ ";
		}
	}

	int aux = rango;
	rango = 50;
	for(i=0; i<rango; i++){
		gotoxy(i, 16); cout<<"       _____      ";
		gotoxy(i, 17); cout<<"      /  O  \\     ";
		gotoxy(i, 18); cout<<"  ___/__ |-_ \\______";
		gotoxy(i, 19); cout<<" |()   __ UBER __ ()|";
		gotoxy(i, 20); cout<<" |__/  \\_____/  \\___|";
		gotoxy(i, 21); cout<<"    \\_/      \\_/    ";
		Sleep(90);


	}
	if(i >= 10){
		rango -= 25;
	}
	cout<<"\n";

	for(int i=rango; i<=50; i += 10){
		gotoxy(i, 9); cout<<"     ";
	}
	for(int i=aux; i<=50; i += 10){
		gotoxy(i, 9); cout<<"     ";
		gotoxy(i, 10); cout<<"     ";
		gotoxy(i, 11); cout<<"     ";
		gotoxy(i, 12); cout<<"     ";
		Sleep(1200);

	}

	int aux2 = 80;
	for(i=50; i<aux2; i++){
		gotoxy(i, 16); cout<<"       _____      ";
		gotoxy(i, 17); cout<<"      /  O  \\     ";
		gotoxy(i, 18); cout<<"  ___/__ |-_ \\______";
		gotoxy(i, 19); cout<<" |() ___ UBER __  ()|";
		gotoxy(i, 20); cout<<" |__/  \\_____/  \\__|";
		gotoxy(i, 21); cout<<"    \\_/      \\_/    ";
		Sleep(90);
		system("cls");
	}
	if(i >= 10){
		rango -= 25;
	}

}

bool Nodo::validarDatos(char cant[]){
	bool ban = false;

	if((int(cant[0]) >=48 ) and (int(cant[0]) <= 57)){
		ban = true;
	}
	return ban;
}

void Nodo::Menu(){
	Nodo *frente = NULL,*fin = NULL, pila = NULL;
	int aux, num=0, cantidad=0, cont2=0;
	char cant[256];

		cout<<"\n\n\t\t''AEROPUERTO INTERNACIONAL DE GUADALAJARA''"<<endl<<endl<<endl;
		cout<<"Ingrese la Cantidad de Pasajeros a Abordar: ";
		cin>>cant;
			do{
				num++;
				comprarBoleto(frente, fin, num);
				cantidad--;
				cont2++;
			}while(cantidad != 0);

			cout<<"\n------------------------------------"<<endl<<endl;
			cout<<"\tGracias Por su Compra! "<<endl<<endl;
			cout<<"\tDisfrute su Viaje. . . "<<endl<<endl;
			cout<<"-------------------------------------"<<endl<<endl;;

			system("pause");

			aux = recogerBoleto(frente, cont2);
			salirBoleto(aux);
			asientoReservado(frente, cont2);
			revisionMaletas(frente, cont2);
			salirRevisionMaletas(frente, aux);
			abordarAvion(frente, cont2);
			pop(frente, fin);
			vuelo();
			desabordarAvion(cont2);
			pedirUber(frente, cont2);
}

bool Nodo::Validation(char* num) {
    if((char)*num>=48 && (char)*num<=57) {
        cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
        }
    else {
        cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
        }
    }

int Nodo::enterValue() {
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


int main(){
	Nodo llamar;
	llamar.Menu();

	return 0;
}
