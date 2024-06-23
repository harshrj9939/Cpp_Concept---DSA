
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int> ans;
        stack<int> st;
        int opens = 0;
        for(auto it: str){
            if(it=='('){
            opens++;
            st.push(opens);
            ans.push_back(st.top());
        }
        else if(it==')'){
            ans.push_back(st.top());
            st.pop();
        }
        }
        return ans;
    }
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}