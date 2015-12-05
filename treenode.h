#ifndef TREENODE
#define TREENODE

#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* left_child;
	TreeNode* right_child;
	void PrintNode() {
		cout << "Data: " << data << endl;
	}

};

#endif