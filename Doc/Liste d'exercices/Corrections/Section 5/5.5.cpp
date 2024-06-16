#include <iostream>
using namespace std;

class Cercle
{
    float rayon;
    const float pi = 3.1415;

public:
    Cercle();
    ~Cercle();

    float getRayon();
    float getCircomference();
    float getAire();

    void setRayon(float Rayon);
};

Cercle::Cercle() { }

Cercle::~Cercle() { }

float Cercle::getRayon()
{ 
    return rayon;
}

float Cercle::getCircomference()
{ 
    return 2 * rayon * pi;
}

float Cercle::getAire()
{ 
    return rayon * rayon * pi;
}

void Cercle::setRayon(float Rayon)
{ 
    rayon = Rayon;
}

int main()
{
    Cercle cercle;
    cercle.setRayon(3.1415);

    cout << "Le cercle de rayon " << cercle.getRayon() << " a un périmètre de " << cercle.getCircomference() << " et une aire de " << cercle.getAire();

    return 0;
}