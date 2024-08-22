#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to build the tree from a string
Node* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N') return NULL;

    istringstream iss(str);
    vector<string> values((istream_iterator<string>(iss)), istream_iterator<string>());

    Node* root = new Node(stoi(values[0]));
    queue<Node*> q;
    q.push(root);

    size_t i = 1;
    while (i < values.size()) {
        Node* currentNode = q.front();
        q.pop();

        if (values[i] != "N") {
            currentNode->left = new Node(stoi(values[i]));
            q.push(currentNode->left);
        }
        i++;
        if (i >= values.size()) break;

        if (values[i] != "N") {
            currentNode->right = new Node(stoi(values[i]));
            q.push(currentNode->right);
        }
        i++;
    }

    return root;
}

// Function to return the bottom view of the tree
vector<int> bottomView(Node* root) {
    if (!root) return {};

    map<int, int> bottomViewMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        bottomViewMap[hd] = node->data;

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    vector<int> result;
    for (const auto& [hd, value] : bottomViewMap) {
        result.push_back(value);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> result = bottomView(root);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
