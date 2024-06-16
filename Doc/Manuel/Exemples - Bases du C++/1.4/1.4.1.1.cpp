#include <iostream>
#include <cmath> // On utilise ce module pour la fonction sinus
using namespace std;

float f(float x)
{
    if (x == 0)
    {
        return 1;
    }

    return sin(x) / x;
}

void moyenne(float* valeurs, float* resultat, int taille)
{
    // Bonne pratique pour éviter d'ajouter des valeurs à       une variable potentiellement
    // pas initialisée.
    *resultat = 0;

    for (int i = 0; i < taille; i++)
    {
        *resultat += valeurs[i];
    }

    *resultat /= (float)taille;
}

int main()
{
    float resultat = 0, x = -1;
    float valeurs[4];

    for (int i = 0; i < sizeof(valeurs) / sizeof(float); i++)
    {
        valeurs[i] = f(x);
        x += 0.5;
    }

    moyenne(valeurs, &resultat, 4);

    cout << "La moyenne des valeurs est : " << resultat;

    return 0;
}