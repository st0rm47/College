#include <iostream>
#include <string>
using namespace std;

bool dfa(const string &s) {
    int state = 0;
    for (char c : s) {
        if (state == 0) {
            if (c == 'a') 
                state = 1;
            else if (c == 'b') 
                state = 0;
        }
        else if (state == 1) {
            if (c == 'a') 
                state = 1;
            else if (c == 'b') 
                state = 2;
        }
        else if (state == 2) {
            if (c == 'a') 
                state = 1;
            else if (c == 'b') 
                state = 0;
        }
    }
    return state == 2;
}

int main() {
    string input_string;
    cout << "Enter a string: ";
    getline(cin, input_string);

    if (dfa(input_string))
        cout << "String is accepted (ends with 'ab')" << endl;
    else
        cout << "String is rejected" << endl;

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
