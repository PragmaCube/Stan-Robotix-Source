#include <iostream>
using namespace std;

// On cherche à déterminer le nombre entier n tel que n^3 = 4n^2
int main()
{
  int n = 1;

  // n * n * n pour le cube de n et n * n pour le carré
  // Tant que les valeurs sont différentes, on continue
  while (n * n * n != 4 * n * n)
  {
    n++;
  }

  cout << n;
  
  return 0;
}