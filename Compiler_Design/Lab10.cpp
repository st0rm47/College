#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

char input[50], stackArr[50];

// Parsing Table
char table[5][6][4] = {
    {"tb", "", "", "tb", "", ""},
    {"", "+tb", "", "", "n", "n"},
    {"fc", "", "", "fc", "", ""},
    {"", "n", "*fc", "", "n", "n"},
    {"i", "", "", "(e)", "", ""}
};

int sizeArr[5][6] = {
    {2,0,0,2,0,0},
    {0,3,0,0,1,1},
    {2,0,0,2,0,0},
    {0,1,3,0,1,1},
    {1,0,0,3,0,0}
};

int getRow(char ch) {
    switch (ch) {
        case 'e': return 0;
        case 'b': return 1;
        case 't': return 2;
        case 'c': return 3;
        case 'f': return 4;
    }
    return -1;
}

int getCol(char ch) {
    switch (ch) {
        case 'i': return 0;
        case '+': return 1;
        case '*': return 2;
        case '(': return 3;
        case ')': return 4;
        case '$': return 5;
    }
    return -1;
}

void printTable(int top, int ip) {
    cout << "| ";
    for (int i = 0; i <= top; i++)
        cout << stackArr[i];
    cout << setw(26 - top);

    cout << "| ";
    cout << &input[ip];
    cout << setw(26 - strlen(&input[ip]));
    cout << "|\n";
}

int main() {
    cout << "\t\t================" << endl;
    cout << "\t\t  LL(1) PARSER  " << endl;
    cout << "\t\t================" << endl;

    cout << "Grammar:\n";
    cout << "E -> T B\n";
    cout << "B -> + T B | epsilon\n";
    cout << "T -> F C\n";
    cout << "C -> * F C | epsilon\n";
    cout << "F -> (E) | i\n\n";

    cout << "Enter input string: ";
    cin >> input;
    strcat(input, "$");

    stackArr[0] = '$';
    stackArr[1] = 'e';

    int top = 1, ip = 0;

    cout << "+--------------------------+-------------------------+ " << endl;
    cout << "|          STACK           |          INPUT          | " << endl;
    cout << "+--------------------------+-------------------------+ " << endl;

    while (top >= 0) {
        printTable(top, ip);

        if (stackArr[top] == input[ip]) {
            top--;
            ip++;
        }
        else {
            int r = getRow(stackArr[top]);
            int c = getCol(input[ip]);

            if (r == -1 || c == -1 || table[r][c][0] == '\0') {
                cout << "\nERROR: Invalid string\n";
                return 0;
            }

            if (table[r][c][0] == 'n') { // epsilon
                top--;
            }
            else {
                char prod[4];
                strcpy(prod, table[r][c]);
                top--;
                for (int k = sizeArr[r][c] - 1; k >= 0; k--)
                    stackArr[++top] = prod[k];
            }
        }

        if (stackArr[top] == '$' && input[ip] == '$')
            break;
    }

    cout << "+--------------------------+-------------------------+\n";
    cout << "\nSUCCESS: Parsing completed successfully!\n";
    cout << "Compiled by : Subodh Ghimire\n";
    return 0;
}
