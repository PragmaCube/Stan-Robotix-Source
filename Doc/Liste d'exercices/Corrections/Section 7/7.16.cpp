#include <iostream>
using namespace std;

int main()
{
    float probabilite = 0.3;
    float gain = 30;
    float interets = 0;
    float precision = 0.1;

    // La question étant mal construite,
    // il suffit de prendre i > probabilite * gain.
    // Essayons tout de même autrement,
    // dans le cas où l'on ne connait que l'ordre :

    while (interets <= probabilite * gain)
    {
        interets += precision;
    }

    cout << "La somme à verser est " << interets;

    return 0;
}