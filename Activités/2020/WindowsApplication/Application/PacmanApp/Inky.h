#pragma once

#include "PacmanMonster.h"

/*

Personnalit� : on double le vecteur Blinky-Cible et on obtient la cible d'Inky

*/

class Inky :
	public PacmanMonster
{
public:
	Inky();

	void move();
};