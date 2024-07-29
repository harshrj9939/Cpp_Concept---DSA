#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return -1;
        int m = arr[0].size();
        if (m == 0) return -1;
        
        int max1sCount = 0;
        int rowIndex = -1;
        
        for (int i = 0; i < n; ++i) {
            // Use binary search to find the first occurrence of 1
            int first1 = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
            
            if (first1 < m) {  // There is at least one '1' in this row
                int num1s = m - first1;
                if (num1s > max1sCount) {
                    max1sCount = num1s;
                    rowIndex = i;
                }
            }
        }
        
        return rowIndex;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}
