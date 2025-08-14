#include <iostream>
#include <string>
using namespace std;

int main() {
    string identifier;
    int flag = 1, i = 1;

    cout << "Enter an identifier: ";
    getline(cin, identifier);

    // Check if first character is a letter or underscore
    if (isalpha(identifier[0]) || identifier[0] == '_')
        flag = 1;
    else {
        flag = 0;
    }

    // Check remaining characters
    while (i < identifier.length()) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            flag = 0;
            break;
        }
        i++;
    }

    if (flag == 1)
        cout << "It is a valid identifier" << endl;
    else
        cout << "It is not a valid identifier" << endl;

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
