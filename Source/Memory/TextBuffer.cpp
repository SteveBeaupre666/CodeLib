#include "TextBuffer.h"

CTextBuffer::CTextBuffer(char *s)
{
	SetText(s);
}

char CTextBuffer::GetChar(int n)
{
	return (char)GetByte(n);
}

bool CTextBuffer::GetChar(int n, char *val)
{
	return GetByte(n, (BYTE*)val);
}

bool CTextBuffer::SetChar(int n, char val)
{
	return SetByte(n, (BYTE)val);
}

void CTextBuffer::SetText(char *s)
{
	Free();
	if(!s)
		return;

	int len = strlen(s);
	
	Allocate(len+1);
	strncpy((char*)Buffer, s, BufferSize);
}

void CTextBuffer::Format(char *fmt, ...)
{
	if(!IsAllocated() || !fmt)
		return;

	Erase();

	va_list ap;
	va_start(ap, fmt);
	_vsnprintf((char*)Buffer, BufferSize, fmt, ap);
	va_end(ap);
}

