#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    char symbol;
    Node* left;
    Node* right;
    set<int> firstpos, lastpos;
    bool nullable;
    int position;
    Node(char sym) : symbol(sym), left(nullptr), right(nullptr),
                     nullable(false), position(-1) {}
};
   
void printSet(const set<int>& s) {
    cout << "{ ";
    for (int x : s) cout << x << " ";
    cout << "}";
}

void computeFirstLast(Node* root) {
    if (!root) return;
    if (!root->left && !root->right) {
        root->firstpos.insert(root->position);
        root->lastpos.insert(root->position);
        root->nullable = false;
        return;
    }
    computeFirstLast(root->left);
    computeFirstLast(root->right);
    if (root->symbol == '|') {
        root->firstpos.insert(root->left->firstpos.begin(), root->left->firstpos.end());
        root->firstpos.insert(root->right->firstpos.begin(), root->right->firstpos.end());
        root->lastpos.insert(root->left->lastpos.begin(), root->left->lastpos.end());
        root->lastpos.insert(root->right->lastpos.begin(), root->right->lastpos.end());
        root->nullable = root->left->nullable || root->right->nullable;
    }
    else if (root->symbol == '.') {
        root->firstpos = root->left->firstpos;
        if (root->left->nullable)
            root->firstpos.insert(root->right->firstpos.begin(), root->right->firstpos.end());
        root->lastpos = root->right->lastpos;
        if (root->right->nullable)
            root->lastpos.insert(root->left->lastpos.begin(), root->left->lastpos.end());
        root->nullable = root->left->nullable && root->right->nullable;
    }
    else if (root->symbol == '*') {
        root->firstpos = root->left->firstpos;
        root->lastpos = root->left->lastpos;
        root->nullable = true;
    }
    else if (root->symbol == '+') {
        root->firstpos = root->left->firstpos;
        root->lastpos = root->left->lastpos;
        root->nullable = root->left->nullable;
    }
}

void computeFollowpos(Node* root, map<int,set<int>>& followpos) {
    if (!root) return;
    if (root->symbol == '.') {
        for (int i : root->left->lastpos)
            followpos[i].insert(root->right->firstpos.begin(), root->right->firstpos.end());
    }
    else if (root->symbol == '*' || root->symbol == '+') {
        for (int i : root->lastpos)
            followpos[i].insert(root->firstpos.begin(), root->firstpos.end());
    }
    computeFollowpos(root->left, followpos);
    computeFollowpos(root->right, followpos);
}

// Recursive descent parser
Node* parseTerm(const string& s, int& pos, int& leafCount);

Node* parseFactor(const string& s, int& pos, int& leafCount) {
    Node* node = nullptr;
    if (s[pos] == '(') {
        pos++; // skip '('
        node = parseTerm(s, pos, leafCount);
        if (pos < s.size() && s[pos] == ')') pos++;
    }
    else if (isalnum(s[pos])) {
        node = new Node(s[pos]);
        node->position = leafCount++;
        pos++;
    }

    // Handle * and +
    if (pos < s.size() && (s[pos] == '*' || s[pos] == '+')) {
        Node* opNode = new Node(s[pos]);
        opNode->left = node;
        node = opNode;
        pos++;
    }
    return node;
}

Node* parseConcat(const string& s, int& pos, int& leafCount) {
    Node* left = parseFactor(s, pos, leafCount);
    while (pos < s.size() && (isalnum(s[pos]) || s[pos] == '(')) {
        Node* right = parseFactor(s, pos, leafCount);
        Node* concat = new Node('.');
        concat->left = left;
        concat->right = right;
        left = concat;
    }
    return left;
}

Node* parseTerm(const string& s, int& pos, int& leafCount) {
    Node* left = parseConcat(s, pos, leafCount);
    while (pos < s.size() && s[pos] == '|') {
        pos++; // skip '|'
        Node* right = parseConcat(s, pos, leafCount);
        Node* unionNode = new Node('|');
        unionNode->left = left;
        unionNode->right = right;
        left = unionNode;
    }
    return left;
}

int main() {
    string regex;
    cout << "Enter regex: ";
    getline(cin, regex);

    int pos = 0, leafCount = 1;
    Node* root = parseTerm(regex, pos, leafCount);

    computeFirstLast(root);
    cout << "Firstpos: "; printSet(root->firstpos); cout << "\n";
    cout << "Lastpos: "; printSet(root->lastpos); cout << "\n";

    map<int,set<int>> followpos;
    computeFollowpos(root, followpos);
    cout << "Followpos:\n";
    for (auto& kv : followpos) {
        cout << "Pos " << kv.first << ": "; printSet(kv.second); cout << "\n";
    }
    cout << "\nCompiled by : Subodh Ghimire\n";
}
