#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Generate Huffman Codes
void generateCodes(Node *root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node *, vector<Node *>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++)
    {
        char ch;
        int freq;
        cin >> ch >> freq;

        pq.push(new Node(ch, freq));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node *root = pq.top();

    cout << "\nHuffman Codes:\n";
    generateCodes(root, "");

    return 0;
}