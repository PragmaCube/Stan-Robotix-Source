#include "CollisionEngine.h"

#include <string>
#include <locale>
#include <codecvt>

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
	if (nullptr != mLeftPadPtr && nullptr != mRightPadPtr && nullptr != mBallPtr)
	{
		if (!mInit)
		{
			mLeftPadPtr->initialiser(iWindowRect);
			mRightPadPtr->initialiser(iWindowRect);
			mInit = true;
		}

		if (mBallPtr->getX() <= 250                                      && 
			mBallPtr->getX() >= 250 + mBallPtr->getSpeedX()              && // + getSpeedX() parce que la vitesse est négative
			mLeftPadPtr->getY() - mPadHeight / 2 <= mBallPtr->getY()     &&
			mBallPtr->getY() <= mLeftPadPtr->getY() + mPadHeight / 2)
		{
			mBallPtr->flipXSpeed();
			//PlaySound(TEXT("Ping_Pong.wav"), NULL, SND_ASYNC);
			mBallPtr->increaseSpeed();
			mNbEchanges++;
		}

		if (mBallPtr->getX() >= 880 && mBallPtr->getX() <= 880 + mBallPtr->getSpeedX() && mRightPadPtr->getY() - mPadHeight / 2 <= mBallPtr->getY() &&
			mBallPtr->getY() <= mRightPadPtr->getY() + mPadHeight / 2)
		{
			mBallPtr->flipXSpeed();
			mBallPtr->increaseSpeed();
			mNbEchanges++;
		}

		if (mBallPtr->getX() < iWindowRect.left)
		{
			Sleep(1000);
			mNbEchanges = 0;
			mBallPtr->restart(iWindowRect);
		}

		if (mBallPtr->getX() > iWindowRect.right)
		{
			Sleep(1000);
			mNbEchanges = 0;
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
}

void CollisionEngine::afficherEchanges(HDC ihdc)
{
	std::string wMessage = "Il y a eu " + std::to_string(mNbEchanges) + " echange(s)";
	std::wstring wChar = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(wMessage);
	RECT wTextArea = { 500, 20, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		((int)DT_LEFT | DT_BOTTOM));
}