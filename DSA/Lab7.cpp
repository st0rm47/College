// Write a recursive program to display the series of n number of fibonacci sequences.

#include <iostream>
using namespace std;

// Function to calculate fibonacci series using recursion
int fibo(int n)
{
    if (n <= 1)
        return n;
    else
        return (fibo(n - 1) + fibo(n - 2));
}
int main()
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  Fibonacci Calculator  " << endl;
    cout << "\t\t========================" << endl;

    int n, i;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    cout << "Fibonacci series:" << endl;
    for (i = 0; i < n; i++)
        cout << fibo(i) << "\t";
    return 0;
}
