#include <iostream>
#include <random>
using namespace std;

int main()
{
    int plusGrand = 0, plusPetit = 0, entre = 0;
    
    random_device systeme{};
    mt19937 generateur{systeme()};
    normal_distribution<float> distribution{0.0, 1.0};

    for (int i=0; i < 200; i++)
    {
        float nombre = distribution(generateur);
        
        if (nombre > 1)
        {
            plusGrand++;
        }

        else if (nombre < -1)
        {
            plusPetit++;
        }

        else
        {
            entre++;
        }
    }

    cout << "Il y a " << plusGrand << " nombre plus grand que 1" << endl << "Il y a " << plusPetit << " nombre plus petit que -1"<< endl << "Il y a " << entre << " nombre entre 1 et -1";
    
    return 0;
}