#include <random>
#include <ctime>
#include <iostream>
using namespace std;

void machineAEtats()
{
    random_device systeme{};
    mt19937 generateur{systeme()};
    normal_distribution<float> distribution{3.0, 2.0};

    float mesure;

    for (int iteration = 0; iteration < 100; iteration++)
    {
        mesure = distribution(generateur);

        if (mesure < 2)
        {
            cout << "Iteration #" << iteration + 1 << " : scanner.\n";
        }

        else if (mesure < 5)
        {
            cout << "Iteration #" << iteration + 1 << " : actionner.\n";
        }

        else if (mesure < 9)
        {
            cout << "Iteration #" << iteration + 1 << " : bouger.\n";
        }

        else
        {
            cout << "Arrêt prématuré.";

            break;
        }
    }
}

int main()
{
    machineAEtats();

    return 0;
}