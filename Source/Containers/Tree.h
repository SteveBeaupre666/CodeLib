#pragma once
//----------------------------------------------------------------------//
#include <Windows.h>
#include <stdio.h>
//----------------------------------------------------------------------//

template <class T> class Tree;

//-----------------------------------------------------------------------------
// Tree node
//-----------------------------------------------------------------------------
template <class T> class TreeNode {
public:
	typedef TreeNode<T> NODE;
public:
	TreeNode(){
		Prev = NULL;
		Next = NULL;
		Parent = NULL;
		FirstChild = NULL;
		ZeroMemory(&Data, sizeof(T));
	}
public:
	friend class Tree<T>;
	typedef TreeNode<T> NODE;
private:
	T Data;
	NODE *Next, *Prev, *Parent, *FirstChild;
public:
	T    Get(){return Data;}
	void Set(T dat){Data = dat;}

	NODE* GetParent(){return Parent;}
	NODE* GetPrev(){return Prev;}
	NODE* GetNext(){return Next;}

	UINT  GetChildsCount();
	NODE* GetFirstChild(){return FirstChild;}
	NODE* GetLastChild();

	bool HasPrev(){return Prev != NULL;}
	bool HasNext(){return Next != NULL;}
	bool HasParent(){return Parent != NULL;}
	bool HasChilds(){return FirstChild != NULL;}
	bool IsChildless(){return FirstChild == NULL;}
};

//-----------------------------------------------------------------------------
// Tree class
//-----------------------------------------------------------------------------
template <class T> class Tree {
public:
	Tree();
	~Tree();
public:
	typedef TreeNode<T> NODE;
private:
	void  Initialize();
protected:
	NODE  Root;
	int   NodesCount;
public:
	bool  IsEmpty();
	int   GetNodesCount();

	NODE* GetRootNode();
	NODE* AddChild(NODE* node, T &dat);
	NODE* AddSibling(NODE* node, T &dat);

	bool  DeleteNode(NODE* node);
	void  Clear();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T> TreeNode<T>* TreeNode<T>::GetLastChild()
{
	NODE* child = FirstChild;
	
	while(child){
		if(!child->Next){break;}
		child = child->Next;
	}
	
	return child;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// Constructor...
//-----------------------------------------------------------------------------
template <class T> Tree<T>::Tree()
{
	Initialize();
}

//-----------------------------------------------------------------------------
// Destructor...
//-----------------------------------------------------------------------------
template <class T> Tree<T>::~Tree()
{
	Clear();
}

//-----------------------------------------------------------------------------
// Initialise the class
//-----------------------------------------------------------------------------
template <class T> void Tree<T>::Initialize()
{
	NodesCount = 0;
}

//-----------------------------------------------------------------------------
// Return true if the tree is empty
//-----------------------------------------------------------------------------
template <class T> bool Tree<T>::IsEmpty()
{
	return NodesCount == 0;
}

//-----------------------------------------------------------------------------
// Return number of nodes allocated
//-----------------------------------------------------------------------------
template <class T> int Tree<T>::GetNodesCount()
{
	return NodesCount;
}

//-----------------------------------------------------------------------------
// Return the root node pointer
//-----------------------------------------------------------------------------
template <class T> TreeNode<T>* Tree<T>::GetRootNode()
{
	return &Root;
}

//-----------------------------------------------------------------------------
// Add a node as the last child of this node
//-----------------------------------------------------------------------------
template <class T> TreeNode<T>* Tree<T>::AddChild(NODE* node, T &dat)
{
	if(!node)
		return NULL;

	// Create a new node
	NODE* new_node = new NODE();

	// Set the node's data
	new_node->Set(dat);

	// Save last child pointer
	NODE* last_child = (NODE*)node->GetLastChild();
	
	// Set this node as first child of the newly created node...
	if(!node->FirstChild)
		node->FirstChild = new_node;

	// Update the new node's pointers
	new_node->Parent      = node;
	new_node->Prev        = last_child;
	new_node->Next        = NULL;
	new_node->FirstChild  = NULL;

	// Update the next pointer of the node to the "left"
	if(new_node->Prev)
		new_node->Prev->Next = new_node;

	// Update the next pointer of the node to the "right"
	if(new_node->Next)
		new_node->Next->Prev = new_node;

	// Increment nodes counter
	NodesCount++;

	return new_node;
}

//-----------------------------------------------------------------------------
// Add a node next to another one
//-----------------------------------------------------------------------------
template <class T> TreeNode<T>* Tree<T>::AddSibling(NODE* node, T &dat)
{
	// Don't add sibling to the root node...
	if(!node || !node->Parent)
		return NULL;

	// NOTE: THIS CODE IS WRONG!
	return AddChild(node->Parent, dat);
}

//-----------------------------------------------------------------------------
// Delete a node and it's childrens
//-----------------------------------------------------------------------------
template <class T> bool Tree<T>::DeleteNode(NODE* node)
{
	// Error handling...
	if(!node)
		return false;

	// Delete recursively each childs nodes of this node
	NODE* last_child = node->GetLastChild();
	while(last_child){
		DeleteNode(last_child);
		last_child = node->GetLastChild();
	}

	// Help for my sanity...
	NODE* parent    = node->Parent;
	NODE* prev_node = node->Prev;
	NODE* next_node = node->Next;

	// Update next/previous pointers, if any...
	if(prev_node){prev_node->Next = next_node;}
	if(next_node){next_node->Prev = prev_node;}	

	// If we're the only child left, update parent first child pointer
	if(parent && parent->FirstChild == node)
		parent->FirstChild = next_node;

	// Delete the node if this is not the root node
	bool IsRootNode = node == GetRootNode();
	if(!IsRootNode){
		delete node;
		NodesCount--;
	}
		
	return !IsRootNode;
}

//-----------------------------------------------------------------------------
// Delete the entire tree
//-----------------------------------------------------------------------------
template <class T> void Tree<T>::Clear()
{
	DeleteNode(&Root);
}

