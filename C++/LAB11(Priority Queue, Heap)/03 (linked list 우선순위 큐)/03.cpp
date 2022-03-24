#include <iostream>
using namespace std;
#include "PQType.h"

int main() {
	PQType<int> pq;

	pq.Enqueue(56);
	pq.Enqueue(27);
	pq.Enqueue(42);
	pq.Enqueue(26);
	pq.Enqueue(15);
	pq.Enqueue(3);
	pq.Enqueue(19);
	pq.Enqueue(25);
	pq.Enqueue(24);
	pq.Enqueue(5);

	while (!pq.IsEmpty()) {
		int temp;

		pq.Dequeue(temp);

		cout << temp << ' ';
	}

	return 0;
}