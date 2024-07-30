#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findPaths(vector<vector<int>> &mat, int x, int y, int n, string path, vector<string> &result) {
        // Base case: reached the destination
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }
        
        // Mark the cell as visited
        mat[x][y] = 0;

        // Move Down
        if (x + 1 < n && mat[x + 1][y] == 1) {
            findPaths(mat, x + 1, y, n, path + "D", result);
        }

        // Move Right
        if (y + 1 < n && mat[x][y + 1] == 1) {
            findPaths(mat, x, y + 1, n, path + "R", result);
        }

        // Move Up
        if (x - 1 >= 0 && mat[x - 1][y] == 1) {
            findPaths(mat, x - 1, y, n, path + "U", result);
        }

        // Move Left
        if (y - 1 >= 0 && mat[x][y - 1] == 1) {
            findPaths(mat, x, y - 1, n, path + "L", result);
        }

        // Unmark the cell (backtrack)
        mat[x][y] = 1;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> result;
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return result; // no paths if start or end is blocked
        }
        findPaths(mat, 0, 0, n, "", result);
        sort(result.begin(), result.end());
        return result;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}