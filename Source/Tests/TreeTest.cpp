#include "TreeTest.h"

#pragma warning(push)
#pragma warning(disable:4101)

int TREE_VALUE_A = 0;
int TREE_VALUE_B = 1;
int TREE_VALUE_C = 2;

Tree<int> *tree = NULL;

////////////////////////////////////////////////////////////////////////////////////////////
// Constructor...
////////////////////////////////////////////////////////////////////////////////////////////
TreeTest::TreeTest()
{
	Initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Destructor...
////////////////////////////////////////////////////////////////////////////////////////////
TreeTest::~TreeTest()
{
	TearDown();
}

////////////////////////////////////////////////////////////////////////////////////////////
// Initialize the obect's pointer
////////////////////////////////////////////////////////////////////////////////////////////
void TreeTest::Initialize()
{
	tree = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Create a new object for each tests we do
////////////////////////////////////////////////////////////////////////////////////////////
void TreeTest::SetUp()
{
	TearDown();
	tree = new Tree<int>;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Free the object after each tests we do
////////////////////////////////////////////////////////////////////////////////////////////
void TreeTest::TearDown()
{
	SAFE_DELETE_OBJECT(tree);
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
// Testing Methods for Inserting and Adding Values
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

void TreeTest::TestTree1Level()
{
	AssertTrue(tree->IsEmpty());
	AssertEquals(tree->GetNodesCount(), 0);

	TreeNode<int>* root = tree->GetRootNode();
	TreeNode<int>* node = root;

	TreeNode<int>* child_1 = tree->AddChild(node, TREE_VALUE_A);
	TreeNode<int>* child_2 = tree->AddChild(node, TREE_VALUE_B);
	TreeNode<int>* child_3 = tree->AddChild(node, TREE_VALUE_C);

	AssertEquals(child_1->Get(), TREE_VALUE_A);
	AssertEquals(child_2->Get(), TREE_VALUE_B);
	AssertEquals(child_3->Get(), TREE_VALUE_C);

	AssertEquals(root->GetFirstChild(), child_1);

	AssertEquals(child_1, node->GetFirstChild());
	AssertEquals(child_2, child_1->GetNext());
	AssertEquals(child_3, child_2->GetNext());

	AssertEquals(child_1->GetParent(), root);
	AssertEquals(child_2->GetParent(), root);
	AssertEquals(child_3->GetParent(), root);

	AssertEquals(child_1->GetFirstChild(), NULL);
	AssertEquals(child_2->GetFirstChild(), NULL);
	AssertEquals(child_3->GetFirstChild(), NULL);

	AssertEquals(child_1->GetPrev(), NULL);
	AssertEquals(child_2->GetPrev(), child_1);
	AssertEquals(child_3->GetPrev(), child_2);

	AssertEquals(child_1->GetNext(), child_2);
	AssertEquals(child_2->GetNext(), child_3);
	AssertEquals(child_3->GetNext(), NULL);

	tree->Clear();
	AssertEquals(tree->GetNodesCount(), 0);
	AssertTrue(tree->IsEmpty());
}

////////////////////////////////////////////////////////////////////////////////////////////

void TreeTest::TestTree3Level()
{
	TreeNode<int>* root = tree->GetRootNode();
	TreeNode<int>* node = root;

	int value = 0;
	TreeNode<int>* child_1 = tree->AddChild(node, value); value++;
	TreeNode<int>* child_2 = tree->AddChild(node, value); value++;
	TreeNode<int>* child_3 = tree->AddChild(node, value); value++;

	TreeNode<int>* child_11 = tree->AddChild(child_1, value); value++;
	TreeNode<int>* child_12 = tree->AddChild(child_1, value); value++;
	TreeNode<int>* child_13 = tree->AddChild(child_1, value); value++;

}

////////////////////////////////////////////////////////////////////////////////////////////
// Run all the tests then print results...
////////////////////////////////////////////////////////////////////////////////////////////
void TreeTest::RunTests()
{
	ResetTestsResults();
	PrintTestName("Tree");

	RunTest(TestTree1Level, "TestTree1Level");
	RunTest(TestTree3Level, "TestTree3Level");

	PrintTestsResults();
}

#pragma warning(pop)
