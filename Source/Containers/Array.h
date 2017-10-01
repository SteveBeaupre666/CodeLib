#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//
#include <Exceptions.h>
//----------------------------------------------------------------------//

template <class T> class Array {
public:
	Array();
	Array(int size);
	~Array();
private:
	T*  buffer;
	int buffer_size; 
	int items_size;
	int items_count;

	void Initialize();
	bool InRange(int n);

	int  Min(int a, int b);
	int  Max(int a, int b);
public:
	bool IsEmpty();
	bool IsAllocated();

	bool Allocate(int n);
	bool Resize(int n);
	bool Erase();
	void Free();
	
	bool Copy(T* buf, int size);
	bool Copy(const Array &data);

	int  ItemsSize();
	int  ItemsCount();

	T*   Get(int n);
	void Get(int n, T* item);
	void Set(int n, T* item);

	int  GetSize();
	int  GetBufferSize();
	T*   GetBuffer(int n = 0);

	T& operator[](int n);
	Array<T> operator = (const Array &data);

	bool operator == (const Array &data);
	bool operator != (const Array &data);
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> Array<T>::Array()
{
	Initialize();
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> Array<T>::Array(int size)
{
	Initialize();
	Allocate(size);
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> Array<T>::~Array()
{
	Free();
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> void Array<T>::Initialize()
{
	buffer      = NULL;
	buffer_size = 0; 
	items_size  = 0;
	items_count = 0;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> int Array<T>::Min(int a, int b)
{
	return a < b ? a : b;
}
////////////////////////////////////////////////////////////////////////////////////

template <class T> int Array<T>::Max(int a, int b)
{
	return a > b ? a : b;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::InRange(int n)
{
	return IsAllocated() && (Indx >= 0 && n < buffer_size);
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::IsEmpty()
{
	return buffer_size > 0;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::IsAllocated()
{
	return buffer != NULL;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::Allocate(int n)
{
	if(n <= 0){
		throw IndexOutOfBoundsException(__FILE__, __LINE__);
		return false;
	}

	Free();

	items_count = n;
	items_size  = sizeof(T);
	buffer_size = sizeof(T) * n;

	buffer = new T[items_count];
	if(!buffer){
		Initialize();
		throw OutOfMemoryException(__FILE__, __LINE__);
		return false;
	}

	Erase();
	return true;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::Resize(int n)
{
	Free();

	if(size <= 0){
		if(!size)
			throw IndexOutOfBoundsException(__FILE__, __LINE__);

		return false;
	}

	int OldSize = buffer_size;
	int NewSize = size * sizeof(T);

	T *OldBuffer = buffer;
	T *NewBuffer = new T[NewSize];

	if(!NewBuffer){
		Free();
		throw OutOfMemoryException(__FILE__, __LINE__);
		return false;
	}

	ZeroMemory(NewBuffer, sizeof(T) * NewSize); 
	memcpy(NewBuffer, OldBuffer, size >= buffer_size ? OldSize : NewSize);
	Free();

	items_size  = sizeof(T);
	items_count = size;

	buffer      = NewBuffer;
	buffer_size = NewSize;

	return true;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::Copy(T* buf, int size)
{
	Free();
	return Allocate(size);
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::Copy(const Array &data)
{
	return Copy(buf.GetBuffer(), a.GetSize());
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::Erase()
{
	if(IsAllocated()){
		ZeroMemory(buffer, buffer_size);
		return true;
	}

	return false;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> void Array<T>::Free()
{
	if(IsAllocated()){
		delete [] buffer;
		Initialize();	
	}
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> T* Array<T>::GetBuffer(int n)
{
	if(!InRange(n))
		return NULL;

	return &buffer[n];
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> int Array<T>::GetSize()
{
	return buffer_size;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> int Array<T>::GetBufferSize()
{
	return buffer_size;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> T* Array<T>::Get(int n)
{
	if(!InRange(n))
		return NULL;

	return &buffer[n];
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> void Array<T>::Get(int n, T* item)
{
	switch(InRange(n))
	{
	case false: ZeroMemory(item, sizeof(T));         break;
	case true:  memcpy(item, &buffer[n], sizeof(T)); break;
	}
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> void Array<T>::Set(int n, T* item)
{
	if(InRange(n))
		buffer[n] = *item;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

template <class T> T& Array<T>::operator[](int n)
{
	if(!InRange(indx)){
		T tmp;
		ZeroMemory(&tmp, sizeof(T));
		return tmp;
	}

	return buffer[indx];
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> Array<T> Array<T>::operator=(const Array& data)
{
	if(buffer_size == 0){
		Free();
	} else {
		Allocate(buffer_size);
		Copy(a);
	}

	return *this;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::operator==(const Array& data)
{
	if(buffer_size != a.GetBufferSize())
		return false;

	if(buffer_size == 0 && a.GetSize() == 0)
		return true;

	return memcmp(buffer, a.GetBuffer(), sizeof(T)) == 0;
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> bool Array<T>::operator!=(const Array& data)
{
	return !(operator == a);
}
