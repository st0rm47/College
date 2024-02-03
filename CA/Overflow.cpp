#include <iostream>
using namespace std;

int main() {
    int n1, n2, sum;
    cout << "Enter two numbers:" << endl;
    cin >> n1 >> n2;

    sum = n1 + n2;
    cout << "The sum is " << sum << endl;

    int AS, BS, RS;
    AS = (n1 >> 3) & 1;
    BS = (n2 >> 3) & 1;
    RS = (sum >> 3) & 1;

    if ((AS == BS && AS == RS) || (AS != BS)){
        cout << "NO OVERFLOW!!!" << endl;
    } else {
        cout << "OVERFLOW!!!" << endl;
    }
    return 0;
}
