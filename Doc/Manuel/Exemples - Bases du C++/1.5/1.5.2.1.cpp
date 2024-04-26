#include <iostream>
using namespace std;

class Rectangle
{
    float largeur;
    float hauteur;

public:
    Rectangle()
    {
        cout << "Objet créé !" << endl;
    }

    ~Rectangle()
    {
        cout << "Objet détruit !" << endl;
    }
};

int main()
{
    Rectangle rect;
    
    return 0;
}