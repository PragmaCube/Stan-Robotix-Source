#pragma once

#include "PacmanMonster.h"

/*

Personnalité : suit le joueur par derrière (la 2e case devant le joueur est sa cible)

*/

class Blinky :
	public PacmanMonster
{
public:
	Blinky();

	void move();

	void initializeBitmap(HDC ihdc);

};