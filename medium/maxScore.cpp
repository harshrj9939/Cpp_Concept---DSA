#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to remove a specific substring and count its occurrences
    string removeSubstr(string &s, string matchStr, int &count) {
        stack<char> st;
        for(char &ch : s) {
            if(ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]) {
                st.pop();
                count++;
            } else {
                st.push(ch);
            }
        }
        string temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(begin(temp), end(temp));
        return temp;
    }
    
    
    int maximumGain(string s, int x, int y) {
        int score = 0;
        
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x > y) ? "ba" : "ab";
        
        // First round: remove the substring that gives the higher score
        int countMaxStr = 0;
        string temp_first = removeSubstr(s, maxStr, countMaxStr);
        score += countMaxStr * max(x, y);
        
        // Second round: remove the other substring
        int countMinStr = 0;
        string temp_second = removeSubstr(temp_first, minStr, countMinStr);
        score += countMinStr * min(x, y);

        return score;
    }
};

int main() {
    Solution solution;
    string s = "aabbaaxybbaabb";
    int x = 5, y = 4;
    
    int result = solution.maximumGain(s, x, y);
    cout << "Maximum Gain: " << result << endl; // Output should be 19
    
    return 0;
}
