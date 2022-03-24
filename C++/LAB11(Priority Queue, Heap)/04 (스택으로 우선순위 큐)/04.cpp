#include <iostream>
using namespace std;
#include "StackTType.h"

int main() {
	StackType<int> a;

	a.Push(5);
	a.Push(10);
	a.Push(7);
	a.Push(15);

	while (!a.IsEmpty()) {
		cout << a.Top() << endl;
		a.Pop();
	}

	return 0;
}