#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//
#include "FileIO.h"
//----------------------------------------------------------------------//

class CDiskIO : public CFileIO {
private:
	UI64 BytesPerSector;
	UI64 SectorsPerCluster;
	UI64 NumberOfFreeClusters;
	UI64 TotalNumberOfClusters;
private:
	void InitializeEx();
	void ResetDriveInformation();

	bool IsAlpha(char c);
	char Uppercase(char c);
	bool IsDriveLetterValid(char drive);
	void GenRootPathName(char drive, char *buf);

	bool Create(char *fname){return false;}
	bool Open(char *fname, bool ReadOnly = true){return false;}
	void Flush(){}
public:
	bool LoadDriveInformation(char drive);
	bool Open(char drive, bool ReadOnly = true);
public:
	UI64 GetSize();
	UI64 GetDiskSize();
	UI64 GetSectorSize();
	UI64 GetClusterSize();
	UI64 GetNumFreeClusters();
	UI64 GetTotalNumberOfClusters();
	UI64 GetNumSectorsPerCluster();
	UI64 GetTotalNumberOfSectors();
};
