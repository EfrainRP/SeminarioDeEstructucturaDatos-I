#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#include "Nombre.h"

class Info {
    private:
        //Atributos
        int ID;
        Nombre name;
        std::string address;
        std::string email;

        //Metodo privado
        void copyAll(const Info&);//Guardara el objeto creado a una copia

    public:
        //constructor
        Info();
        Info(const Info&);

        //Metodos (Getters,Setters y etc)
        int getID() const;
        Nombre getName() const;
        std::string getAddress() const;
        std::string getEmail() const;

        void setID(const int&);
        void setName(const Nombre&);
        void setAddress(const std::string&);
        void setEmail(const std::string&);

        std::string toString()const;
        Info& operator = (const Info&);
        bool operator == (const Info&) const;
        bool operator != (const Info&) const;
        bool operator < (const Info&) const;
        bool operator <= (const Info&) const;
        bool operator > (const Info&) const;
        bool operator >= (const Info&) const;


        static int compareByID(const Info&, const Info&);
        static int compareByName(const Info&, const Info&);
    };

#endif // INFO_H_INCLUDED
