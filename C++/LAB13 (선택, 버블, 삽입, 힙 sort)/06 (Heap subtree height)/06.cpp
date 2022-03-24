#include <iostream>
#include "HeapSort.h"
using namespace std;

int main()
{
	int stu[100];
	stu[0] = 25;
	stu[1] = 17;
	stu[2] = 36;
	stu[3] = 2;
	stu[4] = 3;
	stu[5] = 100;
	stu[6] = 1;
	stu[7] = 19;
	stu[8] = 7;

	HeapSort(stu, 9);

	GetHeigthSum(stu, 9);
	cout << "Root Heights " << GetHeight(stu, 0, 9) << endl;

	return 0;
}