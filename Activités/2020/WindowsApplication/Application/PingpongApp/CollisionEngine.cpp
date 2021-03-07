#include "CollisionEngine.h"

CollisionEngine::CollisionEngine() : mBallPtr(nullptr), mLeftPadPtr(nullptr), mRightPadPtr(nullptr)
{

}

void CollisionEngine::setBall(PingPongBall* iBall)
{
	mBallPtr = iBall;

}

void CollisionEngine::setLeftPad(PingPongPad* iPad)
{
	mLeftPadPtr = iPad;
}

void CollisionEngine::setRightPad(PingPongPad* iPad)
{
	mRightPadPtr = iPad;
}



void CollisionEngine::rebound(RECT iWindowRect)
{
	if (!init)
	{
		mLeftPadPtr->initialiser(iWindowRect);
		init = true;
	}
	if (mBallPtr->getX() <= 250 && mLeftPadPtr->getY() - mPadHeight/2 <= mRightPadPtr->getY() && mRightPadPtr->getY() <= mLeftPadPtr->getY() + mPadHeight/2)
	{
		mBallPtr->flipXSpeed();
		mBallPtr->increaseSpeed();
	}
	
	else if (mBallPtr->getX() >= 880)
	{
		mBallPtr->flipXSpeed();
	}

	if (mBallPtr->getX() < iWindowRect.left)
	{
		Sleep(1000);
		mBallPtr->restart(iWindowRect);
	}

	if (mBallPtr->getY() > iWindowRect.bottom)
	{
		mBallPtr->flipYSpeed();
	}
	else if (mBallPtr->getY() < iWindowRect.top)
	{
		mBallPtr->flipYSpeed();
	}
}
