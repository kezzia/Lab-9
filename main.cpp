#include "treenode.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	TreeNode a_tree;
	a_tree.data = 5;
	a_tree.left_child = NULL;
	a_tree.right_child = NULL;

	cout << "Enter a value";
	int new_val;
	cin >> new_val;

	if (new_val <= a_tree.data)
		a_tree.left_child = new_val;
	else
		a_tree.right_child = new_val;
	
	return 0;
}