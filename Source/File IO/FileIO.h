#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//
#define UI64 unsigned __int64
//----------------------------------------------------------------------//
//enum MoveMethod {FileBegin, FileCurrent, FileEnd};
//----------------------------------------------------------------------//

class CFileIO {
public:
	CFileIO();
	~CFileIO();
protected:
	HANDLE h;

	void Initialize();
	virtual void InitializeEx(){}

	UI64 Pack64(void *hi, void *lo);
	void Unpack64(UI64 n, void *hi, void *lo);
public:
	bool IsOpened();
	void Close();

	virtual bool Create(char *fname);
	virtual bool Open(char *fname, bool ReadOnly = true);
	
	virtual UI64 GetSize();
	virtual void Flush();

	UI64 Tell();
	bool Seek(UI64 Offset, UINT MoveMethod);

	bool Read (void *buffer, UINT size, UINT *num_read = NULL);
	bool Write(void *buffer, UINT size, UINT *num_written = NULL);
};
