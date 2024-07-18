#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastSkipLength;
        string result;

        for (char &ch : s) {
            if (ch == '(') {
                lastSkipLength.push(result.length());
            } else if (ch == ')') {
                int l = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(begin(result) + l, end(result));
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};

// Main function to demonstrate the use of reverseParentheses
int main() {
    Solution sol;
    string s = "(abc(de)fg)";  // Example input
    cout << "Input string: " << s << endl;
    cout << "Result string: " << sol.reverseParentheses(s) << endl;
    return 0;
}
