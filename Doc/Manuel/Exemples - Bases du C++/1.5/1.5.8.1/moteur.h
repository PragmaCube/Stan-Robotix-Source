// moteur.h

#include "composant.h"

class Moteur : public Composant
{
    float voltage;
    int port;

public:
    Moteur();
    Moteur(int Port);
    ~Moteur();

    float getVoltage();

    void setVoltage(float Voltage);
};