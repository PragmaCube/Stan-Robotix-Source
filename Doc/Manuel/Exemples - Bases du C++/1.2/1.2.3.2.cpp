#include <iostream>
using namespace std;

int main()
{
    int compteur = 0;
    int entierActuel = 2;
    bool premier;

    while (compteur < 100)
    {
        premier = true;
        
        for (int i = 2; i < entierActuel; i++)
        {
            if (entierActuel % i == 0)
            {
                premier = false;
            }
        }

        if (premier)
        {
            cout << "Le nombre premier #" <<  compteur + 1 << " est " << entierActuel << endl;
            compteur++;
        }

        entierActuel++;
    }
    
    return 0;
}