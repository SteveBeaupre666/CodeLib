#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//

class CTxtFile {
public:
	CTxtFile();
	~CTxtFile();
private:
	FILE *hFile;
private:
	void Initialize();
public:
	bool IsOpened();
	bool Open(char *fname);
	bool Create(char *fname);
	void Close();

	bool  ReadChar(char *c);
	char* ReadLine(char *buffer, int size);

	bool WriteChar(char c);
	int  WriteLine(char *buffer);
	int  WriteArgs(const char *fmt, ...);

	int  Tell();
	void Flush();
};
