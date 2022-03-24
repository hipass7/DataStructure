#include <iostream>
#include "TreeType.h"
using namespace std;



int main() {
	TreeType tree;

	tree.InsertItem('6');
	tree.InsertItem('3');
	tree.InsertItem('8');
	tree.InsertItem('2');
	tree.InsertItem('7');

	if (tree.IsBST()) {
		cout << "The Tree is a BST" << endl;
	}
	else {
		cout << "Tree is is not a BST" << endl;
	}

	return 0;
}