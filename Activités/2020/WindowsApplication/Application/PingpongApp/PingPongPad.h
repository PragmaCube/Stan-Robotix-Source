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

	    void movePadUp();

	    void movePadDown();

	    void paint(HDC ihdc, RECT& iPaintArea);

	    void initialiser(RECT iWindowRect);

	    void UpdatePosition();


	private:
		PingPongBall* mBallPtr;

		int mCoorYPadMax, mCoorYPadMin;
		int mCoorYMax, mCoorYMin, mCoorXMax, mCoorXMin;
		const double mWidth = 20;
		const double mHeight =	100;
		int mCoorY, mCoorX, mSpeed;
		char mKeyUp, mKeyDown;

		bool mIsInit;

		HBRUSH mBrush;
	};



