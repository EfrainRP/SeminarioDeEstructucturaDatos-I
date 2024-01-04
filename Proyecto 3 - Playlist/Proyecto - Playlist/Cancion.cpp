#include "Cancion.h"
#include <string>
#include <algorithm>

using namespace std;

//Metodo privado
void Cancion::copyAll(const Cancion& c) {
    cancion = c.cancion;
    autor = c.autor;
    interprete = c.interprete;
    ranking = c.ranking;
    archivo = c.archivo;
    }

//Constructores
Cancion::Cancion() {}

Cancion::Cancion(const Cancion& n) {
    copyAll(n);
    }

//Metodos (Getters,Setters y etc)
std::string Cancion::getCancion() const {
    return cancion;
    }

Nombre Cancion::getAutor() const {
    return autor;
    }

Nombre Cancion::getInterprete() const {
    return interprete;
    }

int Cancion::getRanking() const {
    return ranking;
    }

std::string Cancion::getArchivo() const {
    return archivo;
    }


void Cancion::setCancion(const std::string& _cancion) {
    cancion = _cancion;
    }

void Cancion::setAutor(const Nombre& _autor) {
    autor = _autor;
    }

void Cancion::setInterprete(const Nombre& _interprete) {
    interprete = _interprete;
    }

void Cancion::setRanking(const int& _ranking) {
    ranking = _ranking;
    }

void Cancion::setArchivo(const std::string& _archivo) {
    archivo = _archivo;
    }


std::string Cancion::toString()const {
    string myStr;
    myStr += cancion.c_str();
    myStr.resize (26,' ');
    myStr.insert(26, 1, char(186));

    myStr += autor.toString().c_str();
    myStr.insert(27, 1, ' ');
    myStr.resize (47,' ');
    myStr.insert(47, 1, char(186));

    myStr += interprete.toString().c_str();
    myStr.insert(48, 1, ' ');
    myStr.resize (69,' ');
    myStr.insert(69, 1, char(186));

    myStr += "    " +  to_string(ranking);
    myStr.insert(68, 1, ' ');
    myStr.resize (81,' ');
    myStr.insert(81, 1, char(186));

    size_t pos = archivo.find("ic");
    myStr += archivo.substr(pos+2);
    myStr.insert(82, 1, ' ');
    myStr.resize (111,' ');
    myStr.insert(111, 1, char(186));

    //c_str() es un puntero temporal cuyo contenido es una cadena que apunta a una matriz de caracteres
    return myStr;
    }

//Sobrecarga de operadores
Cancion& Cancion::operator =(const Cancion& n) {
    copyAll(n);
    return *this;
    }
bool Cancion::operator==(const Cancion& c) const {
    return cancion == c.cancion;
    }

bool Cancion::operator!=(const Cancion& c) const {
    return !(*this==c);
    }

bool Cancion::operator<(const Cancion& c) const {
    return cancion < c.cancion;
    }

bool Cancion::operator<=(const Cancion& c) const {
    return (*this < c) or (*this==c);
    }

bool Cancion::operator>(const Cancion& c) const {
    return !(*this<=c);
    }

bool Cancion::operator>=(const Cancion& c) const {
    return !(*this<c);
    }

int Cancion::compareByCancion(const Cancion& a, const Cancion& b) {
    return a.cancion.compare(b.cancion);
    }

int Cancion::compareByInterprete(const Cancion& a, const Cancion& b) {
    return a.interprete.toString().compare(b.interprete.toString());
    }

ostream& operator << (ostream& os, Cancion& c){

    os<<c.cancion << endl;
    os<<c.autor<< endl;
    os<<c.interprete << endl;
    os<<c.ranking << endl;
    os<<c.archivo;

    return os;
}

istream& operator >> (istream& is, Cancion& c){
    getline(is, c.cancion);
    is>>c.autor;
    is>>c.interprete;
    is>>c.ranking;
    getline(is.ignore(),c.archivo);

    return is;
}


