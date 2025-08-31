#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// Function to remove immediate left recursion for a single non-terminal
void removeLeftRecursion(string nt, vector<string> prods) {
    vector<string> alpha; // productions starting with nt
    vector<string> beta;  // productions not starting with nt

    for (string p : prods) {
        if (p[0] == nt[0]) {
            alpha.push_back(p.substr(1)); // remove leading nt
        } else {
            beta.push_back(p);
        }
    }

    if (alpha.empty()) {
        cout << nt << " -> ";
        for (int i = 0; i < prods.size(); i++) {
            cout << prods[i];
            if (i != prods.size() - 1) cout << " | ";
        }
        cout << endl;
        return;
    }

    string newNT = nt + "'"; // new non-terminal

    // Print new productions
    cout << nt << " -> ";
    for (int i = 0; i < beta.size(); i++) {
        cout << beta[i] << newNT;
        if (i != beta.size() - 1) cout << " | ";
    }
    cout << endl;

    cout << newNT << " -> ";
    for (int i = 0; i < alpha.size(); i++) {
        cout << alpha[i] << newNT;
        if (i != alpha.size() - 1) cout << " | ";
    }
    cout << " | epsilon " << endl;   //epsilon
}

int main() {
    cout << "\t\t=================================" << endl;
    cout << "\t\t  Elimination of Left Recursion  " << endl;
    cout << "\t\t=================================" << endl;
    
    int ntCount;
    cout << "Enter number of non-terminals: ";
    cin >> ntCount;
    cin.ignore();

    map<string, vector<string>> grammar;
    for (int i = 0; i < ntCount; i++) {
        string nonTerminal;
        int n;
        cout << "\nEnter non-terminal: ";
        cin >> nonTerminal;
        cout << "Enter number of productions for " << nonTerminal << ": ";
        cin >> n;
        cin.ignore();

        vector<string> prods(n);
        cout << "Enter productions (one per line):\n";
        for (int j = 0; j < n; j++) {
            getline(cin, prods[j]);
        }

        grammar[nonTerminal] = prods;
    }

    cout << "\nGrammar after removing left recursion:\n";
    for (auto &kv : grammar) {
        removeLeftRecursion(kv.first, kv.second);
    }
    cout << "\nCompiled by : Subodh Ghimire\n";
    return 0;
}
