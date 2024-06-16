#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nombrePremiers;
    int indice = 2;
    int x;
    
    bool pasPremier;
  
    while (indice <= 100)
    {
        x = 2;
        pasPremier = false;

        while (x < indice)
        {
            if (indice % x == 0)
            {
                pasPremier = true;
                break;
            }
        
            x++;
        }
        
        if (!pasPremier)
        {
            nombrePremiers.push_back(indice);
        }
    
        indice++;
    }
    
    return 0;
}