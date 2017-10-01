#pragma once
//----------------------------------------------------------------------//
#include "GenericTest.h"
#include "Buffer.h"
//----------------------------------------------------------------------//

class CTestBuffer : public CBuffer {
public:

	bool EraseExt(){
		if(IsAllocated()){
			ZeroMemory(Buffer, BufferSize);
			return true;
		}
		return false;
	}

	bool FreeExt(){
		if(IsAllocated()){
			delete [] Buffer;
			Initialize();
			return true;
		}
		return false;
	}

};

//----------------------------------------------------------------------//

class BufferTest : public GenericTest {
public:
	BufferTest();
	virtual ~BufferTest();
private:
	void Initialize();
public:
	void SetUp();
	void TearDown();
	void RunTests();
public:
	static void TestAllocate();
	static void TestAllocateWithZero();
	static void TestAllocateWithNegativeValue();
	static void TestIsAllocated();

	static void TestFree();

	static void TestSize();
	static void TestSizeUnallocated();

	static void TestErase();
	static void TestEraseUnallocated();

	static void TestResizeUnallocated();
	static void TestResizeSmaller();
	static void TestResizeBigger();
	static void TestResizeSameSize();

	static void TestGetUnallocated();
	static void TestGetInRange();
	static void TestGetOutOfRange();

	static void TestSetUnallocated();
	static void TestSetInRange();
	static void TestSetOutOfRange();

	//static void TestBracketOperator();
};


