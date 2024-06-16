#include <iostream>
using namespace std;

#include "jeu.h"

Jeu::Jeu() { }
Jeu::~Jeu() { }

int Jeu::getNombreTours()
{
    return nombreTours;
}

Joueur Jeu::getJoueur1()
{
    return joueur1;
}

Joueur Jeu::getJoueur2()
{
    return joueur2;
}

void Jeu::setNombreTours(int NombreTours)
{
    nombreTours = NombreTours;
}

void Jeu::setJoueur1(Joueur Joueur1)
{
    joueur1 = Joueur1;
}

void Jeu::setJoueur2(Joueur Joueur2)
{
    joueur2 = Joueur2;
}

TypeVictoire Jeu::jouer()
{
    Action derniereAction = Action::Cooperer;
    Action actionAleatoire;

    joueur1.setScore(0);
    joueur2.setScore(0);

    for (int i = 0; i < nombreTours; i++)
    {
        actionAleatoire = choixAleatoire();

        switch(actionAleatoire)
        {
            case Action::Cooperer:
                if (derniereAction == actionAleatoire)
                {
                    joueur1.setScore(joueur1.getScore() + 3);
                    joueur2.setScore(joueur2.getScore() + 3);
                }

                else
                {
                    joueur1.setScore(joueur1.getScore() - 1);
                    joueur2.setScore(joueur2.getScore() + 5);
                }

                break;

            case Action::Tricher:
                if (derniereAction != actionAleatoire)
                {
                    joueur1.setScore(joueur1.getScore() + 5);
                    joueur2.setScore(joueur2.getScore() - 1);
                }

                break;
        }

        derniereAction = actionAleatoire;

        cout << "Joueur 1 : " << joueur1.getScore() << endl << "Joueur 2 : " << joueur2.getScore() << endl;
    }

    if (joueur1.getScore() > joueur2.getScore())
    {
        return TypeVictoire::Joueur1Victorieux;
    }

    else if (joueur1.getScore() < joueur2.getScore())
    {
        return TypeVictoire::Joueur1Victorieux;
    }

    else
    {
        return TypeVictoire::Egalite;
    }
}