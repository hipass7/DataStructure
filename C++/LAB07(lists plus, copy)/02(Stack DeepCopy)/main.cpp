#include <iostream>
using namespace std;
#include "StackType.h"

int main() {
 
    StackType stackA, stackB, stackC;
	
    stackA.Push(1);
    stackA.Push(2);
    cout << "A : ";
    stackA.Print();
    cout << endl;
	
    stackA.Pop();
    
    stackA.Push(3);
    stackA.Push(4);

    cout << "A : ";
    stackA.Print();
    cout << endl;

    stackC.Copy(stackA);
    stackB.Copy(stackA);

    
    stackA.Pop();
    stackA.Pop();

    cout << "A : ";
    stackA.Print();
    cout << endl;
    cout << "B : ";
    stackB.Print();
    cout << endl;
    cout << "C : ";
    stackC.Print();
    cout << endl;

    return 0;
}