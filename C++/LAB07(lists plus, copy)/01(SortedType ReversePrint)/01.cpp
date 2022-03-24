#include <iostream>
using namespace std;
#include "SortedType.h"

int main() {
	SortedType<char> test;
	test.InsertItem('Z');
	test.InsertItem('X');
	test.InsertItem('Y');

	test.PrintReverse();
}