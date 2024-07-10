#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        
        for (string &log : logs) {
            if (log == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else if (log != "./") {
                st.push(log);
            }
        }
        
        return st.size();
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<string> logs1 = {"d1/", "d2/", "../", "d21/", "./"};
    cout << "Test case 1 result: " << solution.minOperations(logs1) << endl; // Output: 2
    
    // Test case 2
    vector<string> logs2 = {"d1/", "d2/", "../", "../", "../"};
    cout << "Test case 2 result: " << solution.minOperations(logs2) << endl; // Output: 0
    
    // Test case 3
    vector<string> logs3 = {"./", "wz4/", "../", "mj2/", "../", "../", "ik/", "l3/"};
    cout << "Test case 3 result: " << solution.minOperations(logs3) << endl; // Output: 1
    
    return 0;
}
