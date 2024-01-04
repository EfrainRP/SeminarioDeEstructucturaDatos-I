#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <functional>
#include <chrono>

class Random {
    private:
        int value;
        void copyAll(const Random& r);
    public:
        Random();
        Random(Random&);
        Random& operator = (const Random& r);

        void setValue(const int&);
        int getValue();
    };

void Random::copyAll(const Random& r){
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(1111,9999);
    auto rand = bind(distribution, generator);

    value = r.rand();
}

Random::Random() {
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(1111,9999);
    auto rand = bind(distribution, generator);
}

Random::Random(Random& r){
    copyAll();
}

Random& operator = (const Random& r){
    copyAll();
    *this;
}

void Random::setValue(const int& r) {
    value = r;
    }

int Random::getValue() { const
    return this->value;
    }


#endif // RANDOM_H_INCLUDED
