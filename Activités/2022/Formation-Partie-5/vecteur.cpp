#include "vecteur.h"

#include <cmath>

Vecteur::Vecteur() { }

Vecteur::~Vecteur() { }

float Vecteur::getX()
{
  return mX;
}

float Vecteur::getY()
{
  return mY;
}

float Vecteur::getNorme()
{
  return std::sqrt(mX * mX + mY * mY);
}

void Vecteur::setX(float iX)
{
  mX = iX;
}

void Vecteur::setY(float iY)
{
  mY = iY;
}

float produitScalaire(Vecteur iVect1, Vecteur iVect2)
{
  return iVect1.getX() * iVect2.getX() + iVect1.getY() * iVect2.getY();
}