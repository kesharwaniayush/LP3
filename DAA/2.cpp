// Code-A2 (Huffman Coding)

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// A Huffman Tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare function for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right)
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Main function to build Huffman Tree and generate codes
void huffmanEncoding(vector<char>& chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create a leaf node for each character and add it to the queue
    for (int i = 0; i < chars.size(); i++)
        pq.push(new Node(chars[i], freq[i]));

    // Step 2: Repeat until one node remains (the root)
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create new internal node with sum of two smallest frequencies
        Node* newNode = new Node('-', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Step 3: Print the Huffman codes
    Node* root = pq.top();
    cout << "\nHuffman Codes:\n";
    printCodes(root, "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter corresponding frequencies: ";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    huffmanEncoding(chars, freq);

    return 0;
}

// SAMPLE OUTPUT
/*
* $ ./a.out 
* Enter number of characters: 5   
* Enter characters: a f v c w 
* Enter corresponding frequencies: 3 2 1 5 7 
* 
* Huffman Codes:
* w : 0
* c : 10
* a : 110
* v : 1110
* f : 1111
*/
