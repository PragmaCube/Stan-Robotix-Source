#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%?&*()-_=+/{}[]~,.':;<>";
    string texte = "    ";
    int compteur = 0;

    for (int i = 0; i < alphabet.length(); i++)
    {
        for (int j = 0; j < alphabet.length(); j++)
        {
            for (int k = 0; k < alphabet.length(); k++)
            {
                for (int l = 0; l < alphabet.length(); l++)
                {
                    texte[0] = alphabet[l];
                    texte[1] = alphabet[k];
                    texte[2] = alphabet[j];
                    texte[3] = alphabet[i];

                    compteur++;

                    // L'affichage peut durer plusieurs heures !
                    // Si l'on met en commentaire la ligne suivante
                    // le programme ne met que quelques secondes à
                    // prendre fin...
                    cout << "Chaine " << compteur << " : " << texte << endl;
                }
            }
        }
    }

    cout << "Fin avec " << compteur << " chaines";

    return 0;
}