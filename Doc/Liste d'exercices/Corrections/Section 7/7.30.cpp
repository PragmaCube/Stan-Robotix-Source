#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<float> serie;

    int nbrDonnees = 0;
    float nbr;

    cout << "Nombre de données à rentrer : ";
    cin >> nbrDonnees;

    for (int i = 0; i < nbrDonnees; i++)
    {
        cout << ">>> ";
        cin >> nbr;

        serie.push_back(nbr);
    }

    float somme = 0;
    float sommeCarres = 0;

    for (int i = 0; i < serie.size(); i++)
    {
        somme += serie.at(i);
        sommeCarres += serie.at(i) * serie.at(i);
    }

    cout << "Écart-type : " << sqrt(sommeCarres / serie.size() - somme * somme / (serie.size() * serie.size()));

    return 0;
}