#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

template<typename T>
class Nodo {
    public:
        Nodo();
        Nodo(T,T);
        ~Nodo();
        Nodo *next;
        T id;
        T nombre;
        void print();
    };
template<typename T>
Nodo<T>::Nodo() {
    id= NULL;
    nombre= NULL;
    next= NULL;
    }

template<typename T>
Nodo<T>::Nodo(T id_,T nombre_ ) {
    id=id_;
    nombre=nombre_;
    next=NULL;
    }
template<typename T>
void Nodo<T>::print() {
    cout<<"Id:"<<id<<endl;
    cout<<"Nombre:"<<nombre<<endl;

    }
template<typename T>
Nodo<T>::~Nodo() {}

template<class T>

class List {/////////////////////////////////////////////
    private:
        Nodo<T> *ptrHead;
        int number_nodo;
    public:
        List();
        ~List();

        void add_head(T,T);
        void add_end(T,T);
        void add_sort(T,T);
        void delete_position(int);
        void print();
        void Search(T);
        void Search_name(T);

        //void SearchName(T);
        void DeleteAll();
        void Order();
        void Edit(int);

        void Invert();
        void Search_Pos(int);
        void Modify(int);

    };
template<typename T>
List<T>::List() {
    number_nodo=0;
    ptrHead=NULL;
    }
template<typename T>
List<T>::~List() {
    DeleteAll();
}

//Insertar al inicio
template<typename T>
void List<T>::add_head(T id_,T nombre_) {
    Nodo<T> *new_nodo=new Nodo<T>(id_,nombre_);
    Nodo<T> *temp = ptrHead;

    if(!ptrHead) {
        ptrHead=new_nodo;
        }
    else {
        new_nodo->next=ptrHead;
        ptrHead= new_nodo;
        while(temp) {
            temp=temp->next;
            }
        }
    number_nodo++;
    }

template <typename T>
void List<T>::add_sort(T id_,T nombre_) {
    Nodo<T> *new_nodo= new Nodo<T> (id_,nombre_);
    Nodo<T> *temp=ptrHead;
    if (!ptrHead) {
        ptrHead=new_nodo;
        }
    else {
        if(ptrHead->id==id_) {
            new_nodo->next=ptrHead;
            ptrHead=new_nodo;
            }
        else {
            while(temp->next!=NULL) {
                temp= temp->next;
                }
            new_nodo->next=temp->next;
            temp->next=new_nodo;
            }
        }
    number_nodo++;
    }
template<typename T>
void List<T>::delete_position(int pos) {
    Nodo<T>*temp=ptrHead;
    Nodo<T>*temp1=temp->next;
    if(pos<1||pos>number_nodo) {
        cout<<"Fuera de rango\n";
        }
    else if(pos==1) {
        ptrHead=temp->next;
        delete temp;
        number_nodo--;
        }
    else {
        for(int i=2; i<=pos; i++) {
            if(i==pos) {
                Nodo<T>*aux_nodo=temp1;
                temp->next=temp1->next;
                delete aux_nodo;
                number_nodo--;
                }
            temp=temp->next;
            temp1=temp1->next;
            }
        }
    }

template<typename T>
void List<T>::print() {
    Nodo<T> *temp=ptrHead;
    if(!ptrHead) {
        cout<<"La Agenda esta vacia\n";
        }
    else {
        while(temp) {
            temp->print();
            cout<<"\n\n";
            temp=temp->next;
            }
        }

    }

template<typename T>
void List<T>::Search(T id_) {
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
    while(temp) {
        if(temp->id==id_) {
            cout<<"Encontrado en la posicion:"<<count1<<endl;
            count2++;
            }
        temp=temp->next;
        count1++;
        }
    if(count2==0) {
        cout<<"No existe el dato\n";
        }
    cout<<"\n\n";
    }

template<typename T>
void List<T>::Search_name(T nombre_) {
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
    while(temp) {
        if(temp->nombre==nombre_) {
            cout<<"Encontrado en la posicion:"<<count1<<endl;
            count2++;
            }
        temp=temp->next;
        count1++;
        }
    if(count2==0) {
        cout<<"No existe el dato\n";
        }
    cout<<"\n\n";
    }

template<typename T>
void List<T>::DeleteAll() {
    if(ptrHead==NULL){
        cout<<"La agenda esta vacia\n";
    }else {
        Nodo<T>* aux1=ptrHead;
        Nodo<T>* aux2=aux1;
        while(ptrHead!=NULL) {
            delete aux1;
            ptrHead=ptrHead->next;
            }
        ptrHead=NULL;
        number_nodo=0;
        cout<<"Se eliminaron los datos\n";
        }

    }

template<typename T>
void List<T>::Invert() {
    if(ptrHead==NULL)
        cout<<"La agenda esta vacia\n";
    else {
        Nodo<T>* aux1=NULL;
        Nodo<T>* aux2=ptrHead;
        Nodo<T>* aux3=ptrHead->next;
        while(aux3!=NULL) {
            aux2->next = aux1;
            aux1 = aux2;
            aux2 = aux3;
            aux3 = aux2->next;
            }
        aux2->next = aux1;
        ptrHead=aux2;
        number_nodo=1;
        cout<<"Se invirtieron los datos\n";
        }
    }

template<typename T>
void List<T>::Search_Pos(int pos){
	int band=0;
	Nodo<T> *aux=ptrHead;
	if(number_nodo==0)
		cout<<"Agenda esta vacia\n";
	else{
		if(pos<number_nodo+1&&pos>0){
			for(int i=1;i<pos;i++)
			{
				aux=aux->next;
				}
			cout<<"Id: "<<aux->id<<endl;
			cout<<"Nombre: "<<aux->nombre<<endl;
			}
			else{
				cout<<"Posicion invalida\n";
			}
	}
}

template<typename T>
void List<T>::Modify(int pos){
    int band=0;
	Nodo<T> *aux=ptrHead;
	T myStr;
	if(number_nodo==0)
		cout<<"Agenda esta vacia\n";
	else{
		if(pos<number_nodo+1&&pos>0){
			for(int i=1;i<pos;i++)
			{
				aux=aux->next;
				}
            cin.ignore();
			cout<<"Id: ";
			getline(cin,aux->id);

            //cin.ignore();
			cout<<"Nombre: ";
			getline(cin,aux->nombre);
			}
			else{
				cout<<"Posicion invalida\n";
			}
	}
}

template<typename T>
void List<T>::Order(){
    T aux;
    Nodo<T> *aux_node = ptrHead;
    Nodo<T> *temp = aux_node;

    while (aux_node) {
        temp = aux_node;

        while (temp->next) {
            temp = temp->next;

            if (aux_node->nombre > temp->nombre) {
                aux = aux_node->nombre;
                aux_node->nombre = temp->nombre;
                temp->nombre = aux;
            }
        }

        aux_node = aux_node->next;
    }
    cout<<"Se ordenaron\n";
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


int main (int argc,char *argv[]) {
    List<string> list1;

    int element,dimention,pos,dat, opc;
    string id_,nombre_,correo_,numero_,direccion_;
    do {

        cout<<"1-.Agregar contacto \n";
        cout<<"2-.Buscar contacto.\n";
        cout<<"3-.Eliminar contacto.\n";
        cout<<"4-.Buscar por posicion\n";
        cout<<"5-.Invertir\n";
        cout<<"6-.Buscar por nombre\n";
        cout<<"7-.Ordenar alfabeticamente\n";
        cout<<"8-.Imprimir datos\n";
        cout<<"9-.Modificar\n";
        cout<<"10-.Eliminar Todo\n";
        cout<<"0-.Salir..\n";
        cout<<"Seleccione un opcion\n";

        switch (opc=enterValue()) {
            case 1: {
                system ("CLS");
                cin.sync();
                cout<<"ID \n";
                do {

                    getline(cin,id_);

                    if(id_<="0" || id_>="9") {
                        cout<<"Ingresa puros numeros"<<endl;
                        }
                    }
                while(id_<="0"|| id_>="9");


                cout<<"Nombre \n";
                getline(cin,nombre_);


                list1.add_head(id_,nombre_);
                list1.print();
                break;
                }

            case 2: {
                getline(cin,id_);
                cout<<"Busca un elemento\n";
                do {

                    getline(cin,id_);
                    if(id_<="0" || id_>="9") {
                        cout<<"Ingresa puros numeros"<<endl;
                        }
                    }
                while(id_<="0"|| id_>="9");
                list1.Search(id_);
                break;
                }
            case 3: {
                cout<<"Elimina posicion\n";
                pos=enterValue();
                list1.delete_position(pos);
                list1.print();
                break;
                }
            case 4: {
                cout<<"Ingrese la posicion\n";
                pos=enterValue();
                list1.Search_Pos(pos);

                break;
                }
            case 5: {
                list1.Invert();
                break;
                }
            case 6: {
                cin.ignore();
                cout<<"Ingresa el nombre a buscar\n";
                getline(cin,nombre_);
                list1.Search_name(nombre_);
                break;
                }
            case 7: {
                list1.Order();
                break;
                }
            case 8: {
                list1.print();
                break;
                }
            case 9: {
                cout<<"Ingresa la posicion del dato a modificar\n";
                pos=enterValue();
                list1.Modify(pos);
                break;
                }
            case 10: {
                list1.DeleteAll();
                break;
                }

            }
        cout<<endl;
        system("pause");
        system("cls");
        }
    while(opc!=0);
    return 0;
    }
