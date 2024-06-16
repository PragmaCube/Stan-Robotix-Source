#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int nbrBits;
    int bit;
    int resultat = 0;

    cout << "Nombre de bits à décoder :\n>>> ";
    cin >> nbrBits;

    for (int i = 1; i <= nbrBits; i++)
    {
        cout << "Bits " << i << " : ";
        cin >> bit;

        resultat += bit * pow(2, nbrBits - i);
    }

    cout << "Le résultat est : " << resultat;
    
    return 0;
}