#include <iostream>
using namespace std;

#include "simulation.h"

int main()
{
    Joueur joueur1;
    Joueur joueur2;
    Jeu jeu;

    jeu.setJoueur1(joueur1);
    jeu.setJoueur2(joueur2);

    Simulation simulation;

    simulation.setJeu(jeu);

    simulation.simuler();

    cout << "Le joueur 1 a " << simulation.getNombreVictoiresJoueur1() << " victoires.\n" << endl << "Le joueur 2 a " << simulation.getNombreVictoiresJoueur2() << "victoires.";

    return 0;
}