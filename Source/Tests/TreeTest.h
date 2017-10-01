#pragma once
//----------------------------------------------------------------------//
#include "GenericTest.h"
#include "Tree.h"
//----------------------------------------------------------------------//

class TreeTest : public GenericTest {
public:
	TreeTest();
	virtual ~TreeTest();
private:
	void Initialize();
	void SetUp();
	void TearDown();
public:
	void RunTests();

	static void TestTree1Level();
	static void TestTree3Level();
};


