#include <iostream>
#include <queue>
#include <unordered_map>
#include <iomanip>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare function for priority queue (min-heap)
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Recursive function to generate codes
void generateCodes(Node *root, string code, unordered_map<char, string> &huffCode)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        huffCode[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffCode);
    generateCodes(root->right, code + "1", huffCode);
}

void huffmanCoding(unordered_map<char, int> freqMap)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Step 1: Create leaf nodes and add to queue
    for (auto pair : freqMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Step 2: Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node *root = pq.top();
    unordered_map<char, string> huffCode;
    generateCodes(root, "", huffCode);

    // Output
    cout << "+-----------+-----------+----------------+" << endl;
    cout << "| Character | Frequency | Huffman Code   |" << endl;
    cout << "+-----------+-----------+----------------+" << endl;
    int originalBits = 0;
    int compressedBits = 0;

    for (auto pair : huffCode)
    {
        char ch = pair.first;
        string code = pair.second;
        int freq = freqMap[ch];

        originalBits += freq * 3;               // assuming 4 bits per char
        compressedBits += freq * code.length(); // bits per Huffman code

        cout << "|"
             << setw(6) << ch << setw(7) << " | "
             << setw(7) << freq << "   | "
             << setw(14) << std::left << code << std::right << " |" << endl;
    }
    cout << "+-----------+-----------+----------------+" << endl;

    cout << "Total space before compression: " << originalBits << " bits" << endl;
    cout << "Total space after compression : " << compressedBits << " bits" << endl;
    cout << "Compression ratio             : " << fixed << (100.0 * (originalBits - compressedBits) / originalBits) << "%" << endl;
}
int main()
{
    cout << "\t\t==================" << endl;
    cout << "\t\t  Huffman Coding  " << endl;
    cout << "\t\t==================" << endl;

    int n, freq;
    char ch;
    cout << endl
         << "Enter the number of characters: ";
    cin >> n;

    unordered_map<char, int> freqMap;
    cout << endl
         << "Enter the characters and their frequencies:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter character and its frequency (e.g., a 5): ";
        cin >> ch >> freq;
        freqMap[ch] = freq;
    }

    cout << endl
         << "+-----------+-----------+" << endl;
    cout << "| Character | Frequency |" << endl;
    cout << "+-----------+-----------+" << endl;
    for (auto pair : freqMap)
    {
        cout << "|" << setw(6) << pair.first << setw(7) << " | "
             << setw(6) << pair.second << setw(5) << " |" << endl;
    }
    cout << "+-----------+-----------+" << endl;
    huffmanCoding(freqMap);

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
