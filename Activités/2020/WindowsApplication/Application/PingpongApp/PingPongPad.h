#pragma once
#include <Windows.h>

#include "PingPongBall.h"

	class PingPongPad
	{
	public:
	    enum { eRightPadId, eLeftPadId };
	
		PingPongPad(int iId);

		int getY();
		
		void setBall(PingPongBall* iball);

		void setAsLeft(HDC ihdc, RECT& iPaintArea);
		void setAsRight(HDC ihdc, RECT& iPaintArea);

		void moovePad(char iChar);


		void paint(HDC ihdc, RECT& iPaintArea);


	private:
		PingPongBall* mBallPtr;

		const double mWidth = 20;
		const double mHeight =	100;
		int mCoorY, mCoorX, mSpeed;
		char iChar1, iChar2;

		bool mIsInit;


		RECT mDrawingArea;

		COLORREF mColor;
		HBRUSH mBrush;
	};



