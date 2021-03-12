#pragma once
#include "Ball.h"

class Pad
{
public:
	enum { eRightPadId, eLeftPadId };

public:
	Pad(int iId);

	void setBall(Ball* iball);

	int getX();
	int getY();

private:
	Pad();

	int mX, mY;

	Ball* mBallPtr;
};

