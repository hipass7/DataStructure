#include <iostream>
#include "TreeType.h"
using namespace std;

int main()
{
	TreeType tree;

	tree.InsertItem('k');
	tree.InsertItem('d');
	tree.InsertItem('o');
	tree.InsertItem('a');
	tree.InsertItem('m');
	tree.InsertItem('x');
	tree.InsertItem('l');
	tree.InsertItem('w');

	tree.ResetTree(IN_ORDER);

	tree.Ancestors('x');

	return 0;
}