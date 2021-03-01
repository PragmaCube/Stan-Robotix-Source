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

void CollisionEngine::execute()
{
	mBallPtr->getX();
	mLeftPadPtr->getY();
	mRightPadPtr->getY();
}

void CollisionEngine::rebound(RECT iWindowRect)
{
	if (mBallPtr->getX() <= 250 && mLeftPadPtr->getY() - 100 <= mRightPadPtr->getY() && mRightPadPtr->getY() <= mLeftPadPtr->getY() + 100)
	{
		mBallPtr->flipXSpeed();
	}
	
	else if (mBallPtr->getX() >= 880)
	{
		mBallPtr->flipXSpeed();
	}

	if (mBallPtr->getX() > iWindowRect.right)
	{
		mBallPtr->flipXSpeed();
	}
	else if (mBallPtr->getX() < iWindowRect.left)
	{
		mBallPtr->flipXSpeed();
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

