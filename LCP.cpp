#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For the min function

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int ans = strs[0].length(), n = strs.size();
        for (int i = 1; i < n; i++) {
            int j = 0;
            while (j < strs[i].length() && strs[i][j] == strs[0][j]) j++;
            ans = min(ans, j);
        }
        return strs[0].substr(0, ans);
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(strs);
    cout << "The longest common prefix is: " << result << endl;
    return 0;
}
