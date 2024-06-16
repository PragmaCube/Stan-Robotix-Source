// entite.cpp

#include "entite.h"

Entite::Entite() { }

Entite::~Entite() { }

float Entite::getX()
{
    return x;
}

float Entite::getY()
{
    return y;
}

void Entite::setX(float X)
{
    x = X;
}

void Entite::setY(float Y)
{
    y = Y;
}