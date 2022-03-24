#pragma once
#include "Student.h"

void BubbleUp(Student values[], int startIndex, int endIndex) {

	for (int index = endIndex; index > startIndex; index--) {

		if (strcmp(values[index].getName(), values[index - 1].getName()) < 0)
			Swap(values[index], values[index - 1]);
	}
}

void BubbleSort(Student values[], int numValues) {
	int current = 0;

	while (current < numValues - 1)
	{
		BubbleUp(values, current, numValues - 1);
		current++;
	}
}

void Swap(Student& item1, Student& item2)
// Post: Contents of item1 and item2 have been swapped.
{
	Student tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}
