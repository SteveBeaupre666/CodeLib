#pragma once
//----------------------------------------------------------------------//
#include "LinkedList.h"
//----------------------------------------------------------------------//

template <class T> class Stack {
public:
	Stack(){}
	~Stack();
private:
	LinkedList<T> List;
public:
	int  Size();
	bool IsEmpty();

	void Push(T data);
	T    Peek();
	T    Pop();

	void Clear();
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// Destructor...
//-----------------------------------------------------------------------------
template <class T> Stack<T>::~Stack()
{
	Clear();
}

//-----------------------------------------------------------------------------
// Obtains the number of elements in the stack
//-----------------------------------------------------------------------------
template <class T> int Stack<T>::Size()
{
	return List.Size();
}

//-----------------------------------------------------------------------------
// Determines whether the stack is empty
//-----------------------------------------------------------------------------
template <class T> bool Stack<T>::IsEmpty()
{
	return List.IsEmpty();
}

//-----------------------------------------------------------------------------
// Adds a value to the top of the stack
//-----------------------------------------------------------------------------
template <class T> void Stack<T>::Push(T data)
{
	List.Insert(0, data);
}

//-----------------------------------------------------------------------------
// Returns but does not delete the value at the top of the stack
//-----------------------------------------------------------------------------
template <class T> T Stack<T>::Peek()
{
	if(List.Size() == 0)
		throw EmptyStackException(__FILE__, __LINE__);

	return List.Get(0);
}

//-----------------------------------------------------------------------------
// Retrieves the value at the head of the queue
//-----------------------------------------------------------------------------
template <class T> T Stack<T>::Pop()
{
	if(List.Size() == 0)
		throw EmptyStackException(__FILE__, __LINE__);

	T res = List.Get(0);
	List.Delete(0);

	return res;
}

//-----------------------------------------------------------------------------
// Deletes all elements from the stack
//-----------------------------------------------------------------------------
template <class T> void Stack<T>::Clear()
{
	List.Clear();
}
