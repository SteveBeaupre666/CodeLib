#include "Buffer.h"

CBuffer::CBuffer()
{
	Initialize();
}

CBuffer::CBuffer(UINT size)
{
	Initialize();
	Allocate(size);
}

CBuffer::~CBuffer()
{
	Free();
}

void CBuffer::Initialize()
{
	Buffer = NULL;
	BufferSize = 0; 
}

bool CBuffer::IsIndexValid(int n)
{
	if(!IsAllocated())
		return false;

	return ((n >= 0) && (n < (int)BufferSize));
}

bool CBuffer::IsAllocated()
{
	return Buffer != NULL;
}

bool CBuffer::Allocate(int size)
{
	if(size <= 0){
		Free();
		return false;	
	} else if(size == BufferSize){
		Erase();
		return true;
	} else {
		Free();
		Buffer = new BYTE[size];
		if(Buffer){
			BufferSize = size;
			Erase();
			return true;
		} else {
			Initialize();
			return false;
		}
	}
}

bool CBuffer::Resize(int size)
{
	if(!IsAllocated())
		return false;

	UINT NewSize = size;
	UINT OldSize = BufferSize;

	if(NewSize == 0 || OldSize == 0)
		return false;
	
	if(NewSize == OldSize)
		return true;
	
	BYTE *NewBuffer = new BYTE[NewSize];
	if(!NewBuffer)
		return false;
	
	ZeroMemory(NewBuffer, NewSize);
	memcpy(NewBuffer, Buffer, NewSize < OldSize ? NewSize : OldSize);

	Free();
	Buffer = NewBuffer;
	BufferSize = NewSize;

	return true;
}

void CBuffer::Erase()
{
	if(IsAllocated())
		ZeroMemory(Buffer, BufferSize);
}

void CBuffer::Free()
{
	if(IsAllocated()){
		delete [] Buffer;
		Initialize();
	}
}

UINT CBuffer::GetSize()
{
	return BufferSize;
}

BYTE CBuffer::GetByte(int n)
{
	if(!IsIndexValid(n))
		return 0;

	return Buffer[n];
}

bool CBuffer::GetByte(int n, BYTE* val)
{
	if(!IsIndexValid(n))
		return false;

	*val = Buffer[n];
	return true;
}

bool CBuffer::SetByte(int n, BYTE val)
{
	if(!IsIndexValid(n))
		return false;

	Buffer[n] = val;
	return true;
}

BYTE* CBuffer::GetBuffer(int n)
{
	if(!IsIndexValid(n))
		return NULL;

	return &Buffer[n];
}

char* CBuffer::GetString(int n)
{
	return (char*)GetBuffer(n);
}

