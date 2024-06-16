#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> carres;

    for (int i = 1; i <= 2 * n + 1; i++)
    {
        carres.push_back(i * i);
    }

    cout << "La taille est : " << carres.size() << "\nLe nombre au milieu est : " << carres.at(n + 1);
    
    return 0;
}