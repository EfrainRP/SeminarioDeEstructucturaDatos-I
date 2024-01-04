#include "Data.h"

using namespace std;
using namespace std::chrono;

int Data::RAND(int MIN,int MAX){
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(MIN,MAX);
    auto rand = bind(distribution, generator);
    int num = rand();
    return num;
}

Data::Data():Ticket(RAND(1111,9999)),Maleta(RAND(1,5)), ID(RAND(1111,9999)),Date("22/03/2022"), destiny("Canada"){}

Data::Data(Data& d): cont(d.cont), name(d.name),ID(RAND(1111,9999)){}

Data& Data::operator=(const Data& d) {
    name=d.name;
    cont=d.cont;
}

void Data::setCont(const int& c){
    cont = c;
}


void Data::setName(const string& n) {
    name=n;
    }

int Data::getCont()const{
    return this->cont;
    }


string Data::getName() const {
    return this->name;
    }

string Data::getDestiny() const {
    return this->destiny;
    }

int Data::getID() const {
    return this->ID;
    }

string Data::getDate() const {
    return this->Date;
    }

int Data::getTicket() const {
    return this->Ticket;
    }

int Data::getMaleta() const {
    return this->Maleta;
    }

string Data::toString() const{
    string myStr;
    myStr += "#N pasajero: "+ to_string(this->cont) + " | ";
    myStr += "Nombre: "+ this->name + " | ";
    myStr += "Destino: "+this->destiny + " | ";
    myStr += "ID: "+to_string(this->ID) + " | ";
    myStr += "Fecha: "+ this->Date + " | ";
    myStr += "#N Boleto: "+to_string(this->Ticket) + " | ";
    myStr += "#N Maleta: "+ to_string(this->Maleta) + " | ";

    return myStr;
}

