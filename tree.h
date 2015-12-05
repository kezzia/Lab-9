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
	void AddLeaf(int item);
	void AddLeaf(TreeNode*& root, int item);	//to-do
	void ClipLeaf(int item);
	void ClipLeaf(TreeNode*& root, int item);	//to-do
	void DeleteNode(TreeNode*& root);
	void GetPredecessor(TreeNode*& root, int& data);

//OBSERVERS
//-------------------------------------------------------------
	void GetAncestors(int& item);	//to-do
	void GetItem(int& item, bool& found);	//to-do
	void GetAncestors(int& item, TreeNode* root, TreeNode* node_ptr, TreeNode* parent_ptr);
	void Retrieve(TreeNode* root, int& item, bool& found);
	bool IsFull();
	bool IsEmpty();

	void InOrder();
	void InOrder(TreeNode*& root);

	void PreOrder();
	void PreOrder(TreeNode*& root);

	void PostOrder();
	void PostOrder(TreeNode*& root);


private:
	TreeNode* root; 				//points at root
	TreeNode* current_node;
};


#endif