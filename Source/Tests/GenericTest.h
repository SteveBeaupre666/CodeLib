#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//
#include "Assertion.h"
#include "Exceptions.h"
//----------------------------------------------------------------------//
#include "SafeKill.h"
//----------------------------------------------------------------------//

#define THROW_TEST_FAILED throw "Test Failed"

typedef void (__cdecl * PFN_TEST)();

class GenericTest {
public:
	GenericTest();
	virtual ~GenericTest(){}
private:
	int  NumTestsDone;
	int  NumTestsFailed;
	int  NumTestsPassed;

	void OnTestFailed(char *pTestName);
	void OnTestPassed(char *pTestName);

	void OnFailure(char *pTestName);
	void OnSuccess(char *pTestName);
protected:
	virtual void SetUp()      = 0;
	virtual void TearDown()   = 0;
	virtual void Initialize() = 0;
	virtual void RunTests()   = 0;
public:
	int  GetNumTestsDone();
	int  GetNumTestsFailed();
	int  GetNumTestsPassed();
	
	void ResetTestsResults();
	void PrintTestsResults();

	void PrintTestName(char* name);
	void RunTest(void *pTestFunc, char *pTestName);
};