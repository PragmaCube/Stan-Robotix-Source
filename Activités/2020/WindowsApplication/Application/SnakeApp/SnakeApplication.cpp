#include "SnakeApplication.h"
#include "../../Framework/IApplication.h"
#include <stdlib.h>     
#include <time.h>       
#include <math.h>
#include <string>


		

SnakeApplication::SnakeApplication()
{
	mRond.setApplication(this);
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

	if (ProchaineDir == 1)
	{
		mRond.Up();
	}
	else if (ProchaineDir == 2)
	{
		mRond.Down();
	}
	else 	if (ProchaineDir == 3)
	{
		mRond.Right();
	}
	else if (ProchaineDir == 4)
	{
		mRond.Left();
	}


}
void SnakeApplication::onChar(char iChar, short iDetail)
{

	switch (iChar)
	{
	case ('W'):
	case ('w'):
	{
		ProchaineDir = 1;
		break;
	}
	case ('S'):
	case ('s'):
	{
		ProchaineDir = 2;
		break;

	}
	case ('D'):
	case ('d'):
	{
		ProchaineDir = 3 ;
		break;

	}
	case ('A'):
	case ('a'):
	{
		ProchaineDir = 4;
		break;

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

