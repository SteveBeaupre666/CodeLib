#pragma once
//----------------------------------------------------------------------//
#include "GenericTest.h"
#include "Array2D.h"
//----------------------------------------------------------------------//

class Array2DTest : public GenericTest {
public:
	Array2DTest();
	virtual ~Array2DTest();
private:
	void Initialize();
public:
	void SetUp();
	void TearDown();
	void RunTests();
public:
	static void TestAllocate();
	/*static void TestAllocateWithZero();
	static void TestAllocateWithNegativeValue();
	static void TestIsAllocated();
	static void TestIsEmpty();

	static void TestResizeWithZero();
	static void TestResizeWithNegativeValue();
	static void TestResizeIntoEqualSizeBuffer();
	static void TestResizeIntoSmallerSizeBuffer();
	static void TestResizeIntoGreaterSizeBuffer();

	static void TestErase();
	static void TestFree();

	static void TestCopyByRef();
	static void TestCopyByPtrAndSize();

	static void TestGet1();
	static void TestGet2();
	static void TestSet();

	static void TestGetSize();
	static void TestGetBufferSize();
	static void TestGetBuffer();

	static void TestBracketOperator();
	static void TestAssignOperator();
	static void TestEqualOperator();
	static void TestNotEqualOperator();*/
};


