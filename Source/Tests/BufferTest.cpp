#include "BufferTest.h"

#pragma warning(push)
#pragma warning(disable : 4101)

CTestBuffer* buffer = NULL;

////////////////////////////////////////////////////////////////////////////////////////////
// Constructor...
////////////////////////////////////////////////////////////////////////////////////////////
BufferTest::BufferTest()
{
	Initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Destructor...
////////////////////////////////////////////////////////////////////////////////////////////
BufferTest::~BufferTest()
{
	TearDown();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Initialize the obect's pointer
////////////////////////////////////////////////////////////////////////////////////////////
void BufferTest::Initialize()
{
	buffer = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Allocate the object to test dynamically
////////////////////////////////////////////////////////////////////////////////////////////
void BufferTest::SetUp()
{
	TearDown();
	buffer = new CTestBuffer();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Free the object we've allocated... 
////////////////////////////////////////////////////////////////////////////////////////////
void BufferTest::TearDown()
{
	SAFE_DELETE_OBJECT(buffer);
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing Methods for bla bla bla
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestAllocate()
{
	AssertTrue(buffer->Allocate(64));
	AssertTrue(buffer->GetBuffer() != NULL);
	AssertEquals(64, buffer->GetSize());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestAllocateWithZero()
{
	AssertFalse(buffer->Allocate(0));
	AssertTrue(buffer->GetBuffer() == NULL);
	AssertEquals(0, buffer->GetSize());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestAllocateWithNegativeValue()
{
	AssertFalse(buffer->Allocate(-1));
	AssertTrue(buffer->GetBuffer() == NULL);
	AssertEquals(0, buffer->GetSize());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestIsAllocated()
{
	AssertFalse(buffer->IsAllocated());
	AssertTrue(buffer->Allocate(64));
	AssertTrue(buffer->IsAllocated());
	buffer->Free();
	AssertFalse(buffer->IsAllocated());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestFree()
{
	AssertTrue(buffer->Allocate(64));
	AssertTrue(buffer->FreeExt());
	AssertFalse(buffer->FreeExt());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestSizeUnallocated()
{
	AssertEquals(0, buffer->GetSize());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestSize()
{
	AssertTrue(buffer->Allocate(64));
	AssertEquals(64, buffer->GetSize());
	AssertTrue(buffer->FreeExt());
	AssertEquals(0, buffer->GetSize());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestErase()
{
	AssertTrue(buffer->Allocate(64));
	AssertTrue(buffer->EraseExt());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestEraseUnallocated()
{
	AssertFalse(buffer->EraseExt());
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestResizeUnallocated()
{
	AssertFalse(buffer->Resize(1024));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestResizeSmaller()
{
	BYTE AuxBuffer[64];
	AssertTrue(buffer->Allocate(64));

	BYTE *MyBuffer = buffer->GetBuffer();
	
	for(int i = 0; i < 64; i++){
		MyBuffer[i]  = i + 1;
		AuxBuffer[i] = i + 1;
	}
	
	AssertTrue(buffer->Resize(32));

	AssertEquals(32, buffer->GetSize());
	AssertEquals(0, memcmp(buffer->GetBuffer(), &AuxBuffer[0], 32));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestResizeBigger()
{
	BYTE AuxBuffer1[128];
	BYTE AuxBuffer2[128];

	AssertTrue(buffer->Allocate(64));
	BYTE *MyBuffer = buffer->GetBuffer();
	
	for(int i = 0; i < 128; i++){

		if(i < 64)
			MyBuffer[i] = i + 1;

		AuxBuffer1[i] = i + 1;
		AuxBuffer2[i] = i < 64 ? i + 1 : 0;
	}

	AssertEquals(0, memcmp(buffer->GetBuffer(0), &AuxBuffer1[0],  64));

	AssertTrue(buffer->Resize(128));

	AssertEquals(128, buffer->GetSize());
	AssertEquals(0, memcmp(buffer->GetBuffer(0),  &AuxBuffer2[0],  64));
	AssertEquals(0, memcmp(buffer->GetBuffer(64), &AuxBuffer2[64], 64));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestResizeSameSize()
{
	BYTE AuxBuffer[64];

	AssertTrue(buffer->Allocate(64));
	BYTE *MyBuffer = buffer->GetBuffer();
	
	for(int i = 0; i < 64; i++){
		MyBuffer[i]  = i + 1;
		AuxBuffer[i] = i + 1;
	}

	AssertEquals(0, memcmp(&MyBuffer[0],  &AuxBuffer[0],  64));

	AssertTrue(buffer->Resize(64));

	AssertEquals(0, memcmp(buffer->GetBuffer(0),  &AuxBuffer[0],  64));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestGetUnallocated()
{
	BYTE b = 0xFF;
	AssertFalse(buffer->GetByte(0, &b));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestGetInRange()
{
	AssertTrue(buffer->Allocate(3));
	BYTE *MyBuffer = buffer->GetBuffer();

	for(int i = 0; i < 3; i++)
		MyBuffer[i]  = i + 1;

	AssertEquals(1, buffer->GetByte(0));
	AssertEquals(2, buffer->GetByte(1));
	AssertEquals(3, buffer->GetByte(2));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestGetOutOfRange()
{
	AssertTrue(buffer->Allocate(3));
	BYTE *MyBuffer = buffer->GetBuffer();

	for(int i = 0; i < 3; i++)
		MyBuffer[i]  = i + 1;

	AssertFalse(buffer->SetByte(-1, 1));
	AssertFalse(buffer->SetByte( 3, 2));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestSetUnallocated()
{
	BYTE b = 0xFF;
	AssertFalse(buffer->GetByte(0, &b));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestSetInRange()
{
	AssertTrue(buffer->Allocate(3));

	AssertTrue(buffer->SetByte(0, 1));
	AssertTrue(buffer->SetByte(1, 2));
	AssertTrue(buffer->SetByte(2, 3));

	AssertEquals(1, buffer->GetByte(0));
	AssertEquals(2, buffer->GetByte(1));
	AssertEquals(3, buffer->GetByte(2));
}

////////////////////////////////////////////////////////////////////////////////////////////

void BufferTest::TestSetOutOfRange()
{
	AssertTrue(buffer->Allocate(3));

	BYTE b = 0;
	AssertFalse(buffer->GetByte(-1, &b));
	AssertFalse(buffer->GetByte( 3, &b));
}

////////////////////////////////////////////////////////////////////////////////////////////

/*void BufferTest::TestBracketOperator()
{
	AssertTrue(buffer->Allocate(3));
	BYTE *MyBuffer = buffer->GetBuffer();

	for(int i = 0; i < 3; i++)
		MyBuffer[i]  = i + 1;

	BYTE b = buffer[0];
}*/

////////////////////////////////////////////////////////////////////////////////////////////
// Run all the tests then print results...
////////////////////////////////////////////////////////////////////////////////////////////
void BufferTest::RunTests()
{
	ResetTestsResults();
	PrintTestName("Buffer");

	RunTest(TestAllocate,					"TestAllocate");
	RunTest(TestAllocateWithZero,			"TestAllocateWithZero");
	RunTest(TestAllocateWithNegativeValue,	"TestAllocateWithNegativeValue");
	RunTest(TestIsAllocated,				"TestIsAllocated");
	RunTest(TestFree,						"TestFree");
	RunTest(TestSize,						"TestSize");
	RunTest(TestSizeUnallocated,			"TestSizeUnallocated");
	RunTest(TestErase,						"TestErase");
	RunTest(TestEraseUnallocated,			"TestEraseUnallocated");
	RunTest(TestResizeUnallocated,			"TestResizeUnallocated");
	RunTest(TestResizeSmaller,				"TestResizeSmaller");
	RunTest(TestResizeBigger,				"TestResizeBigger");
	RunTest(TestResizeSameSize,				"TestResizeSameSize");
	RunTest(TestGetUnallocated,				"TestGetUnallocated");
	RunTest(TestGetInRange,					"TestGetInRange");
	RunTest(TestGetOutOfRange,				"TestGetOutOfRange");
	RunTest(TestSetUnallocated,				"TestSetUnallocated");
	RunTest(TestSetInRange,					"TestSetInRange");
	RunTest(TestSetOutOfRange,				"TestSetOutOfRange");
	//RunTest(TestBracketOperator,			"TestBracketOperator");

	PrintTestsResults();
}

#pragma warning(pop)
