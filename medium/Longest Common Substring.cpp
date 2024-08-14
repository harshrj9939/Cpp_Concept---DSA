#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxLength;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
