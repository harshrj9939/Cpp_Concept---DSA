#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int flipsCountFromPastFori = 0;
        deque<int> flipQue;
        
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipsCountFromPastFori -= flipQue.front();
                flipQue.pop_front();
            }
            if (flipsCountFromPastFori % 2 == nums[i]) {
                if (i + k > n)
                    return -1;
                flipsCountFromPastFori++;
                flips++;
                flipQue.push_back(1);
            } else {
                flipQue.push_back(0);
            }
        }
        return flips;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0};
    int k = 1;
    int result = solution.minKBitFlips(nums, k);
    cout << "Minimum number of K-bit flips: " << result << endl;

    vector<int> nums2 = {1, 1, 0, 0, 1, 0};
    k = 3;
    result = solution.minKBitFlips(nums2, k);
    cout << "Minimum number of K-bit flips: " << result << endl;

    return 0;
}
