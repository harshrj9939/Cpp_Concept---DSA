//Question of leetcode - Delete Nodes And Return Forest

#include <vector>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteHelper(TreeNode* node, unordered_set<int>& st, vector<TreeNode*>& result) {
        if (node == NULL)
            return NULL;

        node->left = deleteHelper(node->left, st, result);
        node->right = deleteHelper(node->right, st, result);

        if (st.find(node->val) != st.end()) {
            if (node->left != NULL)
                result.push_back(node->left);
            if (node->right != NULL)
                result.push_back(node->right);
            return NULL;
        } else {
            return node;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        root = deleteHelper(root, st, result);

        if (root && st.find(root->val) == st.end()) {
            result.push_back(root);
        }

        return result;
    }
};

// Helper function to print the tree nodes in a vector
void printForest(const vector<TreeNode*>& forest) {
    for (auto tree : forest) {
        printTree(tree);
        cout << endl;
    }
}

// Helper function to print a single tree (Pre-order traversal)
void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Example usage
int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Nodes to delete
    vector<int> to_delete = {3, 5};

    // Create Solution object and get the forest
    Solution sol;
    vector<TreeNode*> forest = sol.delNodes(root, to_delete);

    // Print the resulting forest
    printForest(forest);

    return 0;

}
