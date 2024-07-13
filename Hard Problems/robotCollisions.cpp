#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> actual_index(n); // 0, 1, 2, ... n-1
        iota(begin(actual_index), end(actual_index), 0); // 0, 1, 2, 3, .... n-1

        auto lambda = [&](int& i, int& j) { 
            return positions[i] < positions[j]; 
        };

        sort(begin(actual_index), end(actual_index), lambda);

        vector<int> result;
        stack<int> st;

        for (int &currIdx : actual_index) {
            if (directions[currIdx] == 'R') {
                st.push(currIdx);
            } else { // Towards left 
                while (!st.empty() && healths[currIdx] > 0) {
                    int top_idx = st.top();
                    st.pop();

                    if (healths[top_idx] > healths[currIdx]) {
                        healths[top_idx] -= 1;
                        healths[currIdx] = 0;
                        st.push(top_idx);
                    } else if (healths[top_idx] < healths[currIdx]) {
                        healths[currIdx] -= 1;
                        healths[top_idx] = 0;
                    } else {
                        healths[currIdx] = 0;
                        healths[top_idx] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    vector<int> positions = {1, 2, 3, 4};
    vector<int> healths = {5, 3, 2, 1};
    string directions = "RLRL";

    vector<int> result = solution.survivedRobotsHealths(positions, healths, directions);

    cout << "Surviving robots' healths: ";
    for (int health : result) {
        cout << health << " ";
    }
    cout << endl;

    return 0;
}
