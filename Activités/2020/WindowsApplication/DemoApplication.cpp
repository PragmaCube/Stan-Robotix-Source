#include "DemoApplication.h"

#include <stdlib.h>     
#include <time.h>   

DemoApplication::DemoApplication()
{
	srand(time(NULL));

	// Le decompte va de 0 a 7 sur une base décimale, ou bien de 000 à 111 sur une base binaire.
	
	for (int i = 0; i < 8; i++)
	{
		int wRed   = (i & 0x1) ? 255 : 0; // Le premier bit détermine si la composante rouge.
		int wGreen = (i & 0x2) ? 255 : 0; // Le deuxieme bit détermine si la composante verte.
		int wBlue  = (i & 0x4) ? 255 : 0; // Le troisieme bit détermine si la composante bleue.
		mDemoAppBall[i].setColor(RGB(wRed, wGreen, wBlue));
	}

	mCircleRadius = 20;

	mNbActiveBall = 3;
}

void DemoApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	for (int i = 0; i < mNbActiveBall; i++)
	{
		mDemoAppBall[i].updateDrawingArea(iPaintArea);
		mDemoAppBall[i].paint(ihdc);
	}
}

void DemoApplication::onChar(char iChar, short iDetail)
{
	if (iChar == '-')
	{
		if (mNbActiveBall > 2)
		{
			mNbActiveBall--;
		}
	}
	else if(iChar == '+')
	{
		if (mNbActiveBall < 8)
		{
			mNbActiveBall++;
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			switch (iChar)
			{
			case 'a':
			case 'A':
				mDemoAppBall[i].decreaseRadius();
				break;
			case 's':
			case 'S':
				mDemoAppBall[i] .increaseRadius();
				break;
			case 'q':
			case 'Q':
				mDemoAppBall[i].decreaseSpeed();
				break;
			case 'w':
			case 'W':
				mDemoAppBall[i].increaseSpeed();
				break;
			};
		}
	}
}

void DemoApplication::onKeyDown(char iChar, short iDetail)
{

}

void DemoApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void DemoApplication::onMouseLeftClick(int iPosX, int iPosY)
{

}

void DemoApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void DemoApplication::onTimer()
{
	for (int i = 0; i < 8; i++)
	{
		mDemoAppBall[i].applyTime();
	}
	IApplication::onTimer();
}