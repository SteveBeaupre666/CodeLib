#pragma once
//----------------------------------------------------------------------//
#include "GenericTest.h"
#include "TxtFile.h"
//----------------------------------------------------------------------//

class TxtFileTest : public GenericTest {
public:
	TxtFileTest();
	virtual ~TxtFileTest();
private:
	void Initialize();
public:
	void SetUp();
	void TearDown();
	void RunTests();
public:
	//static void Test();
};


