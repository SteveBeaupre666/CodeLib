#pragma once
//----------------------------------------------------------------------//
#include <Exceptions.h>
//----------------------------------------------------------------------//

template <class T> 
class Array2D
{
public:
	Array2D();
	Array2D(int w, int h);
	~Array2D();
private:
	T*   buffer;
	int  size; 
	int  width; 
	int  height; 
	void Initialize();
	int  CalcIndex(int x, int y);
	bool IsOutOfBounds(int x, int y);
public:
	int  Size();
	int  Width();
	int  Height();
	bool IsEmpty();

	T    Get(int x, int y);
	void Set(int x, int y, T data);
	T*   GetBuffer();

	void Allocate(int w, int h);
	void Resize(int w, int h);
	void Erase();
	void Free();
};

//-----------------------------------------------------------------------------
// Default constructor...
//-----------------------------------------------------------------------------
template <class T> Array2D<T>::Array2D()
{
	Initialize();
}

//-----------------------------------------------------------------------------
// Optional constructor...
//-----------------------------------------------------------------------------
template <class T> Array2D<T>::Array2D(int w, int h)
{
	Initialize();
	Allocate(w, h);
}

//-----------------------------------------------------------------------------
// Destructor...
//-----------------------------------------------------------------------------
template <class T> Array2D<T>::~Array2D()
{
	Free();
}

//-----------------------------------------------------------------------------
// Reset member variables
//-----------------------------------------------------------------------------
template <class T> void Array2D<T>::Initialize()
{
	size   = 0; 
	width  = 0; 
	height = 0; 
	buffer = NULL;
}

//-----------------------------------------------------------------------------
// Return the array size
//-----------------------------------------------------------------------------
template <class T> int Array2D<T>::Size()
{
	return size; 
}

//-----------------------------------------------------------------------------
// Return the width
//-----------------------------------------------------------------------------
template <class T> int Array2D<T>::Width()
{
	return width; 
}

//-----------------------------------------------------------------------------
// Return the height
//-----------------------------------------------------------------------------
template <class T> int Array2D<T>::Height()
{
	return height; 
}

//-----------------------------------------------------------------------------
// Return true if the array is unallocated
//-----------------------------------------------------------------------------
template <class T> bool Array2D<T>::IsEmpty()
{
	return !buffer;
}

//-----------------------------------------------------------------------------
// Check if the x,y coordinate are out of bounds
//-----------------------------------------------------------------------------
template <class T> bool Array2D<T>::IsOutOfBounds(int x, int y)
{
	return ((x < 0 || x >= width) || (y < 0 || y >= height));
}

//-----------------------------------------------------------------------------
// Return the linear address of coordinates
//-----------------------------------------------------------------------------
template <class T> int Array2D<T>::CalcIndex(int x, int y)
{
	return (y * width) + x;
}

//-----------------------------------------------------------------------------
// Return the array data at given position
//-----------------------------------------------------------------------------
template <class T> T Array2D<T>::Get(int x, int y)
{
	if(IsOutOfBounds(x, y))
		throw IndexOutOfBoundsException(__FILE__, __LINE__);

	int index = CalcIndex(x, y);
	return buffer[index];
}

//-----------------------------------------------------------------------------
// Set the array data at given position
//-----------------------------------------------------------------------------
template <class T> void Array2D<T>::Set(int x, int y, T data)
{
	if(IsOutOfBounds(x, y))
		throw IndexOutOfBoundsException(__FILE__, __LINE__);

	int index = CalcIndex(x, y);
	buffer[index] = data;
}

//-----------------------------------------------------------------------------
// Return the buffer's pointer
//-----------------------------------------------------------------------------
template <class T> T* Array2D<T>::GetBuffer()
{
	return &buffer[0];
}

//-----------------------------------------------------------------------------
// Allocate the array
//-----------------------------------------------------------------------------
template <class T> void Array2D<T>::Allocate(int w, int h)
{
	if(w <= 0 || h <= 0)
		throw InvalidArrayOperationException(__FILE__, __LINE__);

	width  = w;
	height = h;
	size   = w * h;

	buffer = new T[size];
	ZeroMemory(buffer, size * sizeof(T));
}

//-----------------------------------------------------------------------------
// Resize the array
//-----------------------------------------------------------------------------
template <class T> void Array2D<T>::Resize(int w, int h)
{
	if(w <= 0 || h <= 0)
		throw InvalidArrayOperationException(__FILE__, __LINE__);

	Free();
	Allocate(w, h);
}

//-----------------------------------------------------------------------------
// Erase the array
//-----------------------------------------------------------------------------
template <class T> void Array2D<T>::Erase()
{
	if(IsEmpty())
		throw InvalidArrayOperationException(__FILE__, __LINE__);

	ZeroMemory(buffer, size * sizeof(T));
}

//-----------------------------------------------------------------------------
// Free the array
//-----------------------------------------------------------------------------
template <class T> void Array2D<T>::Free()
{
	if(!IsEmpty()){
		delete [] buffer;
		Initialize();
	}
}
