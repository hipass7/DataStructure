#include <iostream>
#include "SelectionSort.h"
#include "Student.h"
using namespace std;

int main()
{
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"�̿���", 3.0);
	stu[1].InitValue(2004200121, (char*)"�ǿ���", 3.2);
	stu[2].InitValue(2005200131, (char*)"������", 2.7);

	SelectionSort(stu, 3);
	Print(cout, stu, 3);
	return 0;

}