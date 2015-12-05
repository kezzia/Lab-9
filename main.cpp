#include "treenode.h"
#include "tree.h"
#include "mainfunctions.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
	Tree *tree = new Tree;
	PopulateTree(tree);
	AskForOrder(tree);
	AskToAdd(tree);
	AskToClip(tree);
	AskToFindAncestor(tree);



	
	return 0;
}