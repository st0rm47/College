#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

// Node for syntax tree
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

// ===== Helpers =====
void printSet(const set<int>& s) {
    cout << "{ ";
    for (int x : s) cout << x << " ";
    cout << "}";
}

// Compute firstpos, lastpos, nullable
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
}

// Compute followpos
void computeFollowpos(Node* root, map<int,set<int>>& followpos) {
    if (!root) return;
    if (root->symbol == '.') {
        for (int i : root->left->lastpos)
            followpos[i].insert(root->right->firstpos.begin(), root->right->firstpos.end());
    }
    else if (root->symbol == '*') {
        for (int i : root->lastpos)
            followpos[i].insert(root->firstpos.begin(), root->firstpos.end());
    }

    computeFollowpos(root->left, followpos);
    computeFollowpos(root->right, followpos);
}

// ===== Recursive parser =====
Node* parseRegex(const string& s, int& pos, int& leafCount) {
    if (pos >= s.size()) return nullptr;

    if (s[pos] == '(') {
        pos++; // skip '('
        Node* left = parseRegex(s, pos, leafCount);

        char op = s[pos]; pos++; // operator . or |
        Node* right = parseRegex(s, pos, leafCount);

        Node* root = new Node(op);
        root->left = left; root->right = right;

        pos++; // skip ')'
        if (pos < s.size() && s[pos] == '*') { // kleene
            Node* star = new Node('*');
            star->left = root;
            pos++;
            return star;
        }

        return root;
    }
    else if (isalnum(s[pos])) {
        Node* leaf = new Node(s[pos]);
        leaf->position = leafCount++;
        pos++;
        if (pos < s.size() && s[pos] == '*') { // kleene
            Node* star = new Node('*');
            star->left = leaf;
            pos++;
            return star;
        }
        return leaf;
    }
    return nullptr;
}

// ===== Main =====
int main() {
    string regex;
    cout << "Enter fully parenthesized regex (., |, *): ";
    getline(cin, regex);

    int pos = 0, leafCount = 1;
    Node* root = parseRegex(regex, pos, leafCount);

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
    return 0;
}
