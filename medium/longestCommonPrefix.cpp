#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &arr) {
        if (arr.empty()) return "-1";
        
        // Start with the first string as the initial prefix
        string prefix = arr[0];
        // Iterate through each string in the array
        for (int i = 1; i < arr.size(); ++i) {
            // Update the prefix by comparing with the current string
            prefix = commonPrefix(prefix, arr[i]);
            // If at any point the prefix becomes empty, return "-1"
            if (prefix.empty()) return "-1";
        }
        return prefix;
    }
    
private:
    string commonPrefix(const string &str1, const string &str2) {
        int minLength = min(str1.size(), str2.size());
        string result;
        for (int i = 0; i < minLength; ++i) {
            if (str1[i] == str2[i]) {
                result.push_back(str1[i]);
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}