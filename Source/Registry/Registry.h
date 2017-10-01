#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//

class CRegistry {
public:
	CRegistry();
	~CRegistry();
private:
	HKEY Key;
	void Initialize();
public:
	HKEY GetKey();
	bool IsKeyOpened();
	bool KeyExist(HKEY RootKey, char* SubKey);
	bool CreateKey(HKEY RootKey, char* SubKey);
	bool OpenKey(HKEY RootKey, char* SubKey);
	bool DeleteKey(HKEY RootKey, char* SubKey);
	void CloseKey();

	bool ValueExist(char* name);
	UINT GetValueType(char* name);
	bool GetValue(char* name, void *data, DWORD *size);
	bool SetValue(char* name, DWORD type, void *data, DWORD size);
	bool DeleteValue(char* name);
};
