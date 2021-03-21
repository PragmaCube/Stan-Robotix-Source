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
	if (!init)
	{
		mLeftPadPtr->initialiser(iWindowRect);
		init = true;
	}
	if (mBallPtr->getX() <= 250 && mBallPtr->getX() >= 250 + mBallPtr->getSpeedX() && mLeftPadPtr->getY() - mPadHeight/2 <= mRightPadPtr->getY() && mRightPadPtr->getY() <= mLeftPadPtr->getY() + mPadHeight/2)
	{                                                   // + getSpeedX() parce que la vitesse est négative
		mBallPtr->flipXSpeed();
		//PlaySound(TEXT("Ping_Pong.wav"), NULL, SND_ASYNC);
		mBallPtr->increaseSpeed();
		nbEchanges++;
	
	}
	
	else if (mBallPtr->getX() >= 880)
	{
		mBallPtr->flipXSpeed();
	}

	if (mBallPtr->getX() < iWindowRect.left)
	{
		Sleep(1000);
		nbEchanges = 0;
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

int CollisionEngine::echanges()
{
	return nbEchanges;
}

void CollisionEngine::afficherEchanges(HDC ihdc)
{
	std::string truc = "Il y a eu " + std::to_string(nbEchanges) + " echange(s)";
	std::wstring wChar = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(truc);
	RECT wTextArea = { 500, 20, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		((int)DT_LEFT | DT_BOTTOM));
}