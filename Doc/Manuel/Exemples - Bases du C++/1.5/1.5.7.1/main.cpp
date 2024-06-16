// main.cpp

#include "joueur.h"

int main()
{
    Joueur joueur;

    // Il est possible d'accéder aux méthodes de la classe Entite car
    // Joueur hérite de Entite
    joueur.setX(0);
    joueur.setY(0);
    joueur.setPointDeVie(30);
    
    return 0;
}