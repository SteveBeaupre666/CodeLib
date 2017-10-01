#pragma once
//----------------------------------------------------------------------//
#include "GenericTest.h"
#include "LinkedList.h"
//----------------------------------------------------------------------//

class LinkedListTest : public GenericTest {
public:
	LinkedListTest();
	virtual ~LinkedListTest();
private:
	void Initialize();
	void SetUp();
	void TearDown();
public:
	void RunTests();
public:
	static void TestInsertIntoEmptyList();
	static void TestInsertBetweenElements();
	static void TestInsertBeforeFirstElement();
	static void TestInsertAfterLastElement();
	static void TestInsertOutOfBounds();
	static void TestAdd();

	static void TestSet();
	static void TestGetOutOfBounds();
	static void TestSetOutOfBounds();

	static void TestDeleteOnlyElement();
	static void TestDeleteFirstElement();
	static void TestDeleteLastElement();
	static void TestDeleteMiddleElement();
	static void TestDeleteOutOfBounds();
	static void TestDeleteByValue();

	static void TestIndexOf();
	static void TestContains();

	static void TestClear();
};


