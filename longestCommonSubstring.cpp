#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfSubstring(string s) {
        int res = 0;
        int left = 0;
        unordered_map<char, int> map;
        for (int right = 0; right < s.size(); right++) {
            if (map.count(s[right])) {
                left = max(left, map[s[right]] + 1);
            }
            map[s[right]] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << "The length of the longest substring without repeating characters is: " << sol.lengthOfSubstring(s) << endl;
    return 0;
}
