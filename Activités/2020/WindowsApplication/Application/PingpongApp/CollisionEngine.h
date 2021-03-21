#pragma 
#include "PingPongBall.h"
#include "PingPongPad.h"

class CollisionEngine
{
public:
	CollisionEngine();


	void setBall(PingPongBall* iball);
	void setLeftPad(PingPongPad* iPad);
	void setRightPad(PingPongPad* iPad);
	void rebound(RECT iWindowRect);
	void afficherEchanges(HDC ihdc);

private:
	PingPongBall* mBallPtr;
	PingPongPad* mLeftPadPtr;
	PingPongPad* mRightPadPtr;

	bool mInit = false;

	int mNbEchanges = 0;

	const int mPadWith = 20;
	const int mPadHeight = 200;
};

