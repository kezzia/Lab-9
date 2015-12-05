#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

//CONSTRUCTOR
//-------------------------------------------------------------
Tree::Tree() {
	root = NULL;
	cout << "Root is NULL\n";
}

Tree::~Tree() {
	delete root;
}

//TRANSFORMERS
//-------------------------------------------------------------
void Tree::	void AddLeaf(TreeNode*& root, int item) {
	if (root == NULL) {
		//leaf becomes root
		root = new TreeNode;
		root->left_child = NULL;
		root->right_child = NULL;
		root->data = item;
	}
	else if (item > root->data) {
		AddLeaf(root->right_child, item);
	}
	else {
		AddLeaf(root->left_child, item);
	}
}
/*
void Tree::ClipLeaf(TreeNode*& tree, int item) {
	if (item > tree->data)
		ClipLeaf(tree->right_child, item);
	else if (item < tree->data) 
		ClipLeaf(tree->left_child, item);
	else 
		delete tree;
	//pass
}

//OBSERVERS
//-------------------------------------------------------------
void Tree::GetItem(int& item, bool& found) {
//Self explanatory. Gets specified item, returns false if item was not found
	Retrieve(tree, item, found);
}

void Tree::Retrieve(TreeNode* tree, int& item, bool& found) {
	if (tree == NULL)
		found = false;
	else if (item < tree->data) 
		Retrieve(tree->left_child, item, found);
	else if (item > tree->data)
		Retrieve(tree->right_child, item, found);
	else {
		item = tree->data;
		found = true;
	}

}

bool Tree::IsFull() {
//returns true if there is no more memory space for tree nodes
	TreeNode* location;

	try {
		location = new TreeNode;
		delete location;
		return false;
	}

	catch(std::bad_alloc exception) {
		return true;
	} 
}

bool Tree::IsEmpty() {
//returns true if root points at nothing
	return (tree == NULL);
}

*/

void Tree::InOrder() {
	tree->PrintNode();
	//pre order
	//post order
	//In Order
}

