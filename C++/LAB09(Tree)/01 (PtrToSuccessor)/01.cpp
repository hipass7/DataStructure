#include <iostream>
#include "TreeType.h"
using namespace std;

struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

int main()
{
	TreeType tree;

	tree.InsertItem('i');
	tree.InsertItem('b');
	tree.InsertItem('c');
	tree.InsertItem('f');
	tree.InsertItem('a');
	tree.InsertItem('t');
	tree.InsertItem('z');

	TreeNode* a = new TreeNode;
	TreeNode* b = new TreeNode;
	a = tree.PtrToSuccessor_a(tree.root);
	b = tree.PtrToSuccessor_b(tree.root);

	cout << a->info << endl;
	cout << b->info << endl;

}