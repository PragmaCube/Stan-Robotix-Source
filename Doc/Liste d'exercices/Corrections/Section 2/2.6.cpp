#include <iostream>
using namespace std;

int main()
{
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
            cout << indice << endl;  
        }
    
        indice++;
    }
    
    return 0;
}