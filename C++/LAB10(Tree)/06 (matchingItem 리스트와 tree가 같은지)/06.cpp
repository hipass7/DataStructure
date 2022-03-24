#include <iostream>
#include "TreeType.h"
#include "UnsortedType.h"
using namespace std;

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list) {
	int list_length = list.LengthIs();
	int tree_length = tree.LengthIs();

	if (list_length != tree_length)
		return false;
	else {
		ItemType item;
		bool found;

		list.ResetList();
		for (int i = 0; i < list_length; i++) {
			list.GetNextItem(item);
			tree.RetrieveItem(item, found);
			if (!found)
				return false;
		}
		return true;
	}
}

bool MatchingItem_Unsorted_test(TreeType& tree, UnsortedType<ItemType>& list) {
	ItemType item;
	bool found;

	tree.ResetTree(IN_ORDER);
	for (int i = 0; i < list.LengthIs(); i++) {
		tree.GetNextItem(item, IN_ORDER, found);
		list.RetrieveItem(item, found);
		if (!found)
			return false;
	}
	return true;
}

int main()
{
	UnsortedType<char> sl;
	TreeType tree;

	sl.InsertItem('g');
	sl.InsertItem('b');
	sl.InsertItem('k');
	sl.InsertItem('a');
	sl.InsertItem('e');
	sl.InsertItem('h');
	sl.InsertItem('z');

	tree.InsertItem('g');
	tree.InsertItem('b');
	tree.InsertItem('k');
	tree.InsertItem('a');
	tree.InsertItem('e');
	tree.InsertItem('h');
	tree.InsertItem('z');
	// tree.InsertItem('x');

	cout << MatchingItem_Unsorted(tree, sl) << endl;
	cout << MatchingItem_Unsorted_test(tree, sl);

	// �Ʒ� test ������ ���� �� �� ����ð� �鿡�� ���̰� �ִ�.
	// �� �Լ��� tree ����Լ����� ���� Ž���� �ϹǷ� O(logN)�� �ɸ�����, �Ʒ� �Լ��� list ����Լ����� ���� Ž���� �ϹǷ� O(N)�� �ɸ���.

	return 0;
}