// Write a recursive program to print the GCD of two given integers.

#include <iostream>
using namespace std;

// Function to solve GCD
int GCD(int a, int b) {
    if (b == 0) 
        return a;
    else
        return GCD(b, a % b);
}

int main()
{
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    if(num1>num2)
        cout << "The GCD of " << num1 << " and " << num2 << " is: " << GCD(num1, num2) << endl;
    else
        cout << "Error! Divisor is larger than the Dividend"<< endl;
    return 0;
}