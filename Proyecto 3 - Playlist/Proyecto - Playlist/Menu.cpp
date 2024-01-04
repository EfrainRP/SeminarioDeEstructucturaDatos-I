#include "Menu.h"
string archiveMusic = "E:\\Documentos PC\\UDG Materias\\SEMINARIO DE ESTRUCTURA\\Proyecto 3 - Playlist\\Music\\";

using namespace std;

///Metodos privados
bool Menu::Validation(char* num) {
    if((char)*num>=48 && (char)*num<=57) {
        //cout<< "El dato ingresado ("<<num<<") ES un numero"<<endl;
        return true;
        }
    else {
        //cout<<"El dato ingresado ("<<num<<") NO es un numero.   Ingrese numero valido: ";
        return false;
        }
    }

int Menu::enterValue() {
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

void Menu::hideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
    }

void Menu::gotoxy(int x,int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
    hideCursor();
    }

void Menu::newElement(List<Cancion>::Position& selectPos, int& POS) {
    clearScreen();
    string myStr;
    int myInt;
    char myChar, rankCancion[30], *ptrChar;
    Nombre newNombre;
    Cancion newCancion;
    List<Cancion>::Position insertPoint;//Direccion de memoria

    if(myList->isEmpty()){
        myList->readFromDisk(archiveMusic + "Canciones-sem.txt" );
    }else{
        cout << "\n\t Agregue Cancion" << endl;
        //Datos de la cancion
        cout << "Ingrese nombre de la cancion: ";
        cin.sync();
        getline(cin, myStr);
        newCancion.setCancion(myStr);

        //Datos del nombre del autor
        cout << "Ingrese primer nombre del autor: ";
        getline(cin, myStr);
        newNombre.setFirstName(myStr);
        cout << "Ingrese segundo nombre del autor: ";
        getline(cin, myStr);
        newNombre.setLastName(myStr);
        newCancion.setAutor(newNombre);

        //Datos del nombre del interprete
        cout << "Ingrese primer nombre del interprete: ";
        getline(cin, myStr);
        newNombre.setFirstName(myStr);
        cout << "Ingrese segundo nombre del interprete: ";
        getline(cin, myStr);
        newNombre.setLastName(myStr);
        newCancion.setInterprete(newNombre);

        //Posicion del ranking
        cout << "Ingrese posicion en el ranking: ";
        do {
            gotoxy(33,7); cout<<"                   ";
            gotoxy(33,7); cin>>rankCancion;
            ptrChar = &rankCancion[0];
        }
        while(!Validation(ptrChar));

        myInt = atoi(ptrChar);
        newCancion.setRanking(myInt);

        //Archivo .MP3
        cout << "Ingrese el nombre del archivo MP3: ";
        getline(cin.ignore(), myStr);
        myStr = archiveMusic + myStr;
        newCancion.setArchivo(myStr);

        do{
        cout<<"\nInsertar en [P]rincipio / [E]legir posicion / [F]inal : ";
        cin>>myChar;
        cin.ignore();
        myChar = toupper(myChar);
        }while(myChar != 'P' && myChar != 'E' && myChar != 'F');

        try {
                switch(myChar) {
                    case 'P':
                        myList->insertData(nullptr,newCancion);//Inserta despues del punto de referencia

                        if(POS==0){
                            selectPos = myList->getFirstPos();
                        }else{
                            selectPos = myList->getPrevPos(selectPos);
                        }
                        cout << "\n\t\t\tCancion Agregada..." << endl<< endl;
                        break;
                    case 'E':
                        cout<< "\nIngrese la posicion a insertar: ";
                        myInt = enterValue() - 1;
                        if((insertPoint = myList->getPos(myInt)) != nullptr) {
                            myList->insertData(myList->getPrevPos(insertPoint),newCancion);//Inserta en el punto de referencia

                            if(myInt <= POS){
                                selectPos = myList->getPrevPos(selectPos);
                            }
                            cout << "\n\t\t\tCancion Agregada..." << endl<< endl;
                            }
                        else {
                            cout << "\n\t\tCancion No Agregada..."<<endl<< "\t\tPosicion Invalida..." << endl;
                            }
                        break;
                    case 'F':
                        myList->insertData((insertPoint = myList->getLastPos()),newCancion);//Inserta despues del punto de referencia
                        cout << "\n\t\t\tCancion Agregada..." << endl<< endl;
                        break;
                    default:
                        cout << "\n\t\t\tOpcion Invalida..." << endl<< endl;
                        break;
                }
            }
        catch(List<Cancion>::ListException ex) {
            cout << "Ocurrio un error" << endl;
            cout << "Error de sistema:" << ex.what() << endl;
            enterMenu();
            }
    }
    //return myList->getNextPos(selectPos);
    }

void Menu::deleteElement(const List<Cancion>::Position& selectPos) {
    Cancion newCancion;
    string myStr;
    int myInt;
    //clearScreen();
    gotoxy(0,15);
    showList();
    try {
        if(selectPos != nullptr) {
            myList->deleteData(selectPos);
            gotoxy(31,11); cout<<"Cancion eliminado... "<<endl;
            }
        else {
            gotoxy(31,11); cout << "No existe la cancion..." << endl;
            }
        }
    catch(List<Cancion>::ListException ex) {
        cout << "Ocurrio un error" << endl;
        cout << "Error de sistema:" << ex.what() << endl;
        return;
        }
    gotoxy(0,15);
    showList();
    myStr= " "; myStr.resize(125,' '); cout<<myStr;
    enterMenu();
    }

void Menu::EditElement(const List<Cancion>::Position& selectPos) {
    string myStr;
    int myInt;
    char rankCancion[30], *ptrChar;
    Nombre newNombre;
    Cancion newCancion;

    clearScreen();
    gotoxy(0,12);
    showList();

    if(selectPos != nullptr){
        gotoxy(0,0);
        cout << "\n\t Ingrese Cancion a modificar" << endl;

        //Datos de la cancion
        cout << "Ingrese nombre de la cancion: ";
        cin.sync();
        getline(cin, myStr);
        newCancion.setCancion(myStr);

        //Datos del nombre del autor
        cout << "Ingrese primer nombre del autor: ";
        getline(cin, myStr);
        newNombre.setFirstName(myStr);
        cout << "Ingrese segundo nombre del autor: ";
        getline(cin, myStr);
        newNombre.setLastName(myStr);
        newCancion.setAutor(newNombre);

        //Datos del nombre del interprete
        cout << "Ingrese primer nombre del interprete: ";
        getline(cin, myStr);
        newNombre.setFirstName(myStr);
        cout << "Ingrese segundo nombre del interprete: ";
        getline(cin, myStr);
        newNombre.setLastName(myStr);
        newCancion.setInterprete(newNombre);

        //Posicion del ranking
            cout << "Ingrese posicion en el ranking: ";
            do {
                gotoxy(33,7); cout<<"                                              ";
                gotoxy(33,7); cin>>rankCancion;
                ptrChar = &rankCancion[0];
            }
            while(!Validation(ptrChar));

            myInt = atoi(ptrChar);
            newCancion.setRanking(myInt);

            //Archivo .MP3
            cout << "Ingrese el nombre del archivo MP3: ";
            getline(cin.ignore(), myStr);
            myStr = archiveMusic + myStr;
            newCancion.setArchivo(myStr);

        selectPos->setData(newCancion);
        cout<<"\n\t\t\tCancion modificada... "<<endl;

    }else{
        clearScreen();
        gotoxy(0,12);
        showList();
        cout<<"\n\t\t\tPosicion Invalida... "<<endl;
    }
    gotoxy(0,12);
    showList();
    enterMenu();
    }

void Menu::playMusic(const Cancion& c) {
    ifstream file;

    file.open(c.getArchivo());

    if (file){
      cout<< "  REPRODUCIENDO....";
      PlaySound((LPCSTR)c.getArchivo().c_str(),NULL,SND_FILENAME | SND_ASYNC);
      file.close();
    }
    else
    {
      cout<< "Arvhivo NO encontrado\n";
    }

}

void Menu::displayMenu() {
    clearScreen();
    cout<< "\t\t MENU " <<endl;
    cout<< "\t1. Añadir nuevos canciones: " <<endl;
    cout<< "\t2. Eliminar cancion: " <<endl;
    cout<< "\t3. Editar cancion" <<endl;
    cout<< "\t4. Busqueda" <<endl;
    cout<< "\t5. Siguiente"<<endl;
    cout<< "\t6. Anterior"<<endl;
    cout<< "\t7. Play " <<endl;
    cout<< "\t8. Stop " <<endl;
    cout<< "\t9. Invertir " <<endl;
    cout<< "\t10. Salir " <<endl;
    cout<< "\tSelecciona una opcion: ";

    }

double Menu::showListMenu(int pos, const List<Cancion>::Position selectPos) {
    string myStr(" ");
    char myChar[30], buffer[10], *ptrChar;
    double mydouble;
    Cancion miCancion;
    clearScreen();

    displayMenu();
    gotoxy(0,15);
    showList();
    if(!myList->isEmpty() && selectPos != nullptr) {
            myStr.resize(22, ' ');
            gotoxy(123,20+pos);cout<<char(174)<<char(174)<<char(205)<<myStr<<endl;//flecha

            miCancion = myList->retrieve(selectPos);

            myStr  = char(201); myStr.resize(122, char(205));//Parte arriba
            myStr.resize(122,char(205)); myStr.replace(9, 1, 1, char(203)); myStr.replace(37, 1, 1, char(203));
            myStr.replace(58, 1, 1, char(203)); myStr.replace(81, 1, 1, char(203)); myStr.replace(92, 1, 1, char(203));

            sprintf(buffer, "%c%4i    %c ", char(186), pos+1, char(186));

            gotoxy(0,13); cout<<myStr<<char(187)<<endl<<buffer<<miCancion.toString()<<endl<<char(200);//tabla selector

            for(int i(0); i < 121; i++) {
        switch (i) {
            case 8: cout<<char(202); break;
            case 36: cout<<char(202); break;
            case 57: cout<<char(202); break;
            case 80: cout<<char(202); break;
            case 91: cout<<char(202); break;
            default: cout<<char(205);
            }
        }
        cout<<char(188);
    }
    gotoxy(31,11);
    do {
        gotoxy(31,11);
        myStr = " ";
        myStr.resize(75, ' '); cout<<myStr<<endl;
        myStr.resize(150, ' '); cout<<myStr;
        gotoxy(31,11);
        cin>>myChar;
        ptrChar = &myChar[0];

        }
    while(!Validation(ptrChar));

    mydouble = atoi(ptrChar);

    gotoxy(31,11);

    return mydouble;
    }

void Menu::showList() {
    string myStr, tableUp, tableDown;

    tableUp += char(201);
    tableUp.resize(122,char(205));
    tableUp.replace(9, 1, 1, char(203));
    tableUp.replace(37, 1, 1, char(203));
    tableUp.replace(58, 1, 1, char(203));
    tableUp.replace(81, 1, 1, char(203));
    tableUp.replace(92, 1, 1, char(203));
    tableUp += char(187);

    tableDown += char(200);
    tableDown.resize(122,char(205));
    tableDown += char(188);

    //gotoxy(0,10);
    myStr += " POSICION";
    myStr.replace(0, 1, 1, char(186));
    myStr.replace(9, 1, 1, char(186));
    myStr += "   NOMBRE DE LA CANCION";
    myStr.resize (37,' ');
    myStr.replace(37, 1, 1, char(186));
    //myStr += "   | ";
    myStr += "     AUTOR";
    myStr.resize (58,' ');
    myStr.replace(58, 1, 1, char(186));
    //myStr += "   | ";
    myStr += "     INTERPRETE";
    myStr.resize (81,' ');
    myStr.replace(81, 1, 1, char(186));
    //myStr += "   | ";
    myStr += "  RANKING";
    myStr.resize (92,' ');
    myStr.replace(92, 1, 1, char(186));
    //myStr += "   | ";
    myStr += "      NOMBRE DE ARCHIVO";
    myStr.resize (122,' ');
    myStr.replace(122, 1, 1, char(186));
    //myStr += "   | ";

    cout<<endl<<endl;
    cout<<tableUp<<endl<<myStr<<endl;

    if(myList->isEmpty()){
    cout<<char(204);
    for(int i(0); i < 121; i++) {
        switch (i) {
            case 8: cout<<char(202); break;
            case 36: cout<<char(202); break;
            case 57: cout<<char(202); break;
            case 80: cout<<char(202); break;
            case 91: cout<<char(202); break;
            default: cout<<char(205);
            }
        }
    cout<<char(185)<<endl;
    }else{
        cout<<char(204);
    for(int i(0); i < 121; i++) {
        switch (i) {
            case 8:
                cout<<char(206);
                break;
            case 36:
                cout<<char(206);
                break;
            case 57:
                cout<<char(206);
                break;
            case 80:
                cout<<char(206);
                break;
            case 91:
                cout<<char(206);
                break;
            default:
                cout<<char(205);
            }
        }
    cout<<char(185)<<endl;
    }
    cout<< myList->toString();
    if(!myList->isEmpty()) {
        tableDown.replace(9, 1, 1, char(202)); tableDown.replace(37, 1, 1, char(202)); tableDown.replace(58, 1, 1, char(202));
        tableDown.replace(81, 1, 1, char(202)); tableDown.replace(92, 1, 1, char(202));
        cout<<tableDown<<endl;
        }
    else {
        cout<<tableDown<<endl;
        }
    }

void Menu::findAnElement() {
    List<Cancion>::Position pointSearch;
    string myString;
    char myCharA;
    int myInt;
    Nombre newInterprete;
    Cancion element;
    do {
        clearScreen();
        gotoxy(0,8);
        showList();
        gotoxy(0,0);
        cout<<"\n\tIngrese tipo de busqueda"<<endl;
        cout<<"Buscar por Nombre de la [C]ancion / Nombre del [I]nterprete / [P]osicion de lista / [R]egresar al menu: ";
        cin>> myCharA;
        cin.ignore();
        myCharA = toupper(myCharA);

        switch (myCharA) {
            case 'C':///Busqueda por Cancion
                cout<<endl<<"Ingrese la cancion a buscar: ";
                getline(cin,myString);
                element.setCancion(myString);

                ///Busqueda Lineal por Cancion
                if((pointSearch = myList->findDataLinear(element,Cancion::compareByCancion)) != nullptr) {
                    element = myList->retrieve(pointSearch);
                    cout<<endl<<"La cancion esta en: "<<element.getArchivo()<<endl<<endl;
                    }
                else {
                    cout<<endl<< "\tNo existe la cancion "<<endl;
                    }
                break;

            case 'I':///Busqueda por Interprete
                cout<<endl<<"Ingrese primer nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setFirstName(myString);
                cout<<endl<<"Ingrese segundo nombre del interprete: ";
                getline(cin, myString);
                newInterprete.setLastName(myString);
                element.setInterprete(newInterprete);

                ///Busque Lineal por Interprete
                if((pointSearch = myList->findDataLinear(element,Cancion::compareByInterprete)) != nullptr) {
                    element = myList->retrieve(pointSearch);
                    cout<<endl<<"La cancion esta en: "<<element.getArchivo()<<endl<<endl;
                    }
                else {
                    cout<<endl<<"\tNo existe la cancion "<<endl;
                    }
                break;

            case 'P':
                cout<<endl<<"Ingrese la posicion a buscar: ";
                cin>>myInt;
                if((pointSearch = myList->getPos(myInt-1)) != nullptr) {
                    element = myList->retrieve(pointSearch);
                    cout<<endl<<"La cancion esta en: "<<element.getArchivo()<<endl<<endl;
                    }
                else {
                    cout<<endl<<"\tNo existe la cancion "<<endl;
                    }

            case 'R':
                break;

            default:
                cout<<endl<<"ERROR, Ingrese opcion valida "<<endl;
            }
            cout<<"Presiona cualquier tecla para continuar"<<endl;
        gotoxy(0,8);
        showList();
        enterMenu();
        }
    while(myCharA != 'R');
    }

void Menu::invertList(){
    if(!myList->isEmpty()){
    List<Cancion>* List2(myList);
    List<Cancion>::Position aux(myList->getLastPos());
    List<Cancion>::Position auxPos(nullptr);

    do{
        List2->insertData(auxPos, aux->getData());
        aux = myList->getPrevPos(aux);
        myList->deleteData(aux->getNext());
        auxPos=List2->getLastPos();

    }while(aux != myList->getFirstPos());
    myList=List2;
    cout<< "\tSe ha invertido"<<endl;
    }else{
        cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
        enterMenu();
    }
}

void Menu::enterMenu() {
    getch();
    }

void Menu::clearScreen() {
    system("cls");
    }

///Constructor
Menu::Menu(List<Cancion>& _list): myList(&_list) {}

///Metodo
void Menu::mainMenu() {
    int opc, currentPos(-1), lastPos(-1);
    char opcContinue;
    List<Cancion>::Position PosNode(nullptr);

    while (opc!=10) {
        switch ((opc = showListMenu(currentPos, PosNode))) {
            case 1:
                do {
                    newElement(PosNode, currentPos);
                    lastPos = myList->getAmountNode();
                    cout<< "\nIngresar otra cancion [S]/[N]: ";
                    cin>> opcContinue;
                    opcContinue = toupper(opcContinue);
                    cout<<endl;
                    }
                while(opcContinue != 'N');
                showList();
                enterMenu();
                myList->writeToDisk(archiveMusic + "Canciones-sem.txt");
                //enterMenu();
                break;

            case 2:
                if(!myList->isEmpty()) {
                    if(PosNode == nullptr){
                            cout<< "\n\nCANCION NO SELECCIONADA"<<endl;
                            enterMenu();
                        }else{
                            List<Cancion>::Position AuxNode;
                            if((AuxNode = myList->getNextPos(PosNode)) == nullptr){
                                    AuxNode = myList->getFirstPos();
                                    currentPos = 0;
                                 }

                            deleteElement(PosNode);
                            PosNode = AuxNode;
                            lastPos = myList->getAmountNode();
                            myList->writeToDisk(archiveMusic + "Canciones-sem.txt");
                        }
                    }
                else {
                    cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
                    enterMenu();
                    }

                break;

            case 3:
            if(!myList->isEmpty()) {
                if(PosNode == nullptr) {
                    cout<< "\n\nCANCION NO SELECCIONADA"<<endl;
                    enterMenu();
                    }
                else {
                    EditElement(PosNode);
                    myList->writeToDisk(archiveMusic + "Canciones-sem.txt");
                    }
                }
            else {
                    cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
                    enterMenu();
                    }

                break;

            case 4:
                if(!myList->isEmpty()) {
                    findAnElement();
                    }
                else {
                    cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
                    enterMenu();
                    }
                break;

            case 5://siguiente
                if(!myList->isEmpty()) {
                    if((currentPos < lastPos) and PosNode != nullptr){
                        currentPos++;
                        PosNode = myList->getNextPos(PosNode);

                        }
                    else {
                        PosNode = myList->getFirstPos();
                        currentPos = 0;

                        }
                    }
                else {
                    cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
                    enterMenu();
                    }
                break;

            case 6://anterior
                if(!myList->isEmpty()) {
                        if(PosNode == nullptr){
                            PosNode = myList->getLastPos();
                        }
                    if(currentPos > 0){
                        PosNode = myList->getPrevPos(PosNode);
                        currentPos--;

                        }else{
                        PosNode = myList->getLastPos();
                        currentPos = lastPos;
                        }
                    }
                else {
                    cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
                    enterMenu();
                    }
                break;

            case 7:
                if(!myList->isEmpty()) {
                if(PosNode == nullptr) {
                    cout<< "\n\nCANCION NO SELECCIONADA"<<endl;
                    }
                else {
                    playMusic(PosNode->getData());
                    }
                }
            else {
                    cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
                    }
                enterMenu();
                break;
            case 8:
                if(!myList->isEmpty()) {
                if(PosNode == nullptr) {
                    cout<< "\n\nCANCION NO SELECCIONADA"<<endl;
                    }
                else {
                PlaySound(NULL,NULL,SND_FILENAME | SND_ASYNC);
                cout << "       STOP...." << endl;
                }
                }
                else {
                    cout<< "\n\nLISTA VACIA, debe ingresar canciones"<<endl;
                    }
                    enterMenu();
                break;

            case 9:
                invertList();
                myList->writeToDisk(archiveMusic + "Canciones-sem.txt");
                PosNode = myList->getPos(currentPos);
                break;

            case 10:
                clearScreen();
                cout << "\n\n\tFIN del programa" << endl;
                break;

            default:
                cout<< "ERROR, ingrese opcion valida" <<endl;
                enterMenu();
            }
        }
    }
