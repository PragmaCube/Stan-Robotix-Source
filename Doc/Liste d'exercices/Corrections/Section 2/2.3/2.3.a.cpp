#include <iostream>
using namespace std;

// On cherche à déterminer si le nombre est premier
// (divisible seulement par lui-même et 1)
int main()
{
  int nombre;
  bool premier = true;
  
  cout << "Donner un nombre : ";
  cin >> nombre;

  // Il faut préciser le contenu de la boucle
  for (int i = 2 ; i < nombre ; i++)
  {
    if (nombre % i == 0)
    {
      premier = false;
      // On veut quitter la boucle dans ce cas
      break;
    }
  }

  // Cette partie est plutôt facile
  if (premier)
  {
    cout << "Le nombre est premier";
  }
  
  else
  {
    cout << "Le nombre n'est pas premier";
  }
  
  return 0;
}