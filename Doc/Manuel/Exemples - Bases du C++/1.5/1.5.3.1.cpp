#include <iostream>
using namespace std;

class Rectangle
{
    float largeur;
    float hauteur;

public:
    // Il n'est pas nécessaire de remplir le constructeur
    // et le destructeur.
    Rectangle() {    }
    ~Rectangle() {    }

    float getLargeur()
    {
        return largeur;
    }
    
    float getHauteur()
    {
        return hauteur;
    }

    void setLargeur(float Largeur)
    {
        largeur = Largeur;
    }

    void setHauteur(float Hauteur)
    {
        hauteur = Hauteur;
    }
};

int main()
{
    Rectangle rect;
    rect.setLargeur(3.1);
    rect.setHauteur(4.5);

    cout << "L'aire du rectangle est : " << rect.getLargeur() * rect.getHauteur();
    
    return 0;
}