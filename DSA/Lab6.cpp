#include<iostream>
using namespace std;
int facto(int n){
    if (n<=1)
        return 1;
    else
        return (n*facto(n-1));
}
int main(){
    int n;
    cout << "Enter a number:" ;
    cin >> n;
    cout << "Factorial of " << n << " is " << facto(n) << endl;
    return 0;
}
