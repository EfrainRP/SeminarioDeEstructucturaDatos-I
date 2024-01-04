#include "Menu.h"

using namespace std;
//using namespace std::chrono;

///Metodo privado
void Menu::gotoxy(int x,int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
    }

bool Menu::Validation(char*& num) {
    if((char)*num>=48 && (char)*num<=57) {
        //cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
        }
    else {
        //cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
        }
    }

bool Menu::ValidationNum(const string& str){
    int i(0);
    while (i<str.size()) {
        if ((isalpha(str[i]) || isalpha(str[i+1])) && str[i] != ' '){
            return true;
        }
        i++;
    }
    return false;
}

bool Menu::ValidationLetter(const string& str){
    int i(0);
    while (i<str.size()) {
        // Si no es del alfabeto y no es un espacio regresamos false o 0
        if (!isalpha(str[i]) && str[i] != ' '){// El espacio cuenta como válido, si no, simplemente quita la condición
            return true;
        }
        i++;
    }
    return false;
}

bool Menu::ValidationAlphaNum(const string& str){
    int i(0);
    while (i<str.size()) {
        if ((!isalpha(str[i]) && !isdigit(str[i])) && str[i] == ' ' && str[i] != '.'){
            return true;
        }
        i++;
    }
    return false;
}

bool Menu::ValidationEmail(const string& str){
    int i(0);

    while (i<str.size()) {
        if (!isalpha(str[i]) && str[i] != '.'){
            return true;
        }
        i++;
    }
    return false;
}


void Menu::InsertData() {
    int myInt(1);
    string myStr, myStr2;
    Info dataInfo;
    Nombre newName;
    char myChar[15], *ptrChar;

    while(myInt==1) {
        system("cls");
        cout<<"\t\tINGRESE LOS DATOS"<<endl<<endl;
        cout<<"Ingrese la ID:   ";
        cin.ignore();
        do {
        gotoxy(15,2);cout<<"                                      ";
        gotoxy(15,2); getline(cin,myStr);
        //ptrChar = &myChar[0];

        } while(ValidationNum(myStr));

        //myInt = atoi(ptrChar);
        myInt = stoi(myStr);
        dataInfo.setID(myInt);

        cout<<"Ingrese el nombre: ";

        do{
            gotoxy(19,3);cout<<"                                      ";
            gotoxy(19,3); getline(cin,myStr);

        }while(ValidationLetter(myStr));
        newName.setFirstName(myStr);

        cout<<"Ingrese el apellido: ";
        do{
            gotoxy(21,4);cout<<"                                      ";
            gotoxy(21,4); getline(cin,myStr);

        }while(ValidationLetter(myStr));
        newName.setLastName(myStr);

        dataInfo.setName(newName);

        cout<<"Ingrese la direccion: ";
        do{
            gotoxy(22,5);cout<<"                                      ";
            gotoxy(22,5); getline(cin,myStr);

        }while(ValidationAlphaNum(myStr));
        int x=myStr.size()+1;

        do{
            gotoxy(22+x,5);cout<<"#                                      ";
            gotoxy(23+x,5); getline(cin,myStr2);

        }while(ValidationNum(myStr2));

        myStr+= " #" + myStr2;
        dataInfo.setAddress(myStr);

        cout<<"Ingrese el email: ";
        do{
            gotoxy(18,6);cout<<"                                      ";
            gotoxy(18,6); getline(cin,myStr);

        }while(ValidationAlphaNum(myStr));

        x=myStr.size()+1;
        do{
            gotoxy(18+x,6);cout<<"@                                      ";
            gotoxy(19+x,6); getline(cin,myStr2);

        }while(ValidationEmail(myStr2));
        myStr+= "@" + myStr2;
        dataInfo.setEmail(myStr);

        myBTree->insertData(dataInfo);

        cout<<"\t\tAgregado exitosamente"<<endl<<endl;
        cout<<"Desea agregar otro: (1)Si    (2)No : ";
        cin>>myInt;

        }

    }

void Menu::findData() {
    if(!myBTree->isEmpty()){
    int myInt(0);
    string myStr;
    Info newData;
    Nombre newName;
    BTree<Info>::Position point;

    cin.ignore();
    cout<<"\t\t\tBusqueda"<<endl<<"Buscar por: ID [1]   /  Nombre [2] : ";
    do {
            getline(cin,myStr);

        } while(ValidationNum(myStr));

        myInt = stoi(myStr);

    if(myInt==1) {
        do {
            cout<<"Ingrese el ID: ";
            getline(cin,myStr);

        } while(ValidationNum(myStr));

        myInt = stoi(myStr);
        newData.setID(myInt);

        if((point = myBTree->findData(newData)) != nullptr) {
        cout<<endl<<"\tNODO ENCONTRADO:  "<<myBTree->retrieve(point).toString()<<endl;
        getPrevius(point);
        getNextPos(point);
        }
    else {
        cout<<endl<<"\t\tNODO NO ENCONTRADO"<<endl<<endl;
        }

        }
    else if(myInt == 2){

        cout<<"Ingrese el nombre: ";
        do{
            getline(cin.ignore(),myStr);

        }while(ValidationLetter(myStr));
        newName.setFirstName(myStr);

        cout<<"Ingrese el apellido: ";
        do{
            getline(cin,myStr);

        }while(ValidationLetter(myStr));
        newName.setLastName(myStr);

        newData.setName(newName);
        if((point = myBTree->findData(newData)) != nullptr) {
        cout<<endl<<"\tNODO ENCONTRADO:  "<<myBTree->retrieve(point).toString()<<endl;
        getPrevius(point);
        getNextPos(point);
        }
    else {
        cout<<endl<<"\t\tNODO NO ENCONTRADO"<<endl<<endl;
        }
        }

    }else{
        cout<<endl<<"\t\tARBOL VACIO"<<endl<<endl;
    }
}

void Menu::editData() {
    int myInt(0);
    string myStr;
    Info dataInfo;
    Nombre newName;
    BTree<Info>::Position editPoint(nullptr);

    if(!myBTree->isEmpty()){
        cout<<endl<<"ID a modificar: ";
        do {
            getline(cin,myStr);

        } while(ValidationNum(myStr));

        myInt = stoi(myStr);
        dataInfo.setID(myInt);

        editPoint = myBTree->findData(dataInfo);

        if(editPoint != nullptr){
        cout<<"\t\tINGRESE LOS DATOS A MODIFICAR"<<endl<<endl;

            cout<<"Ingrese el nombre: ";
            getline(cin.ignore(),myStr);
            newName.setFirstName(myStr);

            cout<<"Ingrese el apellido: ";
            getline(cin,myStr);
            newName.setLastName(myStr);

            dataInfo.setName(newName);

            cout<<"Ingrese la direccion: ";
            getline(cin,myStr);
            dataInfo.setAddress(myStr);

            cout<<"Ingrese el email: ";
            getline(cin,myStr);
            dataInfo.setEmail(myStr);

            editPoint->setData(dataInfo);

            cout<<myBTree->retrieve(editPoint).toString()<<endl;
        }else{
            cout<<endl<<"\t\tID NO ENCONTRADO"<<endl<<endl;
        }
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

void Menu::deleteData() {
    int myInt(0);
    string myStr;
    Info dataInfo;
    Nombre newName;
    BTree<Info>::Position editPoint(nullptr);

    if(!myBTree->isEmpty()){
        cout<<endl<<"ID a elminar: ";
        do {
            getline(cin,myStr);

        } while(ValidationNum(myStr));

        myInt = stoi(myStr);
        dataInfo.setID(myInt);

        if((editPoint = myBTree->findData(dataInfo)) != nullptr){
            myBTree->deleteData(dataInfo);
            cout<<"\t\tNODO ELIMINADO"<<endl<<endl;

        }else{
            cout<<"\t\tID NO ENCONTRADO"<<endl<<endl;
        }
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

void Menu::getPrevius(BTree<Info>::Position p){
    BTree<Info>::Position point2;
    if(p != nullptr) {
            if((point2 = myBTree->getPreviusPos(p))!= p){
                cout<<"\tNODO ANTECESOR:    "<<myBTree->retrieve(point2).toString()<<endl;
            }else{
                cout<<"\tNO HAY NODO ANTECESOR"<<endl<<endl;
            }
        }
    else {
        cout<<"\tNODO NO ENCONTRADO"<<endl<<endl;
        }
}

void Menu::getNextPos(BTree<Info>::Position p){

    if(p != nullptr) {
            if(!myBTree->isLeaf(p)){
            p = p->getLeft() ==nullptr? p->getRight(): p->getLeft();
            cout<<"\tNODO SUCESOR:  "<<myBTree->retrieve(p).toString()<<endl;
            }else{
                cout<<"\tNO HAY NODO SUCESOR"<<endl<<endl;
            }
        }
    else {
        cout<<"\tNODO NO ENCONTRADO"<<endl<<endl;
        }
}

void Menu::displayMenu() {
    cout<< "\t\t MENU " <<endl;
    cout<< "\t1. Insertar Nodos: " <<endl;
    cout<< "\t2. Buscar Nodo: " <<endl;
    cout<< "\t3. Mostrar Minimo ID" <<endl;
    cout<< "\t4. Mostrar Maximo ID" <<endl;
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
    int opc=0, myInt;
    Info i;
    char myChar[20], *ptrChar;
    string myStr;
    BTree<Info>::Position p(nullptr);


    while(opc<12) {
    do {
        system("cls");
        myBTree->parseInOrder(0);
        displayMenu();
        cin>>myChar;
        ptrChar = &myChar[0];
        } while(!Validation(ptrChar));

        opc = atoi(ptrChar);
        cout<<endl;

        switch(opc) {
            case 1://inserta
                InsertData();
                system("cls");
                break;

            case 2://busca
                findData();
                break;

            case 3://minimo
                p = myBTree->getHighest();
                i = myBTree->retrieve(p);
                cout<<endl<<"ID Minimo: "<<endl<<i.toString();
                getPrevius(p);
                getNextPos(p);
                break;

            case 4://maximo
                p = myBTree->getHighest();
                i = myBTree->retrieve(p);
                cout<<endl<<"ID Maximo: "<<endl<<i.toString();
                getPrevius(p);
                getNextPos(p);
                break;

            case 5://antecesor
                cout<<"Ingrese el ID: ";
                cin.ignore();
                do {
                    getline(cin,myStr);

                } while(ValidationNum(myStr));
                myInt = stoi(myStr);
                i.setID(myInt);
                p=myBTree->findData(i);
                getPrevius(p);
                break;

            case 6://sucesor
                cout<<"Ingrese el ID: ";
                cin.ignore();
                do {
                    cout<<"Ingrese el ID: ";
                    getline(cin,myStr);

                } while(ValidationNum(myStr));

                myInt = stoi(myStr);
                i.setID(myInt);
                p=myBTree->findData(i);
                getNextPos(p);
                break;

            case 7://editar
                editData();
                break;

            case 8://elimina
                deleteData();
                break;

            case 9://inorder
                myBTree->parseInOrder(0);
                break;

            case 10://preorder
                myBTree->parsePreOrder(0);
                break;

            case 11://postorder
                myBTree->parsePostOrder(0);
                break;

            case 12://salir
                cout<<"\t\tFIN DEL PROGRAMA"<<endl<<endl;
                break;
            }
            if(opc!=12 && opc!=1){
                system("pause");
            }

        }

    }
