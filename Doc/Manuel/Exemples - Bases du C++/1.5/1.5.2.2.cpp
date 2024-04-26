#include <iostream>
using namespace std;

class Rectangle
{
    float largeur;

public:
    Rectangle()
    {
        cout << "Objet créé !" << endl;
    }

    ~Rectangle()
    {
        cout << "Objet détruit !" << endl;
    }

    float hauteur;
};

int main()
{
    Rectangle rect;
    rect.hauteur = 3.1;
    cout << rect.hauteur << endl;
    
    return 0;
}