#include "info.h"
#include <string>
#include <algorithm>

using namespace std;

void Info::copyAll(const Info& I) {
    ID = I.ID;
    name = I.name;
    address = I.address;
    email = I.email;
    }

Info::Info() {}

Info::Info(const Info& I) {
    copyAll(I);
    }

int Info::getID() const {
    return ID;
    }

Nombre Info::getName() const {
    return name;
    }

string Info::getAddress() const {
    return address;
    }

string Info::getEmail() const {
    return email;
    }

void Info::setID(const int& i) {
    ID = i;
    }

void Info::setName(const Nombre& i) {
    name = i;
    }

void Info::setAddress(const std::string& i) {
    address = i;
    }

void Info::setEmail(const std::string& i) {
    email = i;
    }

string Info::toString() const {

    }

Info& Info::operator=(const Info&i) {
    copyAll(i);
    return *this;
    }

bool Info::operator == (const Info&i) const{
    return *this == i;
    }
bool Info::operator != (const Info&i) const{
    return !(*this==i);
    }

bool Info::operator < (const Info&i) const{
    return *this < i;
    }

bool Info::operator <= (const Info&i) const{
    return (*this < i) or (*this==i);
    }

bool Info::operator > (const Info&i) const{
    return !(*this<=i);
    }

bool Info::operator >= (const Info&i) const{
    return !(*this<i);
    }


int Info::compareByID(const Info& A, const Info& B) {
    return A.ID-B.ID;
    }

int Info::compareByName(const Info& A, const Info& B) {
    return A.name.toString().compare(B.name.toString());
    }
