#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

void preOrder(Node* root, vector<string>& ans, string curr) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        ans.push_back(curr);
        return;
    }

    preOrder(root->left, ans, curr + "0");
    preOrder(root->right, ans, curr + "1");
}

vector<string> huffmanCodes(string S, vector<int>& f, int N) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < N; i++) {
        pq.push(new Node(f[i]));
    }

    while (pq.size() >= 2) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();

        Node* newNode = new Node(l->data + r->data);
        newNode->left = l;
        newNode->right = r;

        pq.push(newNode);
    }

    Node* root = pq.top();
    vector<string> ans;
    preOrder(root, ans, "");

    return ans;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.length();
    vector<int> f(n);

    cout << "Enter the frequency: ";
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<string> ans = huffmanCodes(s, f, n);

    cout << "Huffman coding:\n";
    for (string code : ans)
        cout << code << " ";

    return 0;
}