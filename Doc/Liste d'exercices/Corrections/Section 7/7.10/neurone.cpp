#include "neurone.h"

Neurone::Neurone() { }

Neurone::~Neurone() { }

vector<float> Neurone::getEntrees()
{
    return entrees;
}

vector<float> Neurone::getPoids()
{
    return poids;
}

void Neurone::setEntrees(vector<float> Entrees)
{
    entrees = Entrees;
}

void Neurone::setPoids(vector<float> Poids)
{
    poids = Poids;
}

float Neurone::sortie()
{
    if (entrees.size() != poids.size())
    {
        return 0;
    }

    float total = 0;

    for (int i = 0; i < entrees.size(); i++)
    {
        total += entrees.at(i) * poids.at(i);
    }

    return total;
}