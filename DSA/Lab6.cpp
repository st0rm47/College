#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int facto(int n)
{
    if (n <= 1)
        return 1;
    else
        return (n * facto(n - 1));
}
int main()
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  Factorial Calculator  " << endl;
    cout << "\t\t========================" << endl;

    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0)
        cout << "Factorial is not defined for negative numbers." << endl;
    else
        cout << "Factorial of " << n << " is " << facto(n) << endl;
    return 0;
}
