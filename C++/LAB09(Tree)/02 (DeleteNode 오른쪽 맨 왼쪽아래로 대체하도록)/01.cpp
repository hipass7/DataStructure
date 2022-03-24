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
	tree.InsertItem('f');
	tree.InsertItem('x');
	tree.InsertItem('v');

	tree.DeleteItem('o');
	// tree.DeleteItem('k'); �� �׽�Ʈ�� �ϸ� ���� DeleteItem���� �����ڰ� �ƴ� �߰� �����ڸ� ����ϵ��� �ߴٴ� ���� �� �� �ִ�.

	tree.ResetTree(IN_ORDER);
	
	ItemType item;
	bool finished;
	for (int i = 0; i < 6; i++) {
		tree.GetNextItem(item, IN_ORDER, finished);
		cout << item << endl;
	}

	return 0;
}