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

	// 아래 test 구현과 비교해 볼 때 수행시간 면에서 차이가 있다.
	// 위 함수는 tree 멤버함수에서 이진 탐색을 하므로 O(logN)이 걸리지만, 아래 함수는 list 멤버함수에서 순차 탐색을 하므로 O(N)이 걸린다.

	return 0;
}