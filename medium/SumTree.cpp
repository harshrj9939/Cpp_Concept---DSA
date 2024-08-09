#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build a tree from a string
Node* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N')
        return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string val; iss >> val;)
        ip.push_back(val);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        if (ip[i] != "N") {
            currNode->left = new Node(stoi(ip[i]));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;

        if (ip[i] != "N") {
            currNode->right = new Node(stoi(ip[i]));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    bool isSumTree(Node* root) {
        int sum = 0;
        return checkSumTree(root, sum);
    }

private:
    bool checkSumTree(Node* node, int &sum) {
        if (!node) {
            sum = 0;
            return true;
        }
        if (!node->left && !node->right) {
            sum = node->data;
            return true;
        }
        

        int leftSum = 0, rightSum = 0;
        bool left = checkSumTree(node->left, leftSum);
        bool right = checkSumTree(node->right, rightSum);

        sum = node->data + leftSum + rightSum;

        return left && right && node->data == leftSum + rightSum;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    Solution solution;

    while (t--) {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        cout << (solution.isSumTree(root) ? "true" : "false") << endl;
    }

    return 0;
}
