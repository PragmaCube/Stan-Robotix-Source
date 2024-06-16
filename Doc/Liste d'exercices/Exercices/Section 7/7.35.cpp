#include <iostream>
#include <vector>

#include <cmath>
#include <random>
#include <ctime>
using namespace std;

vector<float> mouvementBrownienGeometrique(float mu, float sigma, float y0, float intervalle, float tempsMax)
{
    int iterations = int(tempsMax / intervalle);

    mt19937 generateur;
    generateur.seed(time(0));
    normal_distribution<float> gauss(0, sqrt(intervalle));

    vector<float> valeurs;
    valeurs.push_back(std::exp((mu - sigma * sigma / 2) * intervalle + sigma * gauss(generateur)));

    for (int i = 0; i < iterations - 1; i++)
    {
        valeurs.push_back(valeurs.at(i) * exp((mu - sigma * sigma / 2) * intervalle + sigma * gauss(generateur)));
    }

    for (int i = 0; i < iterations; i++)
    {
        valeurs.at(i) *= y0;
    }

    return valeurs;
}

int main()
{
    vector<float> valeurs = mouvementBrownienGeometrique(0.12, 0.41, 871.2, 0.000403, 0.05);

    for (int i = 0; i < valeurs.size(); i++)
    {
        cout << valeurs.at(i) << endl;
    }

    return 0;
}