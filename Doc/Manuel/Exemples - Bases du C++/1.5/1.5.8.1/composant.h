// composant.h

enum EtatComposant
{
    Fonctionnel,
    Endommage
};

class Composant
{
    EtatComposant etat;
    bool actif;
    int dureeVie;
    
    const int dureeVieMaxComposant = 500;

public:
    Composant();
    ~Composant();

    EtatComposant getEtat();

    bool getActif();

    int getDureeVie();

    void activer();
    void desactiver();
};