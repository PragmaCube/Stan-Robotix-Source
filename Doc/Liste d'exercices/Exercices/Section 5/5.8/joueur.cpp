// joueur.cpp

#include "joueur.h"

#include <random>
using namespace std;

Joueur::Joueur() { }
Joueur::~Joueur() { }

int Joueur::getScore()
{
    return score;
}

void Joueur::setScore(int Score)
{
    score = Score;
}

Action choixAleatoire()
{
    int nbr = rand() % 2;

    if (nbr == 0)
    {
        return Action::Cooperer;
    }

    return Action::Tricher;
}