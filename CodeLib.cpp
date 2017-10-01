#include "CodeLib.h"

#define RUN_BUFFER_TEST
//#define RUN_LIST_TEST
//#define RUN_TREE_TEST

int main()
{
	#ifdef RUN_BUFFER_TEST
	BufferTest BufferTester;
	BufferTester.RunTests();
	#endif

	#ifdef RUN_BUFFER_TEST
	LinkedListTest LinkedListTester;
	LinkedListTester.RunTests();
	#endif

	#ifdef RUN_BUFFER_TEST
	TreeTest TreeTester;
	TreeTester.RunTests();
	#endif

	system("PAUSE");

	return 0;
}

