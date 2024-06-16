#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

float trajectoire(float distanceParcourue, float vitesseInitiale, float angle)
{
    return - (9.81 / 2) * distanceParcourue * distanceParcourue / (cos(angle) * cos(angle) * vitesseInitiale * vitesseInitiale) + tan(angle) * distanceParcourue;
}

int main()
{
    // Dichotomie pour trouver la deuxième racine,
    // la première étant 0.

    float a;
    float b;
    float vitesseInitiale = 75;

    vector<float> distance;

    for (float angle = 0; angle < 2 * atanf(1); angle += 0.1)
    {
        a = 0.5;
        b = 700;

        while (abs(a - b) > 0.001)
        {
            if (trajectoire(a, vitesseInitiale, angle) * trajectoire((a + b) / 2, vitesseInitiale, angle) < 0)
            {
                b = (a + b) / 2;
            }

            else
            {
                a = (a + b) / 2;
            }
        }

        distance.push_back(abs((a + b) / 2 - 420));
    }

    float minimum = distance.at(0);
    int positionMinimum = 0;

    for (int i = 1; i < distance.size(); i++)
    {
        if (distance.at(i) < minimum)
        {
            minimum = distance.at(i);
            positionMinimum = i;
        }
    }

    cout << "L'angle optimal est : " << 0.1 * positionMinimum << " avec un écart de " << distance.at(positionMinimum);
    
    return 0;
}