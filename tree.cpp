#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

//CONSTRUCTOR
//-------------------------------------------------------------
Tree::Tree() {
	root = NULL;
	current_node = NULL;
}

Tree::~Tree() {
	delete root;
}

//TRANSFORMERS
//-------------------------------------------------------------
void Tree::AddLeaf(int item) {
    return AddLeaf( root, item );
}

void Tree::AddLeaf(TreeNode*& root, int item) {
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



















void Tree::ClipLeaf(int item) {
	//removes leaf from tree
    return ClipLeaf( root, item );
}


void Tree::ClipLeaf(TreeNode*& root, int item) {
	//helper function. removes leaf from tree
	bool found = false;
	GetItem(item, found);
	if (found == true) {
		if (item > root->data)
			ClipLeaf(root->right_child, item);
		else if (item < root->data) 
			ClipLeaf(root->left_child, item);
		else 
			DeleteNode(root);
	}
}

void Tree::DeleteNode(TreeNode*& root) {
	int predecessor;
	TreeNode* tmp_ptr;

	tmp_ptr = root;
	if(root->left_child == NULL) {
		root = root->right_child;
		delete tmp_ptr;
	}
	else if(root->right_child == NULL) {
		root = root->left_child;
		delete tmp_ptr;
	}
	else {
		GetPredecessor(root->left_child, predecessor);
		root->data = predecessor;
		ClipLeaf(root->left_child, predecessor); //deleting predecessor
	}
}

void Tree::GetPredecessor(TreeNode*& root, int& predecessor) {
//gets the item furthest to the right
	while (root->right_child != NULL) {
		root = root->right_child;
	}
	predecessor = root->data;
}





















//OBSERVERS
//-------------------------------------------------------------
void Tree::GetAncestors(int& item) {
//Self explanatory. Gets specified item, returns false if item was not found
	TreeNode *node_ptr;
	TreeNode *parent_ptr;

	GetAncestors(item, root, node_ptr, parent_ptr);
}


void Tree::GetAncestors(int& item, TreeNode* root, TreeNode* node_ptr, TreeNode* parent_ptr)
{
	node_ptr = root;
	parent_ptr = NULL;
	bool found = false;

	cout << "Finding ancestors: \n";
	while ( (node_ptr != NULL) && (!found) ) {
		if (item < node_ptr->data) {
			parent_ptr = node_ptr;
			parent_ptr->PrintNode();
			node_ptr = node_ptr->left_child;
		}
		else if (item > node_ptr->data) {
			parent_ptr = node_ptr;
			parent_ptr->PrintNode();
			node_ptr = node_ptr->right_child;
		}
		else
			found = true;
	}

}

void Tree::GetItem(int& item, bool& found) {
//Self explanatory. Gets specified item, returns false if item was not found
	Retrieve(root, item, found);
}

void Tree::Retrieve(TreeNode* root, int& item, bool& found) {
	if (root == NULL) {
		cout << "Item not found!\n";
		found = false;
	}
	else if (item < root->data) {
		Retrieve(root->left_child, item, found);
	}
	else if (item > root->data)
		Retrieve(root->right_child, item, found);
	else {
		cout << "Item found!\n";
		item = root->data;
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
	return (root == NULL);
}


void Tree::InOrder() {
	cout << "Printing InOrder: \n";
	return InOrder( root );
}

void Tree::InOrder(TreeNode*& root) {
  	if (root != NULL) {
  		InOrder(root->left_child);
  		root->PrintNode();
  		InOrder(root->right_child);
  	}
}

void Tree::PreOrder() {
	cout << "\nPrinting PreOrder: \n";
	return PreOrder( root );
}

void Tree::PreOrder(TreeNode*& root) {
  	if (root != NULL) {
  		root->PrintNode();
  		InOrder(root->left_child);
  		InOrder(root->right_child);
  	}
}

void Tree::PostOrder() {
	cout << "\nPrinting PostOrder: \n";
	return PostOrder( root );
}

void Tree::PostOrder(TreeNode*& root) {
  	if (root != NULL) {
  		InOrder(root->left_child);
  		InOrder(root->right_child);
  		root->PrintNode();
  	}
}