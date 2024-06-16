#include "simulation.h"

Simulation::Simulation() { }

Simulation::~Simulation() { }

int Simulation::getNombreVictoiresJoueur1()
{
    return nombreVictoiresJoueur1;
}

int Simulation::getNombreVictoiresJoueur2()
{
    return nombreVictoiresJoueur2;
}

int Simulation::getNombreSimulations()
{
    return nombreSimulations;
}

Jeu Simulation::getJeu()
{
    return jeu;
}

void Simulation::setNombreSimulations(int NombreSimulations)
{
    nombreSimulations = NombreSimulations;
}

void Simulation::setJeu(Jeu jeu_)
{
    jeu = jeu_;
}

void Simulation::simuler()
{
    jeu.setNombreTours(5);
    TypeVictoire typeVictoire;
    nombreVictoiresJoueur1 = nombreVictoiresJoueur2 = 0;

    for (int i = 0; i < nombreSimulations; i++)
    {
        typeVictoire = jeu.jouer();

        switch(typeVictoire)
        {
            case TypeVictoire::Joueur1Victorieux:
                nombreVictoiresJoueur1++;
                break;

            case TypeVictoire::Joueur2Victorieux:
                nombreVictoiresJoueur2++;
                break;

            default:
                break;
        }
    }
}