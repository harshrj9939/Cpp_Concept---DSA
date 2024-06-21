//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string compareFrac(string str) {
        int a, b, c, d;
        char slash, comma;
        stringstream ss(str);
        ss >> a >> slash >> b >> comma >> c >> slash >> d;

        string ans = "";
        if (a * d > b * c) {
            ans = to_string(a) + "/" + to_string(b);
        } else if (a * d < b * c) {
            ans = to_string(c) + "/" + to_string(d);
        } else {
            ans = "equal";
        }

        return ans;
    }
};



int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}
