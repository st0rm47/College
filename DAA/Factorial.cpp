#include<iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
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

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
    