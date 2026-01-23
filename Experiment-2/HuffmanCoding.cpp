#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCode(Node* root, string code,
                  unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCode(root->left, code + "0", huffmanCode);
    generateCode(root->right, code + "1", huffmanCode);
}

string decodeString(Node* root, const string& encodedStr) {
    string decoded = "";
    Node* current = root;

    for (char bit : encodedStr) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}

int main() {
    string input;
    cout << "Enter the input string: ";
    getline(cin, input);

    unordered_map<char, int> freq;
    for (char ch : input) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    generateCode(root, "", huffmanCode);

    string encodedStr = "";
    for (char ch : input) {
        encodedStr += huffmanCode[ch];
    }

    string decodedStr = decodeString(root, encodedStr);
    
    cout << "Huffman Codes: " << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    } cout << endl;

    cout << "Original String : " << input << endl;
    cout << "Encoded String  : " << encodedStr << endl;
    cout << "Decoded String  : " << decodedStr << endl;

    return 0;
}
