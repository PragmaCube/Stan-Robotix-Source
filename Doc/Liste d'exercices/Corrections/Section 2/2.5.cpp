#include <iostream>
using namespace std;

int main()
{
  int x;
  
  cout << "Entrez un nombre : ";
  cin >> x;
  
  if (x % 2 == 0)
  {
    cout << "Ce nombre est pair";
  }
  
  else
  {
    cout << "Ce nombre n'est pas pair";
  }
  
  return 0;
}