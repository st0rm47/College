#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool isKeyword(const string &buffer) {
    string keywords[32] = {"auto","break","case","char","const","continue",
        "default","do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed","sizeof","static",
        "struct","switch","typedef","union","unsigned","void","volatile","while"};

    for (int i = 0; i < 32; ++i) {
        if (buffer == keywords[i])
            return true;
    }
    return false;
}

int main() {
    string input;
    cout << "\t\t====================" << endl;
    cout << "\t\t  Lexical Analyzer  " << endl;
    cout << "\t\t====================" << endl;
    cout << "Enter a line of code: ";
    getline(cin, input);

    string buffer = "";
    char operators[] = "+-*/%=";

    for (char ch : input) {
        // Check operators
        for (int i = 0; i < 6; ++i) {
            if (ch == operators[i])
                cout << ch << " is operator" << endl;
        }

        // Build buffer for identifiers/keywords
        if (isalnum(ch) || ch == '_') {
            buffer += ch;
        } 
        else if ((ch == ' ' || ch == '\n' || ch == '\t') && !buffer.empty()) {
            if (isKeyword(buffer))
                cout << buffer << " is keyword" << endl;
            else
                cout << buffer << " is identifier" << endl;
            buffer = "";
        }
    }

    // Check if buffer has remaining word at end of line
    if (!buffer.empty()) {
        if (isKeyword(buffer))
            cout << buffer << " is keyword" << endl;
        else
            cout << buffer << " is identifier" << endl;
    }
    cout << "\nCompiled by : Subodh Ghimire" << endl;
}
