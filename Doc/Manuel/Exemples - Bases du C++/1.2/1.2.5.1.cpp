#include <iostream>
using namespace std;

enum ModeVitesse
{
    modeLent,
    modeMoyen,
    modeRapide
};

int main()
{
    float vitesse = 6.5;
    float tempsEcoule = 0;
    float distanceParcourue = 0;

    ModeVitesse mode = modeRapide;
    
    while (tempsEcoule < 100)
    {
        if (distanceParcourue < 100 || tempsEcoule > 85)
        {
            mode = modeRapide;
        }

        else if (tempsEcoule < 60 && distanceParcourue > 100)
        {
            mode = modeLent;
        }

        else
        {
            mode = modeMoyen;
        }

        tempsEcoule += 0.5;

        cout << "Temps écoulé : " << tempsEcoule << " Distance parcourue : ";

        switch (mode)
        {
            case modeLent:
                distanceParcourue += 0.5 * vitesse * 0.5;
                cout << distanceParcourue << " Mode lent" << endl;
                break;

            case modeMoyen:
                distanceParcourue += 0.5 * vitesse * 0.75;
                cout << distanceParcourue << " Mode moyen" << endl;
                break;

            case modeRapide:
                distanceParcourue += 0.5 * vitesse * 0.9;
                cout << distanceParcourue << " Mode rapide" << endl;
                break;

            default:
                break;
        }
    }

    return 0;
}