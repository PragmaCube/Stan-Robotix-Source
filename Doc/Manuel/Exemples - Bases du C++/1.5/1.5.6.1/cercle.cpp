// cercle.cpp

#include "cercle.h"

Cercle::Cercle() { }

Cercle::Cercle(float Rayon)
{
    rayon = Rayon;
}

Cercle::~Cercle() { }

float Cercle::getRayon()
{
    return rayon;
}

void Cercle::setRayon(float Rayon)
{
    rayon = Rayon;
}