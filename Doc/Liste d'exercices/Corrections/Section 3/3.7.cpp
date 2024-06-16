#include <iostream>
#include <vector>
using namespace std;

enum Vitesse
{
    lente,
    moyenne,
    rapide
};

int main()
{
    int typeVitesse;
    bool continuerBoucle = true;
    vector<Vitesse> vitesses;

    while (continuerBoucle)
    {
        cout << "Entrez la vitesse : \n >>> ";
        cin >> typeVitesse;
        
        switch(typeVitesse)
        {
            case 1:
                vitesses.push_back(Vitesse::lente);
                break;
    
            case 2:
                vitesses.push_back(Vitesse::moyenne);
                break;
    
            case 3:
                vitesses.push_back(Vitesse::rapide);
                break;
    
            default:
                continuerBoucle = false;
                break;
        }
    }
    
    return 0;
}