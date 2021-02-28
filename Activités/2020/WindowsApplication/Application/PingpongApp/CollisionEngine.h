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

private:
	PingPongBall* mBallPtr;
	PingPongPad* mLeftPadPtr;
	PingPongPad* mRightPadPtr;
};

