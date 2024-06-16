#include <iostream>
using namespace std;

int main()
{
    float coupures[10] = {100, 50, 20, 10, 5, 2, 1, 0.25, 0.1, 0.05};
    int coupuresRendues[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    float prixAchat;
    float sommeDonnee;

    cout << "Entrer le prix d'achat du produit :\n>>> ";
    cin >> prixAchat;

    cout << "Entrer la somme donnée par le client :\n>>> ";
    cin >> sommeDonnee;

    if (prixAchat < 0 || sommeDonnee < prixAchat)
    {
        cout << "Au moins une des variables n'a pas une valeur possible.";

        return 0;
    }

    sommeDonnee -= prixAchat;

    for (int i = 0; i < sizeof(coupures) / sizeof(float); i++)
    {
        while (sommeDonnee > 0)
        {
            if (sommeDonnee - coupures[i] > 0)
            {
                coupuresRendues[i]++;

                sommeDonnee -= coupures[i];
            }

            else
            {
                break;
            }
        }
    }

    cout << "Coupures rendues :\n";

    for (int i = 0; i < sizeof(coupures) / sizeof(float); i++)
    {
        if (coupuresRendues[i] != 0)
        {
            cout << coupuresRendues[i] << "x " << coupures[i] << "$ ";
        }
    }

    return 0;
}