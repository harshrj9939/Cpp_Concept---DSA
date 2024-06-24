#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        
        if(q>2*n || q<2)
        return 0;
        if(q+1<=n)
        return q-1;
        return 2*n-q+1;
        }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}