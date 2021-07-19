#pragma once

#include "PacmanMonster.h"

/*

Personnalité :
	À plus de 8 cases de Pacman : suit le joueur par derrière
	À moins de 8 cases de Pacman : tourne en rond

*/

class Clyde :
	public PacmanMonster
{
public:
	Clyde();

	void move();
};