#include <ctime>
#include <iostream>
using namespace std;

enum Deplacement
{
    Avancer,
    Reculer,
    TournerDroite,
    TournerGauche,
    Rien
};

Deplacement autonome(int secondes)
{
    if (secondes < 10)
    {
        return Avancer;
    }

    if (secondes < 12)
    {
        return TournerDroite;
    }

    if (secondes < 20)
    {
        return Avancer;
    }

    if (secondes < 28)
    {
        return Reculer;
    }

    if (secondes < 34)
    {
        return TournerDroite;
    }

    if (secondes < 40)
    {
        return Avancer;
    }

    if (secondes < 46)
    {
        return Reculer;
    }

    if (secondes < 48)
    {
        return TournerDroite;
    }

    if (secondes < 58)
    {
        return Reculer;
    }

    return Rien;
}

int main()
{
    time_t temps = time(0);
    tm* heureActuelle = localtime(&temps);
    int secondes = heureActuelle->tm_sec;

    Deplacement deplacement = autonome(secondes);

    switch(deplacement)
    {
        case Avancer:
            cout << "Le robot avance !";
            break;

        case Reculer:
            cout << "Le robot recule !";
            break;

        case TournerDroite:
            cout << "Le robot tourne à    droite !";
            break;

        case TournerGauche:
            cout << "Le robot tourne à    gauche !";
            break;

        case Rien:
            cout << "Le robot ne fait rien !";
            break;
    }

    return 0;
}