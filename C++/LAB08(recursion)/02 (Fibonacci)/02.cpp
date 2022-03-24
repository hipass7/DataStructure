#include <iostream>
using namespace std;

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);
int main () {
    cout << Fibonacci_recursive(10) << endl;
    cout << Fibonacci_non_recursive(10) << endl;
    
    return 0;
}
// 재귀 버전이 더 비효율적이라고 생각합니다. 왜냐하면 이미 했던 계산을 또 반복해야하기 때문입니다.
// ex) n=3 일때, Fibonacci(1) + Fibonacci(2)를 return 해야하는데, Fibonacci(1)을 계산 했음에도 Fibonacci(2)를 계산하는 과정에서 Fibonacci(1)을 또 계산하게 됩니다.


int Fibonacci_recursive(int n){
    if (n == 0 || n == 1)
        return n;
    else if (n < 0)
        return 0;
    else
        return Fibonacci_recursive(n-2) + Fibonacci_recursive(n-1);
}

int Fibonacci_non_recursive(int n){
    if (n == 0 || n == 1)
        return n;
    else{
        int a = 0;
        int b = 1;
        int sum = 0;
        for (int i = 0; i < n-1; i++){
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
}
