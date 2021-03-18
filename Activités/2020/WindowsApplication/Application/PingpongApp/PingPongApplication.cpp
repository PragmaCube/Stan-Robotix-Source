#include "PingPongApplication.h"
#include "Ball.h"

#include <string>

PingPongApplication::PingPongApplication() :mLeftPad(Pad::eLeftPadId), mRightPad(Pad::eRightPadId)
{
	mCollisionEngine.setBall(&mBall);
	mCollisionEngine.setLeftPad(&mLeftPad);
	mCollisionEngine.setRightPad(&mRightPad);

	mLeftPad.setBall(&mBall);
	mRightPad.setBall(&mBall);
}

void PingPongApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	Pad wDummyPad(Pad::eLeftPadId);
	wDummyPad.setBall((Ball*) 0x12345678);

	std::wstring wTitle = L"Application de Pingpong";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);
}

void PingPongApplication::onChar(char iChar, short iDetail)
{

}

void PingPongApplication::onKeyDown(char iChar, short iDetail)
{

}

void PingPongApplication::onMouseMove(int iPosX, int iPosY)
{

}

void PingPongApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void PingPongApplication::onMouseLeftClick(int iPosX, int iPosY)
{

}

void PingPongApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void PingPongApplication::onTimer()
{

	IApplication::onTimer(); // Pour redessiner l'ecran
}
