
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
    bool isPowerofTwo(long long n) {

        while(n>1 && n%2==0){
            n=n/2;
            
        }
        return n==1?true:false;
    }
};


int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        
        Solution ob;
        if (ob.isPowerofTwo(n)) 
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}
