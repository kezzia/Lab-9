#include "tree.h"
#include "treenode.h"
#include "mainfunctions.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void PopulateTree(Tree*& tree) {
	ifstream myfile;
	myfile.open("integers.txt");
	int new_int;

	while( !myfile.eof() ) {
		myfile >> new_int;
		tree->AddLeaf(new_int);
	}
	tree->InOrder();
}

void AskForOrder(Tree*& tree) {
	bool valid = true;
	int response = 0;

	do {
		cout << "In what order would you like to print the stack?\n";
		cout << "  1. IN ORDER\n";
		cout << "  2. PRE ORDER\n";
		cout << "  3. POST ORDER\n";
		cout << "  4. ALL\n\n";

		cin >> response;

		if (response == 1)
			tree->InOrder();
		else if (response == 2)
			tree->PreOrder();
		else if (response == 3)
			tree->PostOrder();
		else if (response == 4) {
			tree->InOrder();
			tree->PreOrder();
			tree->PostOrder();
		}
		else {
			cout << "Invalid input\n\n";
			valid = false;
		}
	}while(valid == false);
}

void AskToAdd(Tree*& tree) {
	int value;
	cout << "Add a value to the tree: ";
	cin >> value;
	tree->AddLeaf(value);

	tree->InOrder();
}

void AskToClip(Tree*& tree) {
	int value;
	cout << "Clip a value from the tree: ";
	cin >> value;
	tree->ClipLeaf(value);
	tree->InOrder();
}

void AskToFindAncestor(Tree*& tree) {
	int value;
	cout << "Find ancestor of what item? ";
	cin >> value;
	tree->GetAncestors(value);

}