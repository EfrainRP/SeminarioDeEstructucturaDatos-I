#include <iostream>
#include "Data.h"
#include<cstdlib>
#include<windows.h>
#include<ctime>
#define speed 50

using namespace std;

class Nodo {
    public:
        Data people;
        Nodo* next;
    };
///////////////////////////////////////////////////////     PILA
bool pila_vacia(Nodo *&pila) {
    return (pila == NULL)? true : false;
    };

void push(Nodo *&pila, Data& d) {
    Nodo *temp = new Nodo();
    temp->people = d;
    temp->next = pila;
    pila = temp;
    };

void pop(Nodo *&pila) {
    Nodo *temp = pila;
    Data d;
    d = temp->people;
    pila = temp->next;
    delete(temp);


    };
///////////////////////////////////////////////////////        COLA
bool cola_vacia(Nodo *frente) {
    return (frente == NULL)? true : false;
    };

void push(Nodo *&frente,Nodo *&fin, Data& d) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->people = d;
    nuevo_nodo->next = NULL;

    if(cola_vacia(frente)) {
        frente = nuevo_nodo;
        }
    else {
        fin->next = nuevo_nodo;
        }

    fin = nuevo_nodo;
    };

void pop(Nodo *&frente,Nodo *&fin) {
    Nodo *aux = frente;

    if(frente == fin) {
        frente = NULL;
        fin = NULL;
        }
    else {
        frente = frente->next;
        }
    delete aux;

    };

void display(Nodo *frente) {

    Nodo *temp = frente;

    if(!cola_vacia(temp)){
    while(temp!=NULL) {
        cout<<temp->people.toString();
        temp=temp->next;
        cout << endl;
        }
    }else{
        cout<<"Cola Vacia"<<endl<<endl;
    }

    };
/////////////////////////////////////////////////////////
void hideCursor(){
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
    hideCursor();
}

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

void pedirUber(Nodo *&frente, Nodo*&fin, int cont){
	system("cls");
	Nodo *auxptr=frente;
	Nodo *temp = frente, *tempF = fin, *temp2=nullptr,*temp2F=nullptr;
	int ban=0,i=0, j, c=0,rango=75, aux=75;

	cout<<"\t\tWelcome to Canada - Enjoy your Journey! "<<endl;
    for(j=0;j<cont;j++){
	for(i=0; i<rango;i++){
				gotoxy(i,9); cout<<"  "<<auxptr->people.getCont();
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
				Sleep(speed);
			}
			if(i >= 10){
				rango -= 10;
				gotoxy(i,12); cout<<"/ \\";
			}
			auxptr = auxptr->next;
}

	for(i=0; i<=65; i++){
		gotoxy(i, 16); cout<<"       _____      ";
		gotoxy(i, 17); cout<<"      /  O  \\     ";
		gotoxy(i, 18); cout<<"  ___/__ |-_ \\______";
		gotoxy(i, 19); cout<<" |() __  UBER  __  ()|";
		gotoxy(i, 20); cout<<" |__/  \\_____/  \\___|";
		gotoxy(i, 21); cout<<"    \\_/      \\_/    ";
		Sleep(30);
	}
	Sleep(800);
    gotoxy(rango+10, 9); cout<<"      ";
    gotoxy(rango+10, 10); cout<<"     ";
    gotoxy(rango+10, 11); cout<<"     ";
    gotoxy(rango+10, 12); cout<<"     ";

    while(c<cont){
        temp2=temp;
        temp2F=tempF;

        if(temp2!=nullptr){
        gotoxy(65,4);cout<<"Entro al Uber: "<<temp2->people.getName();
        temp2=temp2->next;
        }

        while(temp2 != nullptr) {
            gotoxy(aux,9); cout<<" "<<temp2->people.getCont();
            gotoxy(aux,10); cout<<" O";
            gotoxy(aux,11); cout<<"/|\\";
            gotoxy(aux,12); cout<<"/ \\";
            aux-=10;
            temp2=temp2->next;
        }
        gotoxy(aux, 9); cout<<"      ";
        gotoxy(aux, 10); cout<<"     ";
        gotoxy(aux, 11); cout<<"     ";
        gotoxy(aux, 12); cout<<"     ";

        aux=75;
        Sleep(1200);
        pop(temp,tempF);

        for(i=65;i<140;i++){
		gotoxy(i, 16); cout<<"       _____      ";
		gotoxy(i, 17); cout<<"      /  O  \\     ";
		gotoxy(i, 18); cout<<"  ___/__ |-_ \\______";
		gotoxy(i, 19); cout<<" |() ___ UBER  __ ()|";
		gotoxy(i, 20); cout<<" |__/  \\_____/  \\__|";
		gotoxy(i, 21); cout<<"    \\_/      \\_/    ";
		Sleep(30);
        }
        gotoxy(i, 16); cout<<"                          ";
		gotoxy(i, 17); cout<<"                          ";
		gotoxy(i, 18); cout<<"                          ";
		gotoxy(i, 19); cout<<"                          ";
		gotoxy(i, 20); cout<<"                          ";
		gotoxy(i, 21); cout<<"                          ";
		//Elimina mensaje
        gotoxy(0, 4); cout<<"                                                                                                                    ";

        rango+=10;
        gotoxy(rango, 9); cout<<"      ";
        gotoxy(rango, 10); cout<<"     ";
        gotoxy(rango, 11); cout<<"     ";
        gotoxy(rango, 12); cout<<"     ";

        c++;
        if(c!=cont){
        for(i=0; i<=65; i++){
		gotoxy(i, 16); cout<<"       _____      ";
		gotoxy(i, 17); cout<<"      /  O  \\     ";
		gotoxy(i, 18); cout<<"  ___/__ |-_ \\______";
		gotoxy(i, 19); cout<<" |() __  UBER  __  ()|";
		gotoxy(i, 20); cout<<" |__/  \\_____/  \\___|";
		gotoxy(i, 21); cout<<"    \\_/      \\_/    ";
		Sleep(30);
        }
	}
}
    gotoxy(75, 9); cout<<"      ";
    gotoxy(75, 10); cout<<"     ";
    gotoxy(75, 11); cout<<"     ";
    gotoxy(75, 12); cout<<"     ";


}

void Vuelo(){
	int i, y=1, rango = 90;

	for(i=0;i<rango;i++){
        system("cls");
        cout<<"\n\t\t\t\t SALIDA:"<<endl;
    gotoxy(5,3); cout<<"       ___    ___    ___";
    gotoxy(5,4); cout<<"     _/   \\__/   \\__/   \\_";
    gotoxy(5,5); cout<<"    /                     \\";
    gotoxy(5,6); cout<<"    \\                     /";
    gotoxy(5,7); cout<<"    /                     \\";
    gotoxy(5,8); cout<<"    \\_     __     __     _/";
    gotoxy(5,9); cout<<"      \\___/  \\___/  \\___/";

    gotoxy(0,22); cout<<"       ___    ___    ___";
    gotoxy(0,23); cout<<"     _/   \\__/   \\__/   \\_";
    gotoxy(0,24); cout<<"    /                     \\";
    gotoxy(0,25); cout<<"    \\                     /";
    gotoxy(0,26); cout<<"    /                     \\";
    gotoxy(0,27); cout<<"    \\_     __     __     _/";
    gotoxy(0,28); cout<<"      \\___/  \\___/  \\___/";

    gotoxy(68,8); cout<<"       ___    ___    ___";
    gotoxy(68,9); cout<<"     _/   \\__/   \\__/   \\_";
    gotoxy(68,10); cout<<"    /                     \\";
    gotoxy(68,11); cout<<"    \\                     /";
    gotoxy(68,12); cout<<"    /                     \\";
    gotoxy(68,13); cout<<"    \\_     __     __     _/";
    gotoxy(68,14); cout<<"      \\___/  \\___/  \\___/";

    gotoxy(60,29); cout<<"       ___    ___    ___";
    gotoxy(60,30); cout<<"     _/   \\__/   \\__/   \\_";
    gotoxy(60,31); cout<<"    /                     \\";
    gotoxy(60,32); cout<<"    \\                     /";
    gotoxy(60,33); cout<<"    /                     \\";
    gotoxy(60,34); cout<<"    \\_     __     __     _/";
    gotoxy(60,35); cout<<"      \\___/  \\___/  \\___/";

    //gotoxy(i,10+y); cout<<"         ";
            gotoxy(i,11+y); cout<<"  ____\n";
            gotoxy(i,12+y); cout<<"  \\  `.\n";
            gotoxy(i,13+y); cout<<"   \\   `.\n";
            gotoxy(i,14+y); cout<<"    \\    `.\n";
            gotoxy(i,15+y); cout<<"     \\Canada`.\n";
            gotoxy(i,16+y); cout<<"      \\       `.________________________.-~|~~-._\n";
            gotoxy(i,17+y); cout<<"       \\_______                         ---'-----`-._\n";
            gotoxy(i,18+y); cout<<"       /       /             _...---------..          ~-._________\n";
            gotoxy(i,19+y); cout<<"      //     .`_________  .-`         \\ .-~            /\n";
            gotoxy(i,20+y); cout<<"     //    .'       ||__.~             .-~_____________/\n";
            gotoxy(i,21+y); cout<<"    //___.`           .~            .-~\n";
            gotoxy(i,22+y); cout<<"                    .~           .-~\n";
            gotoxy(i,23+y); cout<<"                  .~         _.-~\n";
            gotoxy(i,24+y); cout<<"                 `-_____.-~'\n";
            //gotoxy(i,25+y); cout<<"                                 ";

		if(y==1){
            y=0;
		}else if(y==0){
            y=1;
            //Sleep(200);
		}
		Sleep(100);

	}
}

void desabordarAvion(int cont, Nodo*&pila, Nodo*&frente, Nodo*&fin){
	system("cls");
	//Nodo* temp = pila;
	cout<<"\n\t\t\t\tLLEGADA:"<<endl;

	gotoxy(0,1); cout<<"     ____\n";
	gotoxy(0,2); cout<<"     \\  `.\n";
	gotoxy(0,3); cout<<"      \\   `.\n";
	gotoxy(0,4); cout<<"       \\    `.\n";
	gotoxy(0,5); cout<<"        \\Canada `.\n";
	gotoxy(0,6); cout<<"         \\       `.________________________.-~|~~-._\n";
	gotoxy(0,7); cout<<"         \\_______                          ---'-----`-._\n";
	gotoxy(0,8); cout<<"         /       /             _...---------..           ~-._________\n";
	gotoxy(0,9); cout<<"        //     .`_________  .-`         \\ .-~            /\n";
	gotoxy(0,10); cout<<"      //    .'       ||__.~             .-~_____________/\n";
	gotoxy(0,11); cout<<"     //___.`           .~            .-~\n";
	gotoxy(0,12); cout<<"                     .~           .-~\n";
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
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;
	cout<<" \t    |         |"<<endl;

	int aux = 25, i;
	for(int j=0; j<cont; j++){
        if(!pila_vacia(pila)){
                    gotoxy(30, 16); cout<<"Salio: "<<pila->people.toString()<<endl;
                    push(frente,fin,pila->people);
                    pop(pila);
                }
		for(i=0; i<=aux; i++){
			gotoxy(13, i+10); cout<<"      ";
			gotoxy(13, i+11); cout<<"   O "<<char(191);
			gotoxy(13, i+12); cout<<"  /|\\"<<char(178);
			gotoxy(13, i+13); cout<<"  / \\"<<char(178);
			Sleep(110);
		}

		if(i >= 10){
			aux -= 3;
		}

	}
	aux = 25;
	//Elimina mensaje
    gotoxy(30, 16); cout<<"                                                                                                                           ";
	for(i=0; i<aux; i += 3){
		gotoxy(13, i+11); cout<<"     ";
		gotoxy(13, i+12); cout<<"      ";
		gotoxy(13, i+13); cout<<"      ";
		gotoxy(13, i+14); cout<<"      ";
		Sleep(300);
	}
}

void AbordarAvion(int cont, Nodo*&frente){
    system("cls");
    Nodo* temp = frente;
	int aux = 9, i,x,y=15,c=1, ban=0;
	cout<<"\n\t\t\tABORDAR AVION "<<endl;

		gotoxy(0,1); cout<<"     ____\n";
		gotoxy(0,2); cout<<"     \\  `.\n";
		gotoxy(0,3); cout<<"      \\   `.\n";
		gotoxy(0,4); cout<<"       \\     `.\n";
		gotoxy(0,5); cout<<"        \\Canada `.\n";
		gotoxy(0,6); cout<<"         \\         `.________________________.-~|~~-._\n";
		gotoxy(0,7); cout<<"         \\_______                            ---'-----`-._\n";
		gotoxy(0,8); cout<<"         /       /            _...---------..               ~-._________\n";
		gotoxy(0,9); cout<<"        //     .`_________  .-`         \\ .-~                /\n";
		gotoxy(0,10); cout<<"      //    .'       ||__.~             .-~_________________/\n";
		gotoxy(0,11); cout<<"     //___.`           .~            .-~\n";
		gotoxy(0,12); cout<<"                      .~           .-~\n";
		gotoxy(0,13); cout<<"                    .~         _.-~\n";
		gotoxy(0,14); cout<<"                   `-_____.-~'\n";

	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;
	cout<<" \t    |        |"<<endl;

	for(int j=0; j<cont;j++){
		for(i=35;i>aux; i--){
            gotoxy(14, i); cout<<"      ";
			gotoxy(14, i+1); cout<<"  O "<<char(191);
			gotoxy(14, i+2); cout<<" /|\\"<<char(178);
			gotoxy(14, i+3); cout<<" / \\"<<char(178);
			gotoxy(14, i+4); cout<<"     ";
			Sleep(120);

		}
		c++;
		if(i <= 31){
			aux += 5;
		}
	}
	Sleep(1000);

    gotoxy(14, aux); cout<<"       ";
    gotoxy(14, aux+1); cout<<"     ";
    gotoxy(14, aux+2); cout<<"     ";
    gotoxy(14, aux+3); cout<<"     ";
    gotoxy(14, aux+4); cout<<"     ";
    if(cont>5){
        gotoxy(30, 16); cout<<"Entro: "<<temp->people.toString()<<endl;
        temp=temp->next;
    }
    Sleep(1000);

	for(x=aux-5; x>9; x -= 5){

		gotoxy(14, x); cout<<"       ";
		gotoxy(14, x+1); cout<<"     ";
		gotoxy(14, x+2); cout<<"     ";
		gotoxy(14, x+3); cout<<"     ";
		gotoxy(14, x+4); cout<<"     ";

        gotoxy(30, 16); cout<<"Entro: "<<temp->people.toString()<<endl;
        temp=temp->next;

		Sleep(1000);
	}
		gotoxy(14, x+1); cout<<"     ";
		gotoxy(14, x+2); cout<<"     ";
		gotoxy(14, x+3); cout<<"     ";
		gotoxy(14, x+4); cout<<"     ";
		if(temp!=nullptr){
            gotoxy(30, 16); cout<<"Entro: "<<temp->people.toString()<<endl;
            temp=temp->next;
            }
            Sleep(1000);
        //Elimina mensaje
        gotoxy(30, 16); cout<<"                                                                                                                              ";
		Sleep(1000);

	}

void revisionMaletas(int cont, Nodo*&frente , Nodo*&fin, Nodo*& pila){

	int ban=0, i=0, rango=95, y=3, c=0, aux=95;
	Nodo *temp = frente, *tempF = fin, *temp2=temp,*temp2F=tempF, *temp3=nullptr,*temp3F=nullptr;

	cout<<"\n\t\t\t\tArea de Revision: "<<endl<<endl;

	for(int j=0;j<cont;j++){
    gotoxy(100, 7); cout<<"  ___________";
	gotoxy(100, 8); cout<<"  /         \\";
	gotoxy(100, 9); cout<<"  |    O    |";
	gotoxy(100, 10); cout<<"  |   /|\\   |";
	gotoxy(100, 11); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(100, 12); printf("%c%c  REVISION  %c%c",219,219,219,219,219);

			for(i=0; i<rango;i++){
				gotoxy(i,9); cout<<"  "<<j+1;
				gotoxy(i,10); cout<<"  O "<<char(191);
				gotoxy(i,11); cout<<" /|\\"<<char(178);

				if(ban == 1){
					gotoxy(i,12); cout<<" /  "<<char(178);
					ban = 0;
				}
				else{
					gotoxy(i,12); cout<<"   \\"<<char(178);
				    ban = 1;
				}
				Sleep(speed);
			}
			if(i >= 10){
				rango -= 10;
				gotoxy(i,12); cout<<"/ \\"<<char(178);
			}
		}

    Sleep(800);
    gotoxy(rango+10, 9); cout<<"       ";
    gotoxy(rango+10, 10); cout<<"      ";
    gotoxy(rango+10, 11); cout<<"      ";
    gotoxy(rango+10, 12); cout<<"      ";

    while(c<cont){
        temp2=temp;
        temp2F=tempF;

        if(temp2!=nullptr){
        gotoxy(0,4);cout<<"Revisado: "<<temp2->people.toString();
        push(pila, temp2->people);
        temp2=temp2->next;
        }
        while(temp2 != NULL ) {
            gotoxy(aux,9); cout<<" "<<temp2->people.getCont();
            gotoxy(aux,10); cout<<" O "<<char(191);
            gotoxy(aux,11); cout<<"/|\\"<<char(178);
            gotoxy(aux,12); cout<<"/ \\"<<char(178);
            aux-=10;
            temp2=temp2->next;
        }
        gotoxy(aux, 9); cout<<"       ";
        gotoxy(aux, 10); cout<<"      ";
        gotoxy(aux, 11); cout<<"      ";
        gotoxy(aux, 12); cout<<"      ";

        aux=95;
        Sleep(1200);
        push(temp3, temp3F, temp->people);
        pop(temp,tempF);

        if(cola_vacia(temp)){
            break;
        }

        rango+=10;
        gotoxy(rango, 9); cout<<"      ";
        gotoxy(rango, 10); cout<<"     ";
        gotoxy(rango, 11); cout<<"     ";
        gotoxy(rango, 12); cout<<"     ";

        c++;
    }
    gotoxy(95, 9); cout<<"      ";
    gotoxy(95, 10); cout<<"     ";
    gotoxy(95, 11); cout<<"     ";
    gotoxy(95, 12); cout<<"     ";
    //Elimina mensaje
    gotoxy(0,4); cout<<"                                                                                                                              ";

    Sleep(1000);

    frente=temp3;
    fin=temp3F;

	//return rango;
}

void recogerBoleto(Nodo *&frente, Nodo *&fin, int cont, Nodo *& pila){
	system("cls");
	Nodo *temp = frente, *tempF = fin, *temp2=nullptr,*temp2F=nullptr, *temp3=nullptr, *temp3F=nullptr;
	int ban=0, i=0,rango=95, j, c=0, aux=95;;

	cout<<"\n\t\t''AEROPUERTO INTERNACIONAL DE GUADALAJARA''"<<endl<<endl;

		gotoxy(100, 8); cout<<"  ___________";
		gotoxy(100, 9); cout<<"  |    O    |";
		gotoxy(100, 10); cout<<"  |   /|\\   |";
		gotoxy(100, 11); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
		gotoxy(100, 12); printf("%c%c  BOLETOS  %c%c",176,176,176,176);

		for(j=0;j<cont;j++){
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
				Sleep(speed);
			}
			if(i >= 10){
				rango -= 10;
				gotoxy(i,12); cout<<"/ \\";
			}
		}
    gotoxy(rango+10, 9); cout<<"      ";
    gotoxy(rango+10, 10); cout<<"     ";
    gotoxy(rango+10, 11); cout<<"     ";
    gotoxy(rango+10, 12); cout<<"     ";

    while(c<cont){
        temp2=temp;
        temp2F=tempF;
        while(temp2!= NULL ) {
            gotoxy(aux,9); cout<<" "<<temp2->people.getCont();
            gotoxy(aux,10); cout<<" O";
            gotoxy(aux,11); cout<<"/|\\";
            gotoxy(aux,12); cout<<"/ \\";
            aux-=10;
            temp2=temp2->next;
        }
        aux=95;
        Sleep(900);
        push(temp3, temp3F, temp->people);
        pop(temp,tempF);

        rango+=10;
        gotoxy(rango, 9); cout<<"      ";
        gotoxy(rango, 10); cout<<"     ";
        gotoxy(rango, 11); cout<<"     ";
        gotoxy(rango, 12); cout<<"     ";
        c++;
    }
    Sleep(1000);
    system("cls");
    frente=temp3;
    fin=temp3F;
}

int BuyTicket(Nodo* &frente, Nodo* &fin){
    int cont=0, cant;
    string myStr;
    Data people;

    cout<<"Introduzca la cantidad de pasajeros: ";
    cant=enterValue();
    do{
	cout<<endl<<"Nombre del Pasajero "<<++cont<<": ";
	people.setCont(cont);

	cin>>myStr;
	cin.ignore();
	people.setName(myStr);

	push(frente,fin,people);
    }while(cont!=cant);

    cout<<"\n------------------------------------"<<endl<<endl;
    cout<<"\tGracias Por su Compra! "<<endl<<endl;
    cout<<"\tDisfrute su Viaje. . . "<<endl<<endl;
    cout<<"-------------------------------------"<<endl<<endl;
    system("pause");

    return people.getCont();
}
int main()
{
    int cont, rango;
    Nodo *pila = nullptr;
    Nodo *frente_1 = nullptr, *fin_1 = nullptr;
    Nodo *frente_2 = nullptr, *fin_2 = nullptr;

    Nodo *aux = nullptr;

    cont = BuyTicket(frente_1, fin_1);
    recogerBoleto(frente_1, fin_1, cont, pila);
    revisionMaletas(cont, frente_1, fin_1, pila);
    AbordarAvion(cont, frente_1);
    Vuelo();
    desabordarAvion(cont, pila, frente_2, fin_2);
    pedirUber(frente_2, fin_2, cont);

    system("cls");
    gotoxy(0,10);cout<<"FIN del programa";
    gotoxy(0,20);system("pause");
    return 0;
}
