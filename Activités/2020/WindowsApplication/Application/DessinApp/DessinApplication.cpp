	#include "DessinApplication.h"

#include <string>

DessinApplication::DessinApplication() : mPosX(0), mPosY(0)
{
	mLastClickType = eClickNone;

	for (int i = 0; i < 8; i++)
	{
		int wRed = (i & 0x1) ? 255 : 0; // Le premier bit détermine si la composante rouge.
		int wGreen = (i & 0x2) ? 255 : 0; // Le deuxieme bit détermine si la composante verte.
		int wBlue = (i & 0x4) ? 255 : 0; // Le troisieme bit détermine si la composante bleue.
		mBrush[i] = CreateSolidBrush(RGB(wRed, wGreen, wBlue));
	}

	mFreeWritingPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

	mPointList.empty();
}

void DessinApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de dessin";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);

	::DrawText(
		ihdc,
		mTextToDraw.c_str(),
		mTextToDraw.length(),
		&iPaintArea,
		DT_LEFT | DT_BOTTOM);

	switch (mLastClickType)
	{
	case eLeftDoubleClick:
		drawHorizontalLines(ihdc, iPaintArea);
		break;
	case eLeftClick:
		drawConcentricCircle(ihdc, iPaintArea);
		break;
	case eRightClick:
		drawStairs(ihdc, iPaintArea);
		break;
	};

	drawFreeWriting(ihdc, iPaintArea);
}

void DessinApplication::drawHorizontalLines(HDC ihdc, RECT& iPaintArea)
{
	for (int i = mPosY-50;
		i < mPosY + 50;
		i += 10)
	{
		::MoveToEx(
			ihdc,
			mPosX-50,
			i,
			nullptr);
		::LineTo(
			ihdc,
			mPosX+50,
			i);
	}
}

void DessinApplication::drawConcentricCircle(HDC ihdc, RECT& iPaintArea)
{
	int wRadius = 100;
	while ( wRadius > 20)
	{
		::Ellipse(ihdc,
			(int)(mPosX)-wRadius,
			(int)(mPosY)-wRadius,
			(int)(mPosX)+wRadius,
			(int)(mPosY)+wRadius);

		wRadius -= 10;
    }

	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush[0]);

	for (int i = 0; i < 8; i++)
	{
		::SelectObject(ihdc, mBrush[i]);
		::FloodFill(ihdc, mPosX + 25 + i * 10, mPosY, RGB(0,0,0));
	}
	::SelectObject(ihdc, wOldBrush);
}

void DessinApplication::drawFreeWriting(HDC ihdc, RECT& iPaintArea)
{
	if (!mPointList.empty())
	{
		bool wFirstPoint = false;
		HGDIOBJ wOldPen = ::SelectObject(ihdc, mFreeWritingPen);

		for (Point wPt : mPointList)
		{
			if (!wFirstPoint)
			{
				::MoveToEx(
					ihdc,
					wPt.getX(),
					wPt.getY(),
					nullptr);

				wFirstPoint = true;
			}
			else
			{
				::LineTo(
					ihdc,
					wPt.getX(),
					wPt.getY());
			}
		}

		::SelectObject(ihdc, wOldPen);
	}
}

void DessinApplication::drawStairs(HDC ihdc, RECT& iPaintArea)
{

}

void DessinApplication::onChar(char iChar, short iDetail)
{
	mTextToDraw.push_back(iChar);
}

void DessinApplication::onKeyDown(char iChar, short iDetail)
{
	if (iChar == 'a' || iChar == 'A')
	{
		int wRep = MessageBox(0, L"Veuillez effacer tout", L"Message", MB_YESNO| MB_ICONEXCLAMATION);

		if (wRep == IDYES)
		{
			mLastClickType = eClickNone;

			mPointList.clear();
		}
	}
}

void DessinApplication::onMouseMove(int iPosX, int iPosY)
{
	mPointList.push_front(Point(iPosX, iPosY));
}

void DessinApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{
	mPosX = iPosX;
	mPosY = iPosY;

	mLastClickType = eLeftDoubleClick;
}

void DessinApplication::onMouseLeftClick(int iPosX, int iPosY)
{
	mPosX = iPosX;
	mPosY = iPosY;

	mLastClickType = eLeftClick;
}

void DessinApplication::onMouseRightClick(int iPosX, int iPosY)
{
	mPosX = iPosX;
	mPosY = iPosY;

	mLastClickType = eRightClick;
}

void DessinApplication::onTimer()
{

	IApplication::onTimer();  // Pour redessiner l'ecran
}
