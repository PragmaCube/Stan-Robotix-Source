enum Couleur
{
    Rouge,
    Vert,
    Bleu,
    Jaune,
    Gris,
    Blanc,
    Rose,
    Orange,

    Rien
};

class Mastermind
{
    Couleur code[4];
    Couleur essai[4];

    int tentatives;

public:
    Mastermind();
    ~Mastermind();

    int getBienPlace();
    int getMalPlace();
    int getTentatives();

    void nouvelEssai(Couleur[4]);
    
    void genererCode();

    void afficherCode();
};