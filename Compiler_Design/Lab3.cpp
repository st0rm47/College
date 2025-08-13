#include <iostream>
#include <string>
using namespace std;

void recognize_string(string s) {
    int state = 0;
    int i = 0;
    char c;

    while (i < s.length()) {
        c = s[i];
        i++;

        switch (state) {
            case 0:
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else state = 6;
                break;

            case 1:
                if (c == 'a') state = 3;
                else if (c == 'b') state = 4;
                else state = 6;
                break;

            case 2:
                if (c == 'a') state = 6;
                else if (c == 'b') state = 2;
                else state = 6;
                break;

            case 3:
                if (c == 'a') state = 3;
                else if (c == 'b') state = 2;
                else state = 6;
                break;

            case 4:
                if (c == 'a') state = 6;
                else if (c == 'b') state = 5;
                else state = 6;
                break;

            case 5:
                if (c == 'a') state = 6;
                else if (c == 'b') state = 2;
                else state = 6;
                break;

            case 6:
                cout << s << " is not recognized" << endl;
                return;
        }
    }

    if (state == 1 || state == 3)
        cout << s << " is accepted under rule 'a*'" << endl;
    else if (state == 2 || state == 4)
        cout << s << " is accepted under rule 'a*b+'" << endl;
    else if (state == 5)
        cout << s << " is accepted under rule 'abb'" << endl;
    else
        cout << s << " is not recognized" << endl;
}

int main() {
    string input_string;
    cout << "Enter a string: ";
    getline(cin, input_string);

    recognize_string(input_string);

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
