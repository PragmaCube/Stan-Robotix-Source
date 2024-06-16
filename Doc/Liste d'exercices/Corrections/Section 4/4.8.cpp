#include <iostream>
#include <random>
using namespace std;

float aleatoireNormale(float esperance, float ecartType)
{
    random_device systeme{};
    mt19937 generateur{systeme()};
    normal_distribution<float> distribution{esperance, ecartType};
    
    return distribution(generateur);
}

int main()
{
    float esperance, ecartType;

    cout << "Veuillez rentrer l'espérance et l'écart-type :\n>>> ";
    cin >> esperance;
    cout << ">>> ";
    cin >> ecartType;

    return 0;
}