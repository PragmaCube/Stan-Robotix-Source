#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void affiche(vector<string> grille)
{
    for (int i = 0; i < grille.size(); i++)
    {
        std::cout << grille.at(i) << std::endl;
    }
}

float f(float x)
{
    return cos(x * x) - sin(x);
}

int main()
{
    vector<string> grille;

    for (int i = 0; i < 41; i++)
    {
        grille.push_back("|                                                                                 | ");
    }

    grille.push_back("                                                                                   ");

    int x = 41, y = 20, zoom = 2;
    float temps = -10, precision = 0.04 / (zoom * zoom);
    float minX;

    int posX = 0, posY = 0;

    bool premiereValeur = true;

    while(true)
    {
        posX = (int)round(x + zoom * 7 * temps);
        posY = (int)round(y -  zoom * 5 * f(temps));

        if (posX > 81)
        {
            break;
        }

        if (posY > 0 && posY < grille.size() - 1 && posX > 0)
        {
            if (premiereValeur)
            {
                minX = temps;

                premiereValeur = false;
            }

            grille.at(posY)[posX] = '.';
        }

        temps += precision;
    }

    grille.at(grille.size() - 1).replace(0, to_string(minX).length() - 1, to_string(minX));
    grille.at(grille.size() - 1).insert(grille.at(0).length() - to_string(temps).length() - 1, to_string(temps));

    affiche(grille);

    return 0;
}