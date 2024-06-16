#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    string texte;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int cle;

    cout << "Veuillez rentrer le texte à chiffrer :\n>>> ";
    // Pour les textes avec espaces
    getline(cin, texte);
    cout << "Veuillez rentrer la clé de chiffrement :\n>>> ";
    cin >> cle;

    for (int i = 0; i < texte.length(); i++)
    {
        for (int j = 0; j < alphabet.length(); j++)
        {
            if (texte[i] == alphabet.at(j))
            {
                texte[i] = alphabet.at((j + cle) % alphabet.size());
                break;
            }
        }
    }

    cout << "Le message chiffré est : " << texte;
    
    return 0;
}