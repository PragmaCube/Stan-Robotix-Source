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