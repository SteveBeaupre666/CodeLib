#include "DiskIO.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void CDiskIO::InitializeEx()
{
	ResetDriveInformation();
}

////////////////////////////////////////////////////////////////

void CDiskIO::ResetDriveInformation()
{
	BytesPerSector        = 0;
	SectorsPerCluster     = 0;
	NumberOfFreeClusters  = 0;
	TotalNumberOfClusters = 0;
}

////////////////////////////////////////////////////////////////

bool CDiskIO::LoadDriveInformation(char drive)
{
	ResetDriveInformation();

	DWORD dwBytesPerSector        = 0;
	DWORD dwSectorsPerCluster     = 0;
	DWORD dwNumberOfFreeClusters  = 0;
	DWORD dwTotalNumberOfClusters = 0;

	char Path[4] = {drive,':', '\\', 0};
	BOOL res = GetDiskFreeSpaceA(Path, &dwSectorsPerCluster, &dwBytesPerSector, &dwNumberOfFreeClusters, &dwTotalNumberOfClusters);

	BytesPerSector        = (UI64)dwBytesPerSector;
	SectorsPerCluster     = (UI64)dwSectorsPerCluster;
	NumberOfFreeClusters  = (UI64)dwNumberOfFreeClusters;
	TotalNumberOfClusters = (UI64)dwTotalNumberOfClusters;

	return res ? true : false;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

bool CDiskIO::IsAlpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

////////////////////////////////////////////////////////////////

char CDiskIO::Uppercase(char c)
{
	if(c >= 'a' && c <= 'z')
		c -= 0x20;

	return c;
}

////////////////////////////////////////////////////////////////

bool CDiskIO::IsDriveLetterValid(char drive)
{
	return IsAlpha(Uppercase(drive));
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void CDiskIO::GenRootPathName(char drive, char *buf)
{
	if(IsDriveLetterValid(drive))
		sprintf(buf, "\\\\.\\%c:", drive);
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetSize()
{
	return GetDiskSize();
}

////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetDiskSize()
{
	return GetTotalNumberOfSectors() * GetSectorSize();
}

////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetSectorSize()
{
	return (UI64)BytesPerSector;
}

////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetClusterSize()
{
	return GetSectorSize() * GetNumSectorsPerCluster();
}

////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetNumFreeClusters()
{
	return (UI64)NumberOfFreeClusters;
}

////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetTotalNumberOfClusters()
{
	return (UI64)TotalNumberOfClusters;
}

////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetNumSectorsPerCluster()
{
	return (UI64)SectorsPerCluster;
}

////////////////////////////////////////////////////////////////

UI64 CDiskIO::GetTotalNumberOfSectors()
{
	return GetNumSectorsPerCluster() * GetTotalNumberOfClusters();
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

bool CDiskIO::Open(char drive, bool ReadOnly)
{
	Close();

	if(!IsDriveLetterValid(drive))
		return false;

	DWORD ShareMode          = FILE_SHARE_READ | FILE_SHARE_WRITE;
	DWORD DesiredAccess      = ReadOnly ? GENERIC_READ : (GENERIC_READ | GENERIC_WRITE);
	DWORD FlagsAndAttributes = FILE_FLAG_NO_BUFFERING | (ReadOnly ? FILE_ATTRIBUTE_NORMAL : FILE_FLAG_WRITE_THROUGH);

	char RootPathName[8];
	ZeroMemory(&RootPathName[0], 8);
	GenRootPathName(drive, RootPathName);
	LoadDriveInformation(drive);

	h = CreateFileA(RootPathName, DesiredAccess, ShareMode, NULL, OPEN_EXISTING, FlagsAndAttributes, NULL);

	return IsOpened();
}
