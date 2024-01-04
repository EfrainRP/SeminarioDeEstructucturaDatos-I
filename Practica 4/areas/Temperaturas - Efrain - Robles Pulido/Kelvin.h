#ifndef KELVIN_H_INCLUDED
#define KELVIN_H_INCLUDED

class Kelvin{
private:
    double kel;

public:
    Kelvin();
    Kelvin(Kelvin&);
    Kelvin& operator = (const Kelvin&);

    double getKelvin();
    void setKelvin(const double&);

    double convertToCels();
};

#endif // KELVIN_H_INCLUDED
