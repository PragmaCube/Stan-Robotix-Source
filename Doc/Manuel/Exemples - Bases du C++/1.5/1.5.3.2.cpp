class Rectangle
{
    float largeur;
    float hauteur;

public:
    Rectangle();
    ~Rectangle();

    float getLargeur();
    float getHauteur();

    void setLargeur(float Largeur);
    void setHauteur(float Hauteur);
};

Rectangle::Rectangle() { }

Rectangle::~Rectangle() { }

float Rectangle::getLargeur()
{
    return largeur;
}

float Rectangle::getHauteur()
{
    return hauteur;
}

void Rectangle::setLargeur(float Largeur)
{
    largeur = Largeur;
}

void Rectangle::setHauteur(float Hauteur)
{
    hauteur = Hauteur;
}