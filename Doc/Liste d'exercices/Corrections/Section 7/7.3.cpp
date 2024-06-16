#include <vector>
using namespace std;

vector<int> triSelection(vector<int> vecteur)
{
    int element;
    int elementIndice;
    int taille = vecteur.size();
    vector<int> vecteurTrie;

    while(vecteurTrie.size() < taille)
    {
        element = vecteur.at(0);
        elementIndice = 0;

        for (int i = 0; i < vecteur.size(); i++)
        {
            if (vecteur.at(i) < element)
            {
                element = vecteur.at(i);
                elementIndice = i;
            }
        }

        vecteurTrie.push_back(element);
        vecteur.erase(vecteur.begin() + elementIndice);
    }

    return vecteurTrie;
}