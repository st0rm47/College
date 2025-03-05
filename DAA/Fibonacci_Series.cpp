#include <iostream>
using namespace std;

int fibo(int n) {
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;

    int first = 0, second = 1;
    for (int i = 2; i <= n; i++) {
        int temp = first + second;
        first = second;
        second = temp;
    }
    return second;
}

int main() {
    cout << "\t\t======================" << endl;
    cout << "\t\t  Fibonacci Sequence  " << endl;
    cout << "\t\t======================" << endl;
    
    int i, n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    cout << "Fibonacci series:" << endl;
    for (i = 0; i < n; i++)
        cout << fibo(i) << "\t";

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
