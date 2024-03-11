#include <iostream>
#include <vector>
using namespace std;

vector<int> nombresPremiers(int borneInferieure, int borneSuperieure)
{
    int entierActuel = borneInferieure;
    bool premier;
    vector<int> listeNombres;

    for (int j = borneInferieure + 1; j < borneSuperieure; j++)
    {
        premier = true;

        for (int i = 2; i < entierActuel; i++)
        {
            if (entierActuel % i == 0)
            {
                premier = false;
            }
        }

        if (premier && entierActuel > borneInferieure)
        {
            listeNombres.push_back(entierActuel);
        }

        entierActuel++;
    }

    return listeNombres;
}

int main()
{
    vector<int> liste = nombresPremiers(18, 104);

    for (int i = 0; i < liste.size(); i++)
    {
        cout << liste.at(i) << endl;
    }

    return 0;
}