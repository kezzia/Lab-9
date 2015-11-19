#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

//CONSTRUCTOR
//-------------------------------------------------------------
Tree::Tree() {
	root->left_child = NULL;
	root->right_child = NULL;
}

//TRANSFORMERS
//-------------------------------------------------------------
void Tree::AddLeaf(TreeNode leaf) {
	//pass
}

void Tree::ClipLeaf(TreeNode leaf) {
	//pass
}

//OBSERVERS
//-------------------------------------------------------------
void Tree::FetchLeaf(TreeNode leaf) {
	//pass
}

bool Tree::IsFull() {
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
	return (root == NULL);
}

void Tree::PrintTree() {
	//pass
}
