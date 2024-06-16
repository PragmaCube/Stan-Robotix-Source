#include <iostream>
using namespace std;

enum Vitesse
{
    lente,
    moyenne,
    rapide
};

int main()
{
  
    Vitesse vitesse;
  
    int nb;
    cout << "Entrer un nombre entier : " << endl;
    cin >> nb;

    if (nb > 0)
    {
        vitesse = rapide;
    }

    else if (nb == 0)
    {
        vitesse = moyenne;
    }

    else
    {
        vitesse = lente;
    }

    switch (vitesse)
    {
    case lente:
        cout << "La vitesse est lente" ;
        break;
    case moyenne:
        cout << "La vitesse est moyenne" ;
        break;

    case rapide:
        cout << "La vitesse est rapide" ;
        break;

    default:
        break;
    }

    return 0;
}