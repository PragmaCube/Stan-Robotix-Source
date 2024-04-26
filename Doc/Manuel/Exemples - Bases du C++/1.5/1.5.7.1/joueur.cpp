// joueur.cpp

#include "joueur.h"

Joueur::Joueur() { }

Joueur::~Joueur() { }

float Joueur::getPointDeVie()
{
    return pointDeVie;
}

void Joueur::setPointDeVie(float PointDeVie)
{
    pointDeVie = PointDeVie;
}