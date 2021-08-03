#pragma once

#include "PacmanMonster.h"

/*

Personnalité : on double le vecteur Blinky-Cible et on obtient la cible d'Inky

*/

class Inky :
	public PacmanMonster
{
	unsigned int mTargetX1 = 1, mTargetY1 = 1, mTargetX2 = 26, mTargetY2 = 24;
	bool mTarget1Done = false, mTarget2Done = false, mInBox = true;

	char mExitPath[16] = { 'u', 'u', 'u', 'l', 'u', 'u', 'l', 'l', 'l', 'u', 'u', 'u', 'l', 'l', 'l' };

	char mLoopPath[140] = { 'l', 'l', 'l', 'l', 'l', 'u', 'u', 'u', 'u', 'r', 'r', 'r', 'r', 'r', 'd',
		'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd',
		'd', 'd', 'd', 'd', 'l', 'l', 'l', 'l', 'l', 'd', 'd', 'd', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r',
		'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'u', 'u', 'u',
		'l', 'l', 'u', 'u', 'u', 'r', 'r', 'u', 'u', 'u', 'l', 'l', 'l', 'l', 'l', 'u', 'u', 'u', 'u', 'u',
		'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'u', 'r', 'r', 'r', 'r', 'r',
		'd', 'd', 'd', 'd', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l',
		'l', 'l', 'l', 'l' };

	int mExitPos = 0, mLoopPos = 0;
public:
	Inky();

	char bestRightLeft(char iLastChoice, unsigned int iOtherY);
	char bestUpDown(char iLastChoice, unsigned int iOtherX);
	char nextMoveWithTarget();
	void path();
	void move();
};