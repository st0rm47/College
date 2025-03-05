#include <iostream>
using namespace std;

// Function to calculate the nth term of the Fibonacci sequence using recursion
int fibo(int n) 
{
    if (n <= 1)
        return n;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main() 
{
    cout << "\t\t======================" << endl;
    cout << "\t\t  Fibonacci Sequence  " << endl;
    cout << "\t\t======================" << endl;
    
    int i,n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    cout << "Fibonacci series:" << endl;
    for (i = 0; i < n; i++)
        cout << fibo(i) << "\t";

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
