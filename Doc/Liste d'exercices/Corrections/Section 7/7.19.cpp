#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int iterations = 30;
    int somme = 0;
    int position;
    int nbrAleatoire;

    int nbrSimulation = 10000;

    for (int i = 0; i < nbrSimulation; i++)
    {
        position = 0;

        for (int j = 0; j < iterations; j++)
        {
            nbrAleatoire = rand() % 2;

            if (nbrAleatoire == 1)
            {
                position++;
            }

            else
            {
                position--;
            }
        }

        somme += position;
    }

    cout << "Distance maximale en moyenne : " << float(somme) / float(nbrSimulation);
    
    return 0;
}