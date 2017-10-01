#pragma once

#include <Windows.h>

class CWinTimer {
public:
	CWinTimer();
	~CWinTimer();
private:
	UINT TimerID;
	UINT TimerSpeed;
	TIMERPROC TimerProc;
private:
	void Reset();
public:
	BOOL IsRunning();
	BOOL Start(UINT Speed, TIMERPROC tp);
	void Stop();
public:
	UINT GetID();
	UINT GetSpeed();
	void SetSpeed(UINT Speed);
};