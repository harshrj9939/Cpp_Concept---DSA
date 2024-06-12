#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> map;
        int n = nums.size();
        
        for(int i =0; i<n; i++){
            int remaining = target - nums[i];
        if(map.find(remaining)!=map.end()){
            return {map[remaining], i};
        }
        map[nums[i]]=i;
    }
    return {-1, -1};
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 16, 15};
    int target = 22;
    vector<int> result = sol.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}