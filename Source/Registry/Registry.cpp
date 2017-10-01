#include "Registry.h"

CRegistry::CRegistry()
{
	Initialize();
}

CRegistry::~CRegistry()
{
	CloseKey();
}

void CRegistry::Initialize()
{
	Key = 0;
}

HKEY CRegistry::GetKey()
{
	return Key; 
}

bool CRegistry::IsKeyOpened()
{
	return Key != 0; 
}

bool CRegistry::KeyExist(HKEY RootKey, char* SubKey)
{
	LONG res = RegOpenKeyEx(RootKey, SubKey, 0, KEY_ALL_ACCESS, &Key);
	if(res == ERROR_SUCCESS)
		RegCloseKey(Key);

	return res == ERROR_SUCCESS;
}

bool CRegistry::CreateKey(HKEY RootKey, char* SubKey)
{
	DWORD Disposition = 0;

	LONG res = RegCreateKeyEx(RootKey, SubKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &Key, &Disposition);

	return res == ERROR_SUCCESS;
}

bool CRegistry::OpenKey(HKEY RootKey, char* SubKey)
{
	LONG res = RegOpenKeyEx(RootKey, SubKey, 0, KEY_ALL_ACCESS, &Key);

	return res == ERROR_SUCCESS;
}

bool CRegistry::DeleteKey(HKEY RootKey, char* SubKey)
{
	LONG res = RegDeleteKey(RootKey, SubKey);

	return res == ERROR_SUCCESS;
}

void CRegistry::CloseKey()
{
	if(IsKeyOpened()){
		RegCloseKey(Key);
		Initialize();
	}
}

bool CRegistry::ValueExist(char* name)
{
	if(!IsKeyOpened())
		return false;

	DWORD Type = 0;
	DWORD Size = 0;
	
	LONG res = RegQueryValueEx(Key, name, 0, &Type, NULL, &Size);
	
	return res == ERROR_SUCCESS;
}

UINT CRegistry::GetValueType(char* name)
{
	if(!IsKeyOpened())
		return 0;

	DWORD Type = 0;
	DWORD Size = 0;
	
	LONG res = RegQueryValueEx(Key, name, 0, &Type, NULL, &Size);
	
	return res == ERROR_SUCCESS ? Type : 0;
}

bool CRegistry::GetValue(char* name, void *data, DWORD *size)
{
	if(!IsKeyOpened())
		return false;

	DWORD Type = 0;
	DWORD Size = 0;

	LONG res = RegQueryValueEx(Key, name, 0, &Type, (BYTE*)data, &Size);
	*size = Size;

	return res == ERROR_SUCCESS;
}

bool CRegistry::SetValue(char* name, DWORD type, void *data, DWORD size)
{
	if(!IsKeyOpened())
		return false;

	LONG res = RegSetValueEx(Key, name, 0, type, (BYTE*)data, size);
	
	return res == ERROR_SUCCESS;
}

bool CRegistry::DeleteValue(char* name)
{
	if(!IsKeyOpened())
		return false;

	LONG res = RegDeleteValue(Key, name);
	
	return res == ERROR_SUCCESS;
}

