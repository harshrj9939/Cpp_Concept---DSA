// find the no of triangle in a circle
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int track = 0;
        for(int l=1; l<=2*r;l++){
            for(int w=1; w<=2*r; w++){
                if(l*l+w*w<=4*r*r){
                    track++;
                }
            }
        }
        return track;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends