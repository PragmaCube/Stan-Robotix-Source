#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "mastermind.h"

int main()
{
    srand(time(0));

    Mastermind jeu;
    jeu.genererCode();

    Couleur essai[4] = {Couleur::Rien, Couleur::Rien, Couleur::Rien, Couleur::Rien};

    cout << "Conversion chiffre -> couleur :\n0 -> Rouge\n1 -> Vert\n2 -> Bleu\n3 -> Jaune\n4 -> Gris\n5 -> Blanc\n6 -> Rose\n7 -> Orange\n8 -> Rien\n\n";

    int couleur;

    while (jeu.getBienPlace() != 4)
    {
        cout << "Il y a " << jeu.getBienPlace() << " couleur(s) bien placée(s) et " << jeu.getMalPlace() << " couleur(s) mal placée(s).\n";
        cout << "Début de la tentative #" << jeu.getTentatives() + 1 << " :\n";

        for (int i = 0; i < 4; i++)
        {
            cout << "Couleur #" << i + 1 << " :\n>>> ";
            cin >> couleur;

            switch (couleur)
            {
            case 0:
                essai[i] = Rouge;
                break;

            case 1:
                essai[i] = Vert;
                break;

            case 2:
                essai[i] = Bleu;
                break;

            case 3:
                essai[i] = Jaune;
                break;

            case 4:
                essai[i] = Gris;
                break;

            case 5:
                essai[i] = Blanc;
                break;

            case 6:
                essai[i] = Rose;
                break;

            case 7:
                essai[i] = Orange;
                break;
            
            default:
                essai[i] = Rien;
                break;
            }
        }

        jeu.nouvelEssai(essai);
    }

    return 0;
}