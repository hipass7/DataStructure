#include <iostream>
using namespace std;

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);
int main () {
    cout << Fibonacci_recursive(10) << endl;
    cout << Fibonacci_non_recursive(10) << endl;
    
    return 0;
}
// ��� ������ �� ��ȿ�����̶�� �����մϴ�. �ֳ��ϸ� �̹� �ߴ� ����� �� �ݺ��ؾ��ϱ� �����Դϴ�.
// ex) n=3 �϶�, Fibonacci(1) + Fibonacci(2)�� return �ؾ��ϴµ�, Fibonacci(1)�� ��� �������� Fibonacci(2)�� ����ϴ� �������� Fibonacci(1)�� �� ����ϰ� �˴ϴ�.


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
