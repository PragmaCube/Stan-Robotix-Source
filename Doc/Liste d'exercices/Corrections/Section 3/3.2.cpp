#include <iostream>
using namespace std;

int main()
{
    float pluie[12] = {27.3, 20.9, 29.7, 67.7, 81.2, 87.0, 89.3, 94.1, 83.0, 89.1, 76.7, 38.8};
    float neige[12] = {49.5, 41.2, 36.2, 12.9, 0, 0, 0, 0, 0, 1.8, 19.0, 48.9};

    float moyennePluie = 0, moyenneNeige = 0, totalPluie = 0, totalNeige = 0;

    for (int i = 0; i < 12; i++)
    {
        totalPluie += pluie[i];
        totalNeige += neige[i];
    }

    moyennePluie = totalPluie / 12;
    moyenneNeige = totalNeige / 12;

    cout << "Pluie :\n Total : " << totalPluie << "\nMoyenne : " << moyennePluie;
    cout << "Neige :\n Total : " << totalNeige << "\nMoyenne : " << moyenneNeige;
    
    return 0;
}