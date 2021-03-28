#include "SnakeApplication.h"
#include "../../Framework/IApplication.h"
#include <stdlib.h>     
#include <time.h>       
#include <math.h>
#include <string>


		

SnakeApplication::SnakeApplication()
{

}

void SnakeApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application d Snake";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);

	mRond.updateDrawingArea(iPaintArea);
	mRond.paint(ihdc);


}
void SnakeApplication::onChar(char iChar, short iDetail)
{

	switch (iChar)
	{
	case ('W'):
	case ('w'):
	{
		mRond.Up();
	}
	case ('S'):
	case ('s'):
	{
		mRond.Down();// ils se sont inspiré de mon code pour créer des directions
	}
	case ('D'):
	case ('d'):
	{
		mRond.Right();
	}
	case ('A'):
	case ('a'):
	{
		mRond.Left();
	}

	}

}


void SnakeApplication::onKeyDown(char iChar, short iDetail)
{

}


void SnakeApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void SnakeApplication::onMouseLeftClick(int iPosX, int iPosY)
{

}

void SnakeApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

