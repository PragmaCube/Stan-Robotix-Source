#include "CollisionEngine.h"

CollisionEngine::CollisionEngine() : mBallPtr(nullptr), mLeftPadPtr(nullptr), mRightPadPtr(nullptr)
{

}

void CollisionEngine::setBall(Ball* iBall)
{
	mBallPtr = iBall;

}

void CollisionEngine::setLeftPad(Pad* iPad)
{
	mLeftPadPtr = iPad;
}

void CollisionEngine::setRightPad(Pad* iPad)
{
	mRightPadPtr = iPad;
}

void CollisionEngine::execute()
{
	mBallPtr->getX();
	mLeftPadPtr->getY();
	mRightPadPtr->getY();
}