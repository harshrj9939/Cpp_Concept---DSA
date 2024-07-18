#include <iostream>
#include <vector>
#include <algorithm>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }
    
private:
    std::vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        if (!node->left && !node->right) return {0};
        
        std::vector<int> leftDistances = dfs(node->left, distance, result);
        std::vector<int> rightDistances = dfs(node->right, distance, result);
        
        for (int leftDist : leftDistances) {
            for (int rightDist : rightDistances) {
                if (leftDist + rightDist + 2 <= distance) {
                    result++;
                }
            }
        }
        
        std::vector<int> currentDistances;
        for (int leftDist : leftDistances) {
            if (leftDist + 1 < distance) {
                currentDistances.push_back(leftDist + 1);
            }
        }
        for (int rightDist : rightDistances) {
            if (rightDist + 1 < distance) {
                currentDistances.push_back(rightDist + 1);
            }
        }
        
        return currentDistances;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution solution;
    int distance = 3;
    std::cout << "Number of good leaf node pairs: " << solution.countPairs(root, distance) << std::endl;
    return 0;
}
