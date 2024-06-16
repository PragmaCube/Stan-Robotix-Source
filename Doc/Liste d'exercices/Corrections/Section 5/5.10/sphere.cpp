#include "sphere.h"

Sphere::Sphere() { }

Sphere::~Sphere() { }

float Sphere::getRayon()
{
    return rayon;
}

void Sphere::setRayon(float Rayon)
{
    rayon = Rayon;
}

float Sphere::getAire()
{
    return 4 * pi * rayon * rayon;
}

float Sphere::getVolume()
{
    return 4 / 3 * pi * rayon * rayon * rayon;
}