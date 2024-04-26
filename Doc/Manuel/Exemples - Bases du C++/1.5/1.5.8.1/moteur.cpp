// moteur.cpp

#include "moteur.h"

Moteur::Moteur()
{
    voltage = 0;
    port = 0;
}

Moteur::Moteur(int Port)
{
    voltage = 0;
    port = Port;
}

Moteur::~Moteur() { }

float Moteur::getVoltage()
{
    return voltage;
}

void Moteur::setVoltage(float Voltage)
{
    voltage = Voltage;

    if (voltage == 0 || getEtat() == EtatComposant::Endommage)
    {
        desactiver();
        voltage = 0;
    }

    else
    {
        activer();
    }
}