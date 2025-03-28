// rectangle.cpp

#include "rectangle.h"

Rectangle::Rectangle()
{
    largeur = new float;
    hauteur = new float;
}

Rectangle::Rectangle(float Largeur, float Hauteur)
{
    largeur = new float;
    hauteur = new float;

    *largeur = Largeur;
    *hauteur = Hauteur;
}

Rectangle::~Rectangle() { }

float Rectangle::getLargeur()
{
    return *largeur;
}

float Rectangle::getHauteur()
{
    return *hauteur;
}

void Rectangle::setLargeur(float Largeur)
{
    *largeur = Largeur;
}

void Rectangle::setHauteur(float Hauteur)
{
    *hauteur = Hauteur;
}