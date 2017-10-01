#include "GameTimer.h"

//-----------------------------------------------------------------------------
// Return number of frame recorded in one second
//-----------------------------------------------------------------------------
float CGameTimer::GetFPS()
{
	return FPS;
}

//-----------------------------------------------------------------------------
// Extend Reset()
//-----------------------------------------------------------------------------
void CGameTimer::OnReset()
{
	FPS = 0;
	FPSElapsedTime = 0.0f;
	Frame = 0;
}

//-----------------------------------------------------------------------------
// Extend Tick()
//-----------------------------------------------------------------------------
void CGameTimer::OnTick(float ElapsedTime)
{
	Frame++;
	FPSElapsedTime += ElapsedTime;
	if(FPSElapsedTime >= 1.0f){
		FPS = (float)Frame / FPSElapsedTime;
		Frame = 0;
		while(FPSElapsedTime >= 1.0f)
			FPSElapsedTime -= 1.0f;
	}
}

