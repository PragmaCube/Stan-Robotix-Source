#include "Pad.h"

Pad::Pad()
{

}

Pad::Pad(int iId)
{
	if (iId == eRightPadId)
	{
		mX = 1;
		mY = 1;
	}
	else
	{
		mX = 2;
		mY = 2;
	}	
}

void Pad::setBall(Ball* iBall)
{
	mBallPtr = iBall;

}

int Pad::getX()
{
	return mX;
}

int Pad::getY()
{
	return mY;
}
