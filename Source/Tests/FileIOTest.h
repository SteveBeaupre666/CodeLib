#pragma once
//----------------------------------------------------------------------//
#include "GenericTest.h"
#include "FileIO.h"
//----------------------------------------------------------------------//

class FileIOTest : public GenericTest {
public:
	FileIOTest();
	virtual ~FileIOTest();
private:
	void Initialize();
public:
	void SetUp();
	void TearDown();
	void RunTests();
public:
	static void TestISOpened();
	static void TestOpenFile();
	static void TestCreateFile();
	static void TestCloseFile();

	static void TestReadFile();
	static void TestWriteFile();

	static void TestSeek();
	static void TestSeek64();

	static void TestGetSize();
	static void TestGetSize64();

	static void TestTell();
	static void TestTell64();

	static void TestFlush();
};


