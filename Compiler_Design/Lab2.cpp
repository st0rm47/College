#include <iostream>
#include <string>
using namespace std;

int main() {
    string com;
    int a = 0;

    cout << "Enter comment: ";
    getline(cin, com);

    if (com.size() >= 2 && com[0] == '/') {
        if (com[1] == '/') {
            cout << "It is a comment" << endl;
        } 
        else if (com[1] == '*') {
            int i = 2;
            while (i < com.size() - 1) {
                if (com[i] == '*' && com[i + 1] == '/') {
                    cout << "It is a comment" << endl;
                    a = 1;
                    break;
                }
                i++;
            }
            if (a == 0)
                cout << "It is not a comment" << endl;
        } 
        else {
            cout << "It is not a comment" << endl;
        }
    } 
    else {
        cout << "It is not a comment" << endl;
    }
    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
