#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> grammar;
map<string, set<string>> FIRST;
map<string, set<string>> FOLLOW;
string startSymbol;

// Check if symbol is non-terminal (starts with uppercase letter)
bool isNonTerminal(const string &symbol) {
    return !symbol.empty() && isupper(symbol[0]);
}

// Split a production by comma
vector<string> splitProduction(const string &prod) {
    vector<string> symbols;
    stringstream ss(prod);
    string temp;
    while (getline(ss, temp, ',')) {
        symbols.push_back(temp);
    }
    return symbols;
}

// Compute FIRST set
set<string> computeFirst(const string &symbol) {
    if (FIRST.find(symbol) != FIRST.end())
        return FIRST[symbol];

    set<string> firstSet;

    if (!isNonTerminal(symbol)) { // terminal
        firstSet.insert(symbol);
        return firstSet;
    }

    for (string prod : grammar[symbol]) {
        vector<string> symbols = splitProduction(prod);
        bool nullable = true;
        for (auto &sym : symbols) {
            set<string> tempFirst = computeFirst(sym);
            for (auto f : tempFirst)
                if (f != "epsilon") firstSet.insert(f);
            if (tempFirst.find("epsilon") == tempFirst.end()) {
                nullable = false;
                break;
            }
        }
        if (nullable) firstSet.insert("epsilon");
    }

    FIRST[symbol] = firstSet;
    return firstSet;
}

// Compute FOLLOW sets
void computeFollow() {
    FOLLOW[startSymbol].insert("$"); // end of input marker

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto &nt : grammar) {
            string A = nt.first;
            for (string prod : nt.second) {
                vector<string> symbols = splitProduction(prod);
                for (size_t i = 0; i < symbols.size(); i++) {
                    string B = symbols[i];
                    if (isNonTerminal(B)) {
                        set<string> trailer;
                        bool nullable = true;
                        for (size_t j = i + 1; j < symbols.size() && nullable; j++) {
                            set<string> firstNext = computeFirst(symbols[j]);
                            for (auto f : firstNext)
                                if (f != "epsilon") trailer.insert(f);
                            if (firstNext.find("epsilon") == firstNext.end())
                                nullable = false;
                        }
                        if (nullable)
                            for (auto f : FOLLOW[A])
                                trailer.insert(f);
                        size_t before = FOLLOW[B].size();
                        FOLLOW[B].insert(trailer.begin(), trailer.end());
                        if (FOLLOW[B].size() != before)
                            changed = true;
                    }
                }
            }
        }
    }
}

// Print set with commas
void printSet(const string &name, const set<string> &s) {
    cout << name << " = { ";
    bool first = true;
    for (auto x : s) {
        if (!first) cout << ", ";
        cout << x;
        first = false;
    }
    cout << " }" << endl;
}

int main() {
    cout << "\t\t========================" << endl;
    cout << "\t\t  FIRST and FOLLOW Set  " << endl;
    cout << "\t\t========================" << endl;

    int n;
    cout << "Enter number of non-terminals: ";
    cin >> n;
    cin.ignore();

    cout << "Enter the grammar (comma-separated symbols):\n";
    for (int i = 0; i < n; i++) {
        string nt;
        int p;
        cout << "\nNon-terminal: ";
        cin >> nt;
        if (i == 0) startSymbol = nt;
        cout << "Number of productions for " << nt << ": ";
        cin >> p;
        cin.ignore();
        vector<string> prods(p);
        cout << "Enter productions (symbols separated by commas):\n";
        for (int j = 0; j < p; j++) {
            getline(cin, prods[j]);
        }
        grammar[nt] = prods;
    }

    // Compute FIRST sets
    for (auto &nt : grammar)
        computeFirst(nt.first);

    // Compute FOLLOW sets
    computeFollow();

    cout << "\nFIRST sets:\n";
    for (auto &nt : FIRST)
        printSet(nt.first, nt.second);

    cout << "\nFOLLOW sets:\n";
    for (auto &nt : FOLLOW)
        printSet(nt.first, nt.second);
    cout << "\nCompiled by : Subodh Ghimire\n";
}
