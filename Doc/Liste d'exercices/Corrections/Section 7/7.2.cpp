#include <vector>
#include <iostream>
using namespace std;

class Simulateur
{
    const float g = 9.8067;
    const float hauteurInitiale = 553.33;
    
    vector<float> positions;

public:
    Simulateur();
    ~Simulateur();

    float getG();
    float getHauteurInitiale();

    vector<float> getPositions();

    void setPositions(vector<float>);

    void simulation(float);      
};

Simulateur::Simulateur() { }

Simulateur::~Simulateur() { }

float Simulateur::getG()
{
    return g;
}

float Simulateur::getHauteurInitiale()
{
    return hauteurInitiale;
}

vector<float> Simulateur::getPositions()
{
    return positions;
}

void Simulateur::setPositions(vector<float> Positions)
{
    positions = Positions;
}

void Simulateur::simulation(float deltaT)
{
    float position = hauteurInitiale;
    float duree = 0;
    positions.push_back(position);

    while (position > 0)
    {
        position -= g * deltaT * deltaT / 2;
        duree += deltaT;
        positions.push_back(position);
    }

    cout << duree;
}