#include <iostream>
using namespace std;

void separer(int nombre)
{
    int unite = nombre % 10;
    int dizaine = ((nombre - unite) / 10) % 10;
    int centaine = ((nombre - unite - 10 * dizaine) / 100) % 10;

    cout << "La décomposition de " << nombre << " en centaine / dizaine / unité est " << centaine << "/" << dizaine << "/" << unite;
}

int main()
{
    int nbr;

    cout << "Choisir un nombre entre 1 et 999 :\n>>> ";
    cin >> nbr;

    separer(nbr);

    return 0;
}