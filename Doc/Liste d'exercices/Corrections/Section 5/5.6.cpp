#include <iostream>
using namespace std;

class Sonic
{
    const float vitesse = 342.88;

public:
    Sonic();
    ~Sonic();

    float getVitesse();
    float distanceParcourue(float secondes);
};

Sonic::Sonic() { }

Sonic::~Sonic() { }

float Sonic::getVitesse()
{
    return vitesse;
}

float Sonic::distanceParcourue(float secondes)
{
    return vitesse * secondes;
}

int main()
{
    Sonic sonic;

    cout << "Sonic a parcouru " << sonic.distanceParcourue(7200) << " mètres en 2h";

    return 0;
}