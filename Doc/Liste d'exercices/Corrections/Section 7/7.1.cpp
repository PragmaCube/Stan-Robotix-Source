#include <iostream>
#include <random>
using namespace std;

float monteCarlo(int nbr)
{
  int compteur = 0;
  float x, y;
  
  random_device random;
  mt19937 generateur(random());
  uniform_real_distribution<> distribution(0, 1);

  for(int i = 0; i < nbr; i++)
    {
      x = distribution(generateur);
      y = distribution(generateur);
      
      if(x * x + y * y <= float(1))
      {
        compteur++;
      }
    }

  return float(4 * compteur) / nbr;
}

int main()
{
    cout << "Approximation Monte-Carlo de pi avec 1000 itérations : " << monteCarlo(1000);

    return 0;
}