#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void sir(int population, int infectes, double tauxTransmission, double tauxGuerison)
{
    int sains = population - infectes;
    int retablis = 0;

    int nouveauxInfectes;

    int jour = 1;

    while (infectes > 0)
    {
        nouveauxInfectes = 0;

        for (int i = 0; i < sains; i++)
        {
            if (((double) rand() / (RAND_MAX)) < tauxTransmission * double(9.437 * infectes) / double(population))
            {
                nouveauxInfectes++;
            }
        }

        sains -= nouveauxInfectes;

        for (int i = 0; i < infectes; i++)
        {
            if (((double) rand() / (RAND_MAX)) < tauxGuerison)
            {
                infectes--;
                retablis++;
            }
        }

        infectes += nouveauxInfectes;

        cout << "Jour " << jour << " : S = " << sains << " / I = " << infectes << " / R = " << retablis << endl;

        jour++;
    }
}

int main()
{
    srand(time(0));

    sir(100000, 1, 0.25, 0.1);

    return 0;
}