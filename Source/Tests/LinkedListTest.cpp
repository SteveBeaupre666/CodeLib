#include "LinkedListTest.h"

#pragma warning(push)
#pragma warning(disable:4101)

char VALUE_A = 'A';
char VALUE_B = 'B';
char VALUE_C = 'C';

LinkedList<char> *list = NULL;

////////////////////////////////////////////////////////////////////////////////////////////
// Constructor...
////////////////////////////////////////////////////////////////////////////////////////////
LinkedListTest::LinkedListTest()
{
	Initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Destructor...
////////////////////////////////////////////////////////////////////////////////////////////
LinkedListTest::~LinkedListTest()
{
	TearDown();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Initialize the obect's pointer
////////////////////////////////////////////////////////////////////////////////////////////
void LinkedListTest::Initialize()
{
	list = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Create a new object for each tests we do
////////////////////////////////////////////////////////////////////////////////////////////
void LinkedListTest::SetUp()
{
	TearDown();
	list = new LinkedList<char>;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Free the object after each tests we do
////////////////////////////////////////////////////////////////////////////////////////////
void LinkedListTest::TearDown()
{
	SAFE_DELETE_OBJECT(list);
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing Methods for Inserting and Adding Values
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestInsertIntoEmptyList()
{
	AssertEquals(0, list->GetSize());
	AssertTrue(list->IsEmpty());

	list->Insert(0, VALUE_A);

	AssertEquals(1, list->GetSize());
	AssertFalse(list->IsEmpty());
	AssertEquals(VALUE_A, *list->GetItem(0));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestInsertBetweenElements()
{
	list->Insert(0, VALUE_A);
	list->Insert(1, VALUE_B);
	list->Insert(1, VALUE_C);
	
	AssertEquals(3, list->GetSize());

	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_C, *list->GetItem(1));
	AssertEquals(VALUE_B, *list->GetItem(2));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestInsertBeforeFirstElement()
{
	list->Insert(0, VALUE_A);
	list->Insert(0, VALUE_B);

	AssertEquals(2, list->GetSize());
	AssertEquals(VALUE_B, *list->GetItem(0));
	AssertEquals(VALUE_A, *list->GetItem(1));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestInsertAfterLastElement()
{
	list->Insert(0, VALUE_A);
	list->Insert(1, VALUE_B);

	AssertEquals(2, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_B, *list->GetItem(1));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestInsertOutOfBounds()
{
	AssertEquals(NULL, list->Insert(-1, VALUE_A));
	AssertEquals(NULL, list->Insert( 1, VALUE_B));

	/*try {
		list->Insert(-1, VALUE_A);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}

	try {
		list->Insert(1, VALUE_B);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}*/
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestAdd()
{
	list->Push(VALUE_A);
	list->Push(VALUE_C);
	list->Push(VALUE_B);

	AssertEquals(3, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_C, *list->GetItem(1));
	AssertEquals(VALUE_B, *list->GetItem(2));
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing Methods for Retrieving and Storing Values
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestSet()
{
	list->Insert(0, VALUE_A);
	AssertEquals(VALUE_A, *list->GetItem(0));

	list->SetItem(0, VALUE_B);
	AssertEquals(VALUE_B, *list->GetItem(0));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestGetOutOfBounds()
{
	AssertEquals(NULL, list->GetItem(-1));
	AssertEquals(NULL, list->GetItem(0));
	AssertEquals(NULL, list->GetItem(1));

	/*try {
		*list->GetItem(-1);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}

	try {
		*list->GetItem(0);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}

	list->Push(VALUE_A);
	try {
		*list->GetItem(1);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}*/
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestSetOutOfBounds()
{
	AssertFalse(list->SetItem(-1, VALUE_A));
	AssertFalse(list->SetItem( 0, VALUE_B));
	AssertFalse(list->SetItem( 1, VALUE_C));

	/*try {
		list->SetItem(-1, VALUE_A);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}

	try {
		list->SetItem(0, VALUE_B);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}

	list->Insert(0, VALUE_C);

	try {
		list->SetItem(1, VALUE_C);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}*/
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing Methods for Deleting Values
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestDeleteOnlyElement()
{
	list->Push(VALUE_A);

	AssertEquals(1, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));

	list->Delete(0);
	AssertEquals(0, list->GetSize());
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestDeleteFirstElement()
{
	list->Push(VALUE_A);
	list->Push(VALUE_B);
	list->Push(VALUE_C);

	AssertEquals(3, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_B, *list->GetItem(1));
	AssertEquals(VALUE_C, *list->GetItem(2));

	list->Delete(0);

	AssertEquals(2, list->GetSize());
	AssertEquals(VALUE_B, *list->GetItem(0));
	AssertEquals(VALUE_C, *list->GetItem(1));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestDeleteLastElement()
{
	list->Push(VALUE_A);
	list->Push(VALUE_B);
	list->Push(VALUE_C);

	AssertEquals(3, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_B, *list->GetItem(1));
	AssertEquals(VALUE_C, *list->GetItem(2));

	list->Delete(2);

	AssertEquals(2, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_B, *list->GetItem(1));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestDeleteMiddleElement()
{
	list->Push(VALUE_A);
	list->Push(VALUE_C);
	list->Push(VALUE_B);

	AssertEquals(3, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_C, *list->GetItem(1));
	AssertEquals(VALUE_B, *list->GetItem(2));

	list->Delete(1);

	AssertEquals(2, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_B, *list->GetItem(1));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestDeleteOutOfBounds()
{
	AssertFalse(list->Delete(-1));
	AssertFalse(list->Delete(0));

	/*try {
		list->Delete(-1);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}

	try {
		list->Delete(0);
		THROW_TEST_FAILED;
	} catch (IndexOutOfBoundsException e){
		// expected
	}*/
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestDeleteByValue()
{
	/*list->Push(VALUE_A);
	list->Push(VALUE_B);
	list->Push(VALUE_A);

	AssertEquals(3, list->GetSize());
	AssertEquals(VALUE_A, *list->GetItem(0));
	AssertEquals(VALUE_B, *list->GetItem(1));
	AssertEquals(VALUE_A, *list->GetItem(2));

	AssertTrue(list->Delete(VALUE_A));

	AssertEquals(2, list->GetSize());
	AssertEquals(VALUE_B, *list->GetItem(0));
	AssertEquals(VALUE_A, *list->GetItem(1));

	AssertTrue(list->Delete(VALUE_A));

	AssertEquals(1, list->GetSize());
	AssertEquals(VALUE_B, *list->GetItem(0));

	AssertFalse(list->Delete(VALUE_C));

	AssertEquals(1, list->GetSize());
	AssertEquals(VALUE_B, *list->GetItem(0));

	AssertTrue(list->Delete(VALUE_B));

	AssertEquals(0, list->GetSize());*/
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing Methods for Finding Values
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestIndexOf()
{
	list->Push(VALUE_A);
	list->Push(VALUE_B);
	list->Push(VALUE_A);
	
	AssertEquals( 0, list->FindItem(VALUE_A));
	AssertEquals( 1, list->FindItem(VALUE_B));
	AssertEquals(-1, list->FindItem(VALUE_C));
}

////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestContains()
{
	list->Push(VALUE_A);
	list->Push(VALUE_B);
	list->Push(VALUE_A);
	
	AssertTrue(list->ItemExist(VALUE_A));
	AssertTrue(list->ItemExist(VALUE_B));
	AssertFalse(list->ItemExist(VALUE_C));
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing What Happens When a List Is Cleared
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void LinkedListTest::TestClear()
{
	list->Push(VALUE_A);
	list->Push(VALUE_B);
	list->Push(VALUE_C);
	
	AssertFalse(list->IsEmpty());
	AssertEquals(3, list->GetSize());
	
	list->Clear();
	
	AssertTrue(list->IsEmpty());
	AssertEquals(0, list->GetSize());
}

////////////////////////////////////////////////////////////////////////////////////////////
// Run all the tests then print results...
////////////////////////////////////////////////////////////////////////////////////////////
void LinkedListTest::RunTests()
{
	ResetTestsResults();
	PrintTestName("LinkedList");

	RunTest(TestInsertIntoEmptyList,		"TestInsertIntoEmptyList");
	RunTest(TestInsertBetweenElements,		"TestInsertBetweenElements");
	RunTest(TestInsertBeforeFirstElement,	"TestInsertBeforeFirstElement");
	RunTest(TestInsertAfterLastElement,		"TestInsertAfterLastElement");
	RunTest(TestInsertOutOfBounds,			"TestInsertOutOfBounds");
	RunTest(TestAdd,						"TestAdd");
	RunTest(TestSet,						"TestSet");
	RunTest(TestGetOutOfBounds,				"TestGetOutOfBounds");
	RunTest(TestSetOutOfBounds,				"TestSetOutOfBounds");
	RunTest(TestDeleteOnlyElement,			"TestDeleteOnlyElement");
	RunTest(TestDeleteFirstElement,			"TestDeleteFirstElement");
	RunTest(TestDeleteLastElement,			"TestDeleteLastElement");
	RunTest(TestDeleteMiddleElement,		"TestDeleteMiddleElement");
	RunTest(TestDeleteOutOfBounds,			"TestDeleteOutOfBounds");
	RunTest(TestDeleteByValue,				"TestDeleteByValue");
	RunTest(TestIndexOf,					"TestIndexOf");
	RunTest(TestContains,					"TestContains");
	RunTest(TestClear,						"TestClear");

	PrintTestsResults();
}

#pragma warning(pop)
