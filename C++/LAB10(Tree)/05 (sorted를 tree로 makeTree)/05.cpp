#include <iostream>
#include "TreeType.h"
#include "SortedType.h"
using namespace std;

void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int>& list) {
	int length = list.LengthIs();
	int* array = new int[length];
	int item_info;
	int i;

	list.ResetList();

	for (i = 0; i < length; i++) {
		list.GetNextItem(item_info);
		array[i] = item_info;
	}

	AddElement(tree, array, 0, length - 1);
	delete[] array;
}

void AddElement(TreeType& tree, int Array[], int front, int rear) {
	int mid;
	if (front <= rear) {
		mid = (front + rear) / 2;
		tree.InsertItem(Array[mid]);
		AddElement(tree, Array, mid + 1, rear);
		AddElement(tree, Array, front, mid - 1);
	}
} // 그냥 넣으면 한쪽으로만 치우친 tree가 되기 때문에 안됨

int main()
{
	SortedType<int> sl;
	TreeType tree;

	sl.InsertItem(1);
	sl.InsertItem(2);
	sl.InsertItem(3);
	sl.InsertItem(4);
	sl.InsertItem(5);
	sl.InsertItem(6);
	sl.InsertItem(7);

	MakeTree(tree, sl);

	tree.ResetTree(IN_ORDER);

	ItemType item;
	bool finished;
	for (int i = 0; i < 7; i++) {
		tree.GetNextItem(item, IN_ORDER, finished);
		cout << item << endl;
	}

	return 0;
}