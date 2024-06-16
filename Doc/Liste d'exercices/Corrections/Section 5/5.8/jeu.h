#include "joueur.h"

enum TypeVictoire
{
    Joueur1Victorieux,
    Joueur2Victorieux,
    Egalite
};

class Jeu
{
    Joueur joueur1;
    Joueur joueur2;
    int nombreTours;

public:
    Jeu();
    ~Jeu();

    int getNombreTours();
    
    Joueur getJoueur1();
    Joueur getJoueur2();

    void setNombreTours(int);
    void setJoueur1(Joueur);
    void setJoueur2(Joueur);

    TypeVictoire jouer();
};