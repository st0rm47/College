//WAP to calculate factorial of a number using recursion.

#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int factorial(int n) 
{
    if (n <=1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main() 
{  
    cout << "\t\t========================" << endl;
    cout << "\t\t  Factorial Calculator  " << endl;
    cout << "\t\t========================" << endl;
    
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;

    if (num < 0)
        cout << "Factorial is not defined for negative numbers." << endl;
    else
        cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
