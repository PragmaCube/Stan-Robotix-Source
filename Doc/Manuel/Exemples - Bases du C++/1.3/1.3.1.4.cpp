#include <iostream>
using namespace std;

int main()
{
    // On ne peut pas prédire à    l'avance le nombre de nombres premiers entre 2 et
    // 100, mais on peut fixer la limite à     49 (les nombres pairs ne sont pas
    // premiers).
    int nombrePremiers[49];
    int indice = 2;
    int x;
    int position = 0;
    
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
            nombrePremiers[position] = indice;
            position++;
        }
    
        indice++;
    }
    
    return 0;
}