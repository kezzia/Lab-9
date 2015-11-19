#ifndef TREENODE
#define TREENODE

#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
public:
	int data;
	TreeNode* left_child;
	TreeNode* right_child;

};

#endif