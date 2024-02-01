// Write a recursive program to display the series of n number of fibonacci sequences.

#include<iostream>
using namespace std;

int fibo(int n)
{
    if (n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return(fibo(n-1)+fibo(n-2));
}

int main()
{
    int n,i;
    cout << "Enter a number:";
    cin >> n;
    cout << "Fibonacci series:" << endl;
    for(i=0;i<n;i++)
        cout << fibo(i) << "\t" ;
    return 0;
}
