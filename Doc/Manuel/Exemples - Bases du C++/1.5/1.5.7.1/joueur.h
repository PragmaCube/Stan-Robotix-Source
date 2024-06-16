// joueur.h

#include "entite.h"

class Joueur : public Entite
{
    float pointDeVie;

public:
    Joueur();
    ~Joueur();

    float getPointDeVie();

    void setPointDeVie(float PointDeVie);
};