#ifndef TREE
#define TREE

#include "treenode.h"
#include <iostream>
#include <string>
using namespace std;

class Tree
{
public:
//CONSTRUCTOR
//-------------------------------------------------------------
	Tree();
	~Tree();

//TRANSFORMERS
//-------------------------------------------------------------	
	void AddLeaf(TreeNode*& root, int item);	//to-do
	void ClipLeaf(TreeNode*& tree, int item);	//to-do

//OBSERVERS
//-------------------------------------------------------------
	void GetItem(int& item, bool& found);	//to-do
	void Retrieve(TreeNode* tree, int& item, bool& found);
	bool IsFull();
	bool IsEmpty();
	void InOrder();				//to-do
	TreeNode* GetRoot();

private:
	TreeNode* root; 				//points at root
};


#endif