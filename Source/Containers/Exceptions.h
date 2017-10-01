#pragma once
//----------------------------------------------------------------------//
#include <windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//

#define MAX_EXCEPTION_BUFFER_SIZE	4096

// GenericException
// UnsupportedOperationException
// IndexOutOfBoundsException
// OutOfMemoryException

//-----------------------------------------------------------------------------

class GenericException {
public:
	GenericException(){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = 0;
	}

	GenericException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Generic exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "GenericException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
protected:
	char msg[MAX_EXCEPTION_BUFFER_SIZE];
	char title[MAX_EXCEPTION_BUFFER_SIZE];
	char fname[MAX_EXCEPTION_BUFFER_SIZE];
	int  LineNumber;
public:
	virtual void Print(){
		printf("%s\nFile: \"%s\"\nLine no: %d\n\n", msg, fname, LineNumber);
	}
	virtual void ShowMessage(){
		
		char Buffer[MAX_EXCEPTION_BUFFER_SIZE];
		ZeroMemory(Buffer, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(Buffer, MAX_EXCEPTION_BUFFER_SIZE, "%s\nFile: \"%s\"\nLine no: %d", msg, fname, LineNumber);

		MessageBox(0, Buffer, title, MB_OK);
	}
};

//-----------------------------------------------------------------------------

class UnsupportedOperationException : public GenericException {
public:
	UnsupportedOperationException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Unsupported operation exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "UnsupportedOperationException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------

class IndexOutOfBoundsException : public GenericException {
public:
	IndexOutOfBoundsException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Index out of bounds exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "IndexOutOfBoundsException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------

class OutOfMemoryException : public GenericException {
public:
	OutOfMemoryException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Out of memory exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "OutOfMemoryException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------

class IteratorOutOfBoundsException : public GenericException {
public:
	IteratorOutOfBoundsException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Iterator out of bounds exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "IteratorOutOfBoundsException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------

class EmptyQueueException : public GenericException {
public:
	EmptyQueueException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Empty queue exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "EmptyQueueException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------

class EmptyStackException : public GenericException {
public:
	EmptyStackException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Empty stack exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "EmptyStackException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------

class InvalidTreeOperationException : public GenericException {
public:
	InvalidTreeOperationException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Invalid tree operation exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "InvalidTreeOperationException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------

class InvalidArrayOperationException : public GenericException {
public:
	InvalidArrayOperationException(char *file_name, int LineNo){
		ZeroMemory(msg, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(msg, MAX_EXCEPTION_BUFFER_SIZE, "%s", "Invalid array operation exception.");
		ZeroMemory(title, MAX_EXCEPTION_BUFFER_SIZE);
		_snprintf(title, MAX_EXCEPTION_BUFFER_SIZE, "%s", "InvalidArrayOperationException");
		ZeroMemory(fname, MAX_EXCEPTION_BUFFER_SIZE);
		strncpy(fname, file_name, MAX_EXCEPTION_BUFFER_SIZE);
		LineNumber = LineNo;
	}
};

//-----------------------------------------------------------------------------
