#pragma once

#include "PacmanMonster.h"

/*

Personnalit� :
	� plus de 8 cases de Pacman : suit le joueur par derri�re
	� moins de 8 cases de Pacman : tourne en rond

*/

class Clyde :
	public PacmanMonster
{
public:
	Clyde();

	void move();
};