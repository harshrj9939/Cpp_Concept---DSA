//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
    long long ExtractNumber(string sentence) {
        long long ans = 0, temp = 0;
        bool indication = false;
         for(char x: sentence){
             if(x>='0' and x<='9'){
                 temp = temp*10+(x-'0');
                 if(x=='9')indication = true;
             }
             else if (x==' '){
                 if(!indication)ans=max(ans,temp);
                 indication = false;
                 temp = 0;
                 
             }
         }
         if(!indication)ans=max(ans,temp);
         return ans ==0?-1:ans;
    }
};


//{ Driver Code Starts.
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
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends