#include <iostream>
using namespace std;

#include "neurone.h"

int main()
{
    Neurone neurone;

    vector<float> entrees = {1, 2, 3, 4, 5};
    vector<float> poids = {0, -3, -2, 7, 1};

    neurone.setEntrees(entrees);
    neurone.setPoids(poids);

    cout << "Sortie du neurone : " << neurone.sortie();

    return 0;
}