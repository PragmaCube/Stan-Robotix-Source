#pragma once

#include "PacmanMonster.h"

/*

Personnalit� : suit le joueur par derri�re (la 2e case devant le joueur est sa cible)

*/

class Blinky :
	public PacmanMonster
{
public:
	Blinky();

	void move();

	void initializeBitmap(HDC ihdc);

};