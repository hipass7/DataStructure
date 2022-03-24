#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main() {
	UnsortedType<int> test;

	test.InsertItem(4);
	test.InsertItem(1);
	test.InsertItem(7);
	test.InsertItem(5);
	// Sort 함수를 InsertItem 함수 내에 포함

	test.ResetList();

	int temp;
	for (int i = 0; i < test.LengthIs(); i++) {

		test.GetNextItem(temp);
		cout << temp << endl;
	}

	return 0;
}