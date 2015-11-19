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
	void AddLeaf(TreeNode leaf);
	void ClipLeaf(TreeNode leaf);

//OBSERVERS
//-------------------------------------------------------------
	void FetchLeaf(TreeNode leaf);
	void PrintTree();

private:
	TreeNode* root; //lol
};


#endif