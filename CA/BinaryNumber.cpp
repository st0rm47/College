#include<iostream>
using namespace std;
void binary(int a){
    for(int i = 3; i >= 0; i--){
        int k = (a >> i) & 1;
        cout << k;
    }
}
int main(){
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    cout << "The hex equivalent is: " << hex << n << endl;
    cout << "The binary equivalent is: " ;
    binary(n);
    cout << endl;

    cout << "The 1's complement is: ";
    binary(-n - 1);
    cout << endl;

    cout << "The 2's complement is: ";
    binary(-n);
    return 0;
}