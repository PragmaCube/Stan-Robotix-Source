#include "sonic.h"

Sonic::Sonic() { }

Sonic::~Sonic() { }

float Sonic::getVitesse()
{
    return vitesse;
}

float Sonic::distanceParcourue(float secondes)
{
    return vitesse * secondes;
}