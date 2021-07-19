#pragma once

#include "PacmanMonster.h"

/*

Personnalité : essaie de passer devant le joueur (la 4e case devant la direction du joueur est sa cible)

*/

class Pinky :
	public PacmanMonster
{
public:
	Pinky();

	void move();
};