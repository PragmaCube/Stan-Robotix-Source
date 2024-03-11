// main.cpp

#include "moteur.h"

#include <iostream>
using namespace std;

int main()
{
    Moteur* moteur = new Moteur(1);

    moteur->setVoltage(1);

    while(moteur->getActif())
    {
        moteur->setVoltage(1);
        cout << moteur->getDureeVie() << endl;
    }

    return 0;
}