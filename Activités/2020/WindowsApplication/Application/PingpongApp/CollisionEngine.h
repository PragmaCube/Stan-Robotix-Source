#pragma 
#include "PingPongBall.h"
#include "PingPongPad.h"

class CollisionEngine
{
public:
	CollisionEngine();

	void execute();

	void setBall(PingPongBall* iball);
	void setLeftPad(PingPongPad* iPad);
	void setRightPad(PingPongPad* iPad);
	void updateDrawingArea(RECT iWindowRect);
	void rebound();

private:
	PingPongBall* mBallPtr;
	PingPongPad* mLeftPadPtr;
	PingPongPad* mRightPadPtr;
};

