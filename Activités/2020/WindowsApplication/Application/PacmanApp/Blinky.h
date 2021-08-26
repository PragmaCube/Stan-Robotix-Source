#pragma once

#include "PacmanMonster.h"

/*

Personnalité : suit un parcours définis

*/

class Blinky :
	public PacmanMonster
{
	bool mInBox = true;

	char mExitPath[16] = { 'u', 'u', 'u', 'l', 'u', 'u', 'l', 'l', 'l', 'u', 'u', 'u', 'l', 'l', 'l' };

	char mLoopPath[156] = { 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd', 'd',
		'd', 'd', 'd', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'u',
		'u', 'u', 'l', 'l', 'l', 'l', 'l', 'l', 'd', 'd', 'd', 'l', 'l', 'l', 'u', 'u', 'u', 'l', 'l',
		'l', 'u', 'u', 'u', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'u', 'u', 'u', 'u', 'u', 'u',
		'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'd', 'd', 'd', 'l', 'l', 'l', 'u', 'u', 'u', 'u',
		'u', 'u', 'u', 'u', 'u', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'd', 'd',
		'd', 'l', 'l', 'l', 'd', 'd', 'd', 'r', 'r', 'r', 'd', 'd', 'd', 'd', 'd', 'd', 'l', 'l', 'l',
		'l', 'l', 'l', 'l', 'l', 'l', 'u', 'u', 'u', 'u', 'u', 'u', 'r', 'r', 'r', 'u', 'u', 'u', 'l',
		'l', 'l', 'u', 'u', 'u', 'l', 'l', 'l', };

	int mExitPos = 0, mLoopPos = 0;

public:
	Blinky();

	void move();
	void path();
	void reset();

	void initializeBitmap(HDC ihdc);
};