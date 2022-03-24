#pragma once
#include "Student.h"

int MinIndex(Student values[], int startIndex, int endIndex) {
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
	{

		if (strcmp(values[index].getName(), values[indexOfMin].getName()) < 0)
		// if (values[index].getName() < values[indexOfMin].getName())
			indexOfMin = index;
	}

	return indexOfMin;
}

void SelectionSort(Student values[], int numValues) {

	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
		Swap(values[current], values[MinIndex(values, current, endIndex)]);
}

void Swap(Student& item1, Student& item2)
// Post: Contents of item1 and item2 have been swapped.
{
	Student tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}