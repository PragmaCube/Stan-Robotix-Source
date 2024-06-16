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
    float vitesse;
    ModeVitesse mode = modeLent;
    
    cout << "Veuillez rentrer la vitesse du robot : ";
    cin >> vitesse;

    switch(mode)
    {
        case modeLent:
            vitesse *= 0.5;
            break;

        case modeMoyen:
            vitesse *= 0.75;
            break;

        case modeRapide:
            vitesse *= 0.9;
            break;

        default:
            break;
    }

    cout << "La nouvelle vitesse est " << vitesse;

    return 0;
}