#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Helper function to perform topological sort
        auto topologicalSort = [](int k, const vector<vector<int>>& conditions) {
            vector<int> inDegree(k + 1, 0);
            unordered_map<int, unordered_set<int>> graph;
            for (const auto& condition : conditions) {
                int u = condition[0], v = condition[1];
                if (graph[u].insert(v).second) { // avoid duplicate edges
                    inDegree[v]++;
                }
            }

            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }

            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                for (int neighbor : graph[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            if (order.size() != k) {
                return vector<int>{}; // return empty vector if no valid topological sort
            }
            return order;
        };

        // Get the topological order for rows and columns
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {}; // return an empty matrix if no valid order exists
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPos, colPos;

        for (int i = 0; i < k; ++i) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        for (int num = 1; num <= k; ++num) {
            matrix[rowPos[num]][colPos[num]] = num;
        }

        return matrix;
    }
};

// Utility function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int k = 3;
    vector<vector<int>> rowConditions = {{1, 2}, {3, 2}};
    vector<vector<int>> colConditions = {{2, 1}, {3, 2}};
    
    Solution sol;
    vector<vector<int>> result = sol.buildMatrix(k, rowConditions, colConditions);
    
    if (result.empty()) {
        cout << "No valid matrix can be constructed." << endl;
    } else {
        printMatrix(result);
    }

    return 0;
}


