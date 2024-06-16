#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<float> nombres = {0.31, 8.12, -38.1, 642.02};

    for (int i = 0; i < nombres.size(); i++)
    {
        nombres.at(i) = nombres.at(i) * nombres.at(i);
    }

    cout << (nombres.at(0) + nombres.at((int)nombres.size() - 1)) / 2;
    
    return 0;
}