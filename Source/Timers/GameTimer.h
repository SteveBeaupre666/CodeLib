#pragma once
//----------------------------------------------------------------------//
#include "Timer.h"
//----------------------------------------------------------------------//

//-----------------------------------------------------------------------------
// Game Timer class
//-----------------------------------------------------------------------------
class CGameTimer : public CTimer {
protected:
	float FPS;
	float FPSElapsedTime;
	int   Frame;
public:
	float GetFPS();
	void  OnReset();
	void  OnTick(float elapsed_time);
};
