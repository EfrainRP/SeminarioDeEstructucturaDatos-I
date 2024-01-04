#include <iostream>
#include <string.h>
using namespace std;

int opc=0;
int index=0;
int i;

struct agenda{
	int id;
	char nombre[30];
	char direccion[30];
	char email[30];
	char telefono[10];
}a[5];

void RegistrarContacto(){
	    a[index].id=index+1;
		cout<<"\nIngrese Nombre: "<<endl;
		cin>>a[index].nombre;
		cout<<"Ingrese Direccion: "<<endl;
		cin>>a[index].direccion;
		cout<<"Ingrese Email: "<<endl;
		cin>>a[index].email;
		cout<<"Ingrese Telefono: "<<endl;
		cin>>a[index].telefono;
		index++;
}
int BuscarContacto(int id){
	int posicion=-1,x=0;
	bool ban=false;
	while(x<5 && ban==false){
		if(id==a[x].id){
			ban=true;
			posicion=x;
		}
		x++;
	}
	return posicion;
}
void EditarContacto(int pos_ed){
    cout<<"\nCampo a editar:"<<endl;
    cout<<"1) Nombre"<<endl;
	cout<<"2) Direccion"<<endl;
    cout<<"3) Email"<<endl;
	cout<<"4) Telefono"<<endl;
	cout<<"5) Todos los campos"<<endl;
	cin>>opc;
    switch (opc){
        case 1: cout<<"\nIngrese Nombre: "<<endl;
                cin>>a[pos_ed].nombre; break;
        case 2: cout<<"\nIngrese Direccion: "<<endl;
                cin>>a[pos_ed].direccion; break;
        case 3: cout<<"\nIngrese Email: "<<endl;
                cin>>a[pos_ed].email; break;
        case 4: cout<<"\nIngrese Telefono: "<<endl;
                cin>>a[pos_ed].telefono; break;
        case 5: cout<<"\nIngrese Nombre: "<<endl; cin>>a[pos_ed].nombre;
                cout<<"Ingrese Direccion: "<<endl; cin>>a[pos_ed].direccion;
                cout<<"Ingrese Email: "<<endl; cin>>a[pos_ed].email;
                cout<<"Ingrese Telefono: "<<endl; cin>>a[pos_ed].telefono; break;

    }
}
int RemoverContacto(int pos_re){
    for(i=pos_re;i<5+1;i++){
        strcpy(a[i].nombre,a[i+1].nombre);
        strcpy(a[i].direccion,a[i+1].direccion);
        strcpy(a[i].email,a[i+1].email);
        strcpy(a[i].telefono,a[i+1].telefono);
    }
}

void MostrarContacto(int pos){
    cout<<"\nID: "<<a[pos].id<<endl;
    cout<<"Nombre: "<<a[pos].nombre<<endl;
    cout<<"Direccion: "<<a[pos].direccion<<endl;
    cout<<"Email: "<<a[pos].email<<endl;
    cout<<"Telefono: "<<a[pos].telefono<<endl;
}

void ListarContactos(){
    for(i=0;i<5;i++){
        MostrarContacto(i);
    }
}

int menu(){
	int opcMenu=0,id=0;
	cout<<"\t1) Registro Contacto"<<endl;
	cout<<"\t2) Buscar Contacto"<<endl;
    cout<<"\t3) Editar Contacto"<<endl;
	cout<<"\t4) Remover Contacto"<<endl;
	cout<<"\t5) Listar Contactos"<<endl;
	cout<<"\t6) Salir\n"<<endl;
	cout<<"\tSeleccione una opcion\n"<<endl;
	cin>>opcMenu;
	switch(opcMenu){
		case 1: RegistrarContacto();break;
		case 2: cout<<"\nIngrese Id a Buscar"<<endl;
	            cin>>id;
			    MostrarContacto(BuscarContacto(id)); break;
		case 3: cout<<"\nIngrese Id a Editar"<<endl;
	            cin>>id;
			    EditarContacto(BuscarContacto(id)); break;
        case 4: cout<<"\nIngrese Id a Remover"<<endl;
	            cin>>id;
			    RemoverContacto(BuscarContacto(id)); break;
        case 5: ListarContactos(); break;
        case 6: cout<<"\nFin del programa"<<endl; break;

	}
}

int main(int argc, char** argv) {
	do{
		system("cls");
		menu();
        cout<<"\nContinuar si[1]  no[2]"<<endl;
        cin>>opc;
	}while(opc!=2);
	return 0;
}
