#ifndef CELSIUS_H_INCLUDED
#define CELSIUS_H_INCLUDED

class Celsius{
private:
    double cels;

public:
    Celsius();
    Celsius(Celsius&);
    Celsius& operator = (const Celsius&);

    double getCels();
    void setCels(const double&);

    double convertToKel();
    double convertToFahren();
};

#endif // CELSIUS_H_INCLUDED
