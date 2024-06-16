#include "jeu.h"

class Simulation
{
    Jeu jeu;
    
    int nombreVictoiresJoueur1;
    int nombreVictoiresJoueur2;
    int nombreSimulations;

public:
    Simulation();
    ~Simulation();

    int getNombreVictoiresJoueur1();
    int getNombreVictoiresJoueur2();
    int getNombreSimulations();

    Jeu getJeu();

    void setNombreSimulations(int);
    void setJeu(Jeu);

    void simuler();
};