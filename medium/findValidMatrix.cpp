//Find Valid Matrix Given Row and Column Sums

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int rows = rowSum.size();
    int cols = colSum.size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int fillValue = min(rowSum[i], colSum[j]);
            result[i][j] = fillValue;
            rowSum[i] -= fillValue;
            colSum[j] -= fillValue;
        }
    }
    
    return result;
}

int main() {
    vector<int> rowSum = {3, 8};
    vector<int> colSum = {4, 7};
    
    vector<vector<int>> matrix = restoreMatrix(rowSum, colSum);
    
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
