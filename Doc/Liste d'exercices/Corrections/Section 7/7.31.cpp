#include <iostream>
#include <vector>
using namespace std;

enum Type
{
    Ligne,
    Colonne
};

vector<int> permuter(vector<int> vecteur, Type type, int position, int decalage)
{
    int temp;

    switch(type)
    {
    case Ligne:
        temp = vecteur.at((position % 3) * 3 + (2 * decalage) % 3);

        vecteur.at((position % 3) * 3 + (2 * decalage) % 3) = vecteur.at((position % 3) * 3 + decalage % 3);
        vecteur.at((position % 3) * 3 + decalage % 3) = vecteur.at((position % 3) * 3);
        vecteur.at((position % 3) * 3) = temp;

        break;

    case Colonne:
        temp = vecteur.at((position % 3 + 6 * decalage) % 9);

        vecteur.at((position % 3 + 6 * decalage) % 9) = vecteur.at((position % 3 + 3 * decalage) % 9);
        vecteur.at((position % 3 + 3 * decalage) % 9) = vecteur.at(position % 3);
        vecteur.at(position % 3) = temp;

        break;

    default:
        break;
    }

    return vecteur;
}

int main()
{
    vector<int> vecteur = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 3; i++)
    {
        cout << "|" << vecteur.at(3 * i) << "|" << vecteur.at(3 * i + 1) << "|" << vecteur.at(3 * i + 2) << "|\n";
    }

    cout << endl;

    vecteur = permuter(vecteur, Type::Ligne, 0, 2);

    for (int i = 0; i < 3; i++)
    {
        cout << "|" << vecteur.at(3 * i) << "|" << vecteur.at(3 * i + 1) << "|" << vecteur.at(3 * i + 2) << "|\n";
    }

    return 0;
}