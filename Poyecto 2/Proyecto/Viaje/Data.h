#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>
#include <random>
#include <chrono>
#include <functional>
#include <string>

class Data {
    private:
        int cont;
        std::string name;
        std::string destiny;
        int ID;
        std::string Date;
        int Ticket;
        int Maleta;

        int RAND(int MIN,int MAX);

    public:
        Data();
        Data(Data&);
        Data& operator = (const Data&);

        void setName(const std::string&);
        void setCont(const int&);

        int getCont()const;
        std::string getName()const;
        std::string getDestiny()const;
        int getID()const;
        std::string getDate()const;
        int getTicket()const;
        int getMaleta() const;

        std::string toString()const;
    };



#endif // DATA_H_INCLUDED
