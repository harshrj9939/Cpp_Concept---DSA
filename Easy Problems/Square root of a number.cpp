#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int low = 1, high = n, ans = 0;
        while (low <= high) {
            long long int mid = (low + high) / 2;
            long long int midSq = mid * mid;
            
            if (midSq == n) {
                return mid;
            }
            else if (midSq < n) {
                ans = mid; // mid is a possible answer
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans; // The floor value of sqrt(n)
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}
