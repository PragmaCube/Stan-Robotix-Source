#include <iostream>
using namespace std;

enum Castes
{
    Alpha,
    Beta,
    Gamma,
    Delta,
    Elpha
};

int main()
{
  
    Castes caste;
    
    float taille;
    cout << "Entrer la taille : " << endl;
    cin >> taille;

    if (taille >= 1.80)
    {
        caste = Alpha;
    }

    else if (taille >= 1.75)
    {
        caste = Beta;
    }

    else if (taille >= 1.70)
    {
        caste = Gamma;
    }

    else if (taille >= 1.65)
    {
        caste = Delta;
    }

    else
    {
        caste = Elpha;
    }

    switch (caste)
    {
    case Alpha:
        cout << "La caste est Alpha" ;
        break;

    case Beta:
        cout << "La caste est Beta" ;
        break;

    case Gamma:
        cout << "La caste est Gamma" ;
        break;

    case Delta:
        cout << "La caste est Delta" ;
        break;

    case Elpha:
        cout << "La caste est Elpha" ;
        break;

    default:
        break;
    }

    return 0;
}