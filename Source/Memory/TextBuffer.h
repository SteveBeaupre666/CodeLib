#pragma once
//----------------------------------------------------------------------//
#include "Buffer.h"
//----------------------------------------------------------------------//

class CTextBuffer : public CBuffer {
public:
	CTextBuffer(){}
	CTextBuffer(char *s);
public:
	char GetChar(int n);
	bool GetChar(int n, char *val);
	bool SetChar(int n, char  val);

	void SetText(char *s);
	void Format(char *fmt, ...);
};

