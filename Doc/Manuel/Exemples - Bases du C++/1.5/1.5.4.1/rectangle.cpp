// rectangle.cpp

#include "rectangle.h"

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