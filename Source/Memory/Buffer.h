#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//

class CBuffer {
public:
	CBuffer();
	CBuffer(UINT size);
	~CBuffer();
protected:
	BYTE* Buffer;
	UINT  BufferSize;
	void  Initialize();
private:
	bool IsIndexValid(int n);
public:
	bool IsAllocated();
	bool Allocate(int size);
	void Erase();
	void Free();

	UINT GetSize();
	bool Resize(int size);

	BYTE GetByte(int n);
	bool GetByte(int n, BYTE *val);
	bool SetByte(int n, BYTE  val);

	BYTE* GetBuffer(int n = 0);
	char* GetString(int n = 0);
};

