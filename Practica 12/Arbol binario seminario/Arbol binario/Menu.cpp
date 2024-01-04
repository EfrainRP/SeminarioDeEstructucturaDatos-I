#include "Menu.h"

using namespace std;
//using namespace std::chrono;

///Metodo privado
void Menu::enterMenu() {
    cout<< endl<< "Presiona cualquier tecla para continuar";
    getch();
    }

void Menu::InsertData() {
    int myInt(1);
    string myStr;
    Info dataInfo;
    Nombre newName;

    while(myInt==1) {
        system("cls");
        cout<<"\t\tINGRESE LOS DATOS"<<endl<<endl;
        cout<<"Ingrese la ID: ";
        cin.ignore()>>myInt;
        dataInfo.setID(myInt);

        cout<<"Ingrese el nombre: ";
        getline(cin.ignore(),myStr);
        newName.setFirstName(myStr);

        cout<<"Ingrese el apellido: ";
        getline(cin,myStr);
        newName.setLastName(myStr);

        cout<<"Ingrese la direccion: ";
        getline(cin,myStr);
        dataInfo.setAddress(myStr);

        cout<<"Ingrese el email: ";
        getline(cin,myStr);
        dataInfo.setEmail(myStr);

        myBTree->insertData(dataInfo);

        cout<<"\t\tAgregado exitosamente"<<endl<<endl;
        cout<<"Desea agregar otro: (1)Si    (2)No : ";
        cin>>myInt;

        }

    }

void Menu::findData() {
    int myInt(0);
    string myStr;
    Info dataInfo;
    Nombre myName;

    cout<<"\t\t\tBusqueda"<<endl<<"Buscar por: ID [1]   /  Nombre [2] : ";
    cin>>myInt;

    if(myInt==1){
    cout<<"Ingrese el ID: ";
    cin>>myInt;
    dataInfo.setID(myInt);

    }else{

    cout<<"Ingrese el nombre: ";
    getline(cin.ignore(),myStr);
    myName.setFirstName(myStr);

    cout<<"Ingrese el apellido: ";
    getline(cin,myStr);
    myName.setLastName(myStr);

    dataInfo.setName(myName);
    }

    if(myBTree->findData(dataInfo) != nullptr){
        cout<<"\t\tNODO ENCONTRADO"<<endl<<endl;
    }else{
        cout<<"\t\tNODO NO ENCONTRADO"<<endl<<endl;
    }
    system("pause");
    }

void Menu::editData() {

    }

void Menu::deleteData() {

    }

void Menu::displayMenu() {
    cout<< "\t\t MENU " <<endl;
    cout<< "\t1. Insertar Nodos: " <<endl;
    cout<< "\t2. Buscar Nodo: " <<endl;
    cout<< "\t3. Mostrar Minimo ID" <<endl;
    cout<< "\t4. Mostrar Maxima ID" <<endl;
    cout<< "\t5. Mostrar Nodo Antecesor"<<endl;
    cout<< "\t6. Mostrar Nodo Sucesor"<<endl;
    cout<< "\t7. Editar Nodo " <<endl;
    cout<< "\t8. Eliminar Nodo " <<endl;
    cout<< "\t9. Mostrar datos en Orden " <<endl;
    cout<< "\t10. Mostrar datos en PreOrden " <<endl;
    cout<< "\t11. Mostrar datos en PostOrden " <<endl;
    cout<< "\t12. Salir " <<endl;
    cout<< "\tSelecciona una opcion: ";
    }


///Constructor
Menu::Menu(BTree<Info>& _BTree): myBTree(&_BTree) {}

///Metodo publico
void Menu::mainMenu() {
    int opc=0;


    while(opc<12){

    system("cls");
    displayMenu();
    cin>>opc;

    switch(opc) {
        case 1://inserta
            InsertData();
            system("cls");
            break;

        case 2://busca
            findData();
            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

            break;

        case 11:

            break;

        case 12:

            break;
        }

    }

    }
