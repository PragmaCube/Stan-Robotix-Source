#include <iostream>
#include <vector>
using namespace std;

vector<int> premiersCarres()
{
    vector<int> carres;

    for (int i = 0; i < 10; i++)
    {
        carres.push_back(i * i);
    }

    return carres;
}

int main()
{
    vector<int> carres = premiersCarres();
    
    for (int i = 0; i < 10; i++)
    {
        cout << "Le carré #" << i << " est : " << carres[i] << endl;
    }

    return 0;
}