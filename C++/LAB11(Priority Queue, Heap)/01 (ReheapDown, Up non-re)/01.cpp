#include <iostream>
using namespace std;
#include "PQType.h"

int main() {
	PQType<int> pq(16);

	pq.Enqueue(56);
	pq.Enqueue(25);
	pq.Enqueue(24);
	pq.Enqueue(5);
	pq.Enqueue(15);
	pq.Enqueue(26);

	while (!pq.IsEmpty()) {
		int temp;
		pq.Dequeue(temp);
		cout << temp << " ";
	}
	return 0;
}