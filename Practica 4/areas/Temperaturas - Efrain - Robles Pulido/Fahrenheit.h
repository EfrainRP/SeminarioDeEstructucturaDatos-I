#ifndef FAHRENHEIT_H_INCLUDED
#define FAHRENHEIT_H_INCLUDED

class Fahrenheit{
private:
    double Fahren;

public:
    Fahrenheit();
    Fahrenheit(Fahrenheit&);
    Fahrenheit& operator = (const Fahrenheit&);

    double getFahren();
    void setFahren(const double&);

    double convertToCels();
};


#endif // FAHRENHEIT_H_INCLUDED
