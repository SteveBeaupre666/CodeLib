#include "ArrayTest.h"

#pragma warning(push)
#pragma warning(disable : 4101)

//char VALUE_A = 'A';
//char VALUE_B = 'B';
//char VALUE_C = 'C';

Array<char> *_array = NULL;

////////////////////////////////////////////////////////////////////////////////////////////
// Constructor...
////////////////////////////////////////////////////////////////////////////////////////////
ArrayTest::ArrayTest()
{
	Initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Destructor...
////////////////////////////////////////////////////////////////////////////////////////////
ArrayTest::~ArrayTest()
{
	TearDown();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Initialize the obect's pointer
////////////////////////////////////////////////////////////////////////////////////////////
void ArrayTest::Initialize()
{
	_array = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Allocate the object to test dynamically
////////////////////////////////////////////////////////////////////////////////////////////
void ArrayTest::SetUp()
{
	TearDown();
	_array = new Array<char>;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Free the object we've allocated... 
////////////////////////////////////////////////////////////////////////////////////////////
void ArrayTest::TearDown()
{
	SAFE_DELETE_OBJECT(_array);
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing Methods for bla bla bla
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void ArrayTest::TestAllocate()
{
	const int TestSize = 512;
	
	AssertTrue(_array->Allocate(TestSize));
	_array->Free();
}

void ArrayTest::TestAllocateWithZero()
{
	AssertFalse(_array->Allocate(0));
}

void ArrayTest::TestAllocateWithNegativeValue()
{
	AssertFalse(_array->Allocate(-1));
}

void ArrayTest::TestIsAllocated()
{

}

void ArrayTest::TestIsEmpty()
{

}

void ArrayTest::TestResizeWithZero()
{

}

void ArrayTest::TestResizeWithNegativeValue()
{

}

void ArrayTest::TestResizeIntoEqualSizeBuffer()
{

}

void ArrayTest::TestResizeIntoSmallerSizeBuffer()
{

}

void ArrayTest::TestResizeIntoGreaterSizeBuffer()
{

}

void ArrayTest::TestErase()
{

}

void ArrayTest::TestFree()
{

}

void ArrayTest::TestCopyByRef()
{

}

void ArrayTest::TestCopyByPtrAndSize()
{

}

void ArrayTest::TestGet1()
{

}

void ArrayTest::TestGet2()
{

}

void ArrayTest::TestSet()
{

}

void ArrayTest::TestGetSize()
{

}

void ArrayTest::TestGetBufferSize()
{

}

void ArrayTest::TestGetBuffer()
{

}

void ArrayTest::TestBracketOperator()
{

}

void ArrayTest::TestAssignOperator()
{

}

void ArrayTest::TestEqualOperator()
{

}

void ArrayTest::TestNotEqualOperator()
{

}

////////////////////////////////////////////////////////////////////////////////////////////
// Run all the tests then print results...
////////////////////////////////////////////////////////////////////////////////////////////
void ArrayTest::RunTests()
{
	ResetTestsResults();
	PrintTestName("Array");

	//RunTest(TestAllocate, "TestAllocate");
	
	PrintTestsResults();
}

#pragma warning(pop)
