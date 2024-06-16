#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> diviseurs;

    cout << "Liste des diviseurs de " << 1922310 << " :\n";

    for (int i = 1; i <= 1922310; i++)
    {
        if (1922310 % i == 0)
        {
            diviseurs.push_back(i);
            
            cout << ">>> " << i << "\n";
        }
    }

    return 0;
}