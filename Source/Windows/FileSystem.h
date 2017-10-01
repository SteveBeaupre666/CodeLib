#pragma once
//----------------------------------------------------------------------//
#pragma comment(lib, "Winmm.lib")
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//
#include <direct.h>
//----------------------------------------------------------------------//
#define UI64 unsigned __int64
//----------------------------------------------------------------------//

struct FileAttributes {
	bool ReadOnly;
	bool Hidden;
	bool System;
	bool Directory;
	bool Archive;
	bool Normal;
	bool Temporary;
	bool SparseFile;
	bool ReparsePoint;
	bool Compressed;
	bool Offline;
	bool NotIndexed;
	bool Encrypted;
	bool Virtual;
};

class CFileManager {
public:
	bool DoesExist(char *filename);
	bool InUse(char *filename);

	void Copy(char *source, char *dest, bool overwrite);
	void Move(char *source, char *dest);
	void Rename(char *source, char *dest);
	void Delete(char *filename);

	bool SendToRecycleBin(char *filename, WORD flags = 0x0054);
	
	UI64 GetSize(char *fname);
	
	UINT GetAttributes(char *filename, FileAttributes *attribs);
	bool SetAttributes(char *filename, FileAttributes *attribs);
	
	void GetShortName(char *longname, char *shortname);

	void Open(char *filename, char *params);
};

class CDirectoryManager {
public:
	bool DoesExist(char *name);
	
	bool Create(char *dirname);
	bool Delete(char *dirname);
	bool DeleteTree(char *dirname, UINT Level = 0);
	void Rename(char *source, char *dest);
	void SendToRecycleBin(char *dirname);
	
	void GetCurrentDirectory(char *dirname);
	void SetCurrentDirectory(char *dirname);

	void GetShortName(char *longname, char *shortname);
};

class CDriveManager {
public:
	UINT GetAvailableDrives();
	bool IsDriveAvailable(char drive);

	UI64 GetSize(char drive);
	UI64 GetSpaceFree(char drive);
	UI64 GetSpaceUsed(char drive);
	
	UI64 GetNumSectors(char drive);
	UINT GetNumBytesPerSector(char drive);
	
	UINT GetType(char drive);
	bool IsCDRom(char drive);
	bool IsHardDrive(char drive);
	bool IsFlashDrive(char drive);
	bool IsRemovableDrive(char drive);
	bool IsRemoteDrive(char drive);
	bool IsRamDisk(char drive);
	
	bool GetInformation(char drive, char *pLabel, char *pSerialNumber, char *pFileSystem);

	void OpenCDRom(char drive, BOOL bOpenDrive);
};
