#include <iostream>
using namespace std;

int* inverser(int* tableau, int taille)
{
    int valeurTemporaire;

    for (int i = 0; i < taille / 2; i++)
    {
        valeurTemporaire = tableau[i];
        tableau[i] = tableau[taille - i - 1];
        tableau[taille - i - 1] = valeurTemporaire;
    }

    return tableau;
}

int main()
{
    int tableau[4] = {6622, 3990, 296, 2626};
    int* tableauInverse = inverser(tableau, (sizeof(tableau) / sizeof(int)));

    for (int i = 0; i < sizeof(tableau) / sizeof(int); i++)
    {
        cout << tableauInverse[i] << endl;
    }

    return 0;
}