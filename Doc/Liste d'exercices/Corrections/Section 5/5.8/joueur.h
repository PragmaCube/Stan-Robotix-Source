enum Action
{
    Cooperer,
    Tricher
};

class Joueur
{
    int score;

public:
    Joueur();
    ~Joueur();

    int getScore();

    void setScore(int);
};

Action choixAleatoire();