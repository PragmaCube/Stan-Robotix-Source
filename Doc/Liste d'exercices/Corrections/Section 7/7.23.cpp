#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int nbrChiffresSignificatifs;
    float nbr;
    
    int partieEntiere;
    float partieDecimale;

    int nbrChiffresPartieDecimale = 0;

    vector<int> decompositionPartieEntiere;
    vector<int> decompositionPartieDecimale;

    float resultat = 0;

    cout << "Indiquer le nombre à arrondir :\n>>> ";
    cin >> nbr;

    cout << "Indiquer le nombre de chiffres significatifs :\n>>> ";
    cin >> nbrChiffresSignificatifs;

    if (nbr > 0)
    {
        partieEntiere = (int)floor(nbr);
        partieDecimale = nbr - floor(nbr);

        while (partieDecimale != 0)
        {
            decompositionPartieDecimale.push_back(int(floor(partieDecimale * 10)));
            partieDecimale = partieDecimale * 10 - decompositionPartieDecimale[nbrChiffresPartieDecimale];
            nbrChiffresPartieDecimale++;
        }
    }

    else
    {
        partieEntiere = (int)ceil(nbr);
        partieDecimale = nbr + ceil(nbr);

        while (partieDecimale != 0)
        {
            decompositionPartieDecimale.push_back(int(ceil(partieDecimale * 10)));
            partieDecimale = partieDecimale * 10 - decompositionPartieDecimale[nbrChiffresPartieDecimale];
            nbrChiffresPartieDecimale++;
        }
    }

    while (partieEntiere != 0)
    {
        decompositionPartieEntiere.push_back(partieEntiere % 10);
        partieEntiere = (partieEntiere - partieEntiere % 10) / 10;
    }

    if (decompositionPartieEntiere.size() == 0)
    {
        int position = 0;

        while (decompositionPartieDecimale[position] == 0)
        {
            position++;
        }

        for (int i = position; i < position + min((int)decompositionPartieDecimale.size(), nbrChiffresSignificatifs); i++)
        {
            if (i == position + nbrChiffresSignificatifs - 1)
            {
                decompositionPartieDecimale[i] = int(round(float(decompositionPartieDecimale[i]) + float(decompositionPartieDecimale[i + 1]) / 10));
            }

            resultat += decompositionPartieDecimale[i] * pow(10, - i - 1);
        }
    }

    else
    {
        for (int i = 0; i < min((int)decompositionPartieEntiere.size(), nbrChiffresSignificatifs); i++)
        {
            if (i == nbrChiffresSignificatifs - 1 && (int)decompositionPartieEntiere.size() != nbrChiffresSignificatifs)
            {
                decompositionPartieEntiere[(int)decompositionPartieEntiere.size() - i - 1] = int(round(float(decompositionPartieEntiere[(int)decompositionPartieEntiere.size() - i - 1]) + float(decompositionPartieEntiere[(int)decompositionPartieEntiere.size() - i - 2]) / 10));
            }

            resultat += decompositionPartieEntiere[(int)decompositionPartieEntiere.size() - i - 1] * pow(10, (int)decompositionPartieEntiere.size() - i - 1);
        }

        for (int i = 0; i < min((int)decompositionPartieDecimale.size(), nbrChiffresSignificatifs - (int)decompositionPartieEntiere.size()); i++)
        {
            if (i + min((int)decompositionPartieEntiere.size(), nbrChiffresSignificatifs) == nbrChiffresSignificatifs - 1)
            {
                decompositionPartieDecimale[i] = int(round(float(decompositionPartieDecimale[i]) + float(decompositionPartieDecimale[i + 1]) / 10));
            }

            resultat += decompositionPartieDecimale[i] * pow(10, - i - 1);
        }
    }

    cout << "Nombre approximé : " << resultat << endl;

    return 0;
}