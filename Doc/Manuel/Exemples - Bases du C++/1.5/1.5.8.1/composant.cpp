// composant.cpp

#include "composant.h"

Composant::Composant()
{
    etat = EtatComposant::Fonctionnel;
    actif = false;
    dureeVie = 0;
}

Composant::~Composant() { }

EtatComposant Composant::getEtat()
{
    return etat;
}

bool Composant::getActif()
{
    return actif;
}

int Composant::getDureeVie()
{
    return dureeVie;
}

void Composant::activer()
{
    if (etat == EtatComposant::Fonctionnel)
    {
        if (!actif)
        {
            actif = true;
        }
        
        dureeVie++;
    }

    if (dureeVie == dureeVieMaxComposant)
    {
        actif = false;
        etat = EtatComposant::Endommage;
    }
}

void Composant::desactiver()
{
    actif = false;
}