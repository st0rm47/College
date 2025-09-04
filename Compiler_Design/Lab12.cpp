#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "\t\t========================" << endl;
    cout << "\t\t  Final Code Generator  " << endl;
    cout << "\t\t========================" << endl;
    
    ifstream fp1("input.txt");
    ofstream fp2("output.txt");

    if (!fp1.is_open() || !fp2.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string op, arg1, arg2, result;

    while (fp1 >> op >> arg1 >> arg2 >> result) {
        if (op == "+") {
            fp2 << "\n MOV R0, " << arg1;
            fp2 << "\n ADD R0, " << arg2;
            fp2 << "\n MOV " << result << ", R0";
        }
        else if (op == "*") {
            fp2 << "\n MOV R0, " << arg1;
            fp2 << "\n MUL R0, " << arg2;
            fp2 << "\n MOV " << result << ", R0";
        }
        else if (op == "-") {
            fp2 << "\n MOV R0, " << arg1;
            fp2 << "\n SUB R0, " << arg2;
            fp2 << "\n MOV " << result << ", R0";
        }
        else if (op == "/") {
            fp2 << "\n MOV R0, " << arg1;
            fp2 << "\n DIV R0, " << arg2;
            fp2 << "\n MOV " << result << ", R0";
        }
        else if (op == "=") {
            fp2 << "\n MOV R0, " << arg1;
            fp2 << "\n MOV " << result << ", R0";
        }
    }

    fp1.close();
    fp2.close();

    cout << "Intermediate code generated successfully!" << endl;
    cout << "Final code written to output.txt" << endl;
    cout << "\nCompiled by : Subodh Ghimire\n";
}
