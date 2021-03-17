#include "SnakeApplication.h"
#include "../../Framework/IApplication.h"
#include <stdlib.h>     
#include <time.h>       
#include <math.h>
#include <string>


		

void SnakeApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Snake";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);
		mDemoAppBall[i].updateDrawingArea(iPaintArea);
		mDemoAppBall[i].paint(ihdc);



}
void SnakeApplication::onChar(char iChar, short iDetail)
{
		while (true)
		{
			switch (iChar)
			{
			case 'a':
			case 'A':
				Serpent::ProchaineDirection gauche =  gauche ;
				break;
			case 's':
			case 'S':
				Serpent::ProchaineDirection bas = bas ;
				break;
			case 'd':
			case 'D':
				Serpent::ProchaineDirection droite = droite ;
				break;	
			case 'w':
			case 'W':
				Serpent::ProchaineDirection haut = haut ;
				break;
			};
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

