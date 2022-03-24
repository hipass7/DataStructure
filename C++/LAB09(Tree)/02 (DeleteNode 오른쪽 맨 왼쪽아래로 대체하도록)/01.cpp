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
	// tree.DeleteItem('k'); 로 테스트를 하면 기존 DeleteItem에서 전임자가 아닌 중간 후임자를 사용하도록 했다는 것을 알 수 있다.

	tree.ResetTree(IN_ORDER);
	
	ItemType item;
	bool finished;
	for (int i = 0; i < 6; i++) {
		tree.GetNextItem(item, IN_ORDER, finished);
		cout << item << endl;
	}

	return 0;
}