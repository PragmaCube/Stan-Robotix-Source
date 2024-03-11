// rectangle.h

class Rectangle
{
    float* largeur;
    float* hauteur;

public:
    Rectangle();
    ~Rectangle();

    float getLargeur();
    float getHauteur();

    void setLargeur(float Largeur);
    void setHauteur(float Hauteur);
};