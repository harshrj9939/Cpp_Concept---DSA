#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id;    // Job Id 
    int dead;  // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        // Sort jobs in decreasing order of profit
        sort(arr, arr + n, [](Job &a, Job &b) {
            return a.profit > b.profit;
        });

        // Find the maximum deadline to determine the size of the time slot array
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Create a slot array to keep track of the occupied time slots
        vector<int> slots(maxDeadline + 1, -1);

        int countJobs = 0, totalProfit = 0;

        // Iterate over each job
        for (int i = 0; i < n; i++) {
            // Find a slot for this job, starting from its deadline
            for (int j = arr[i].dead; j > 0; j--) {
                if (slots[j] == -1) {
                    // If the slot is free, assign this job to that slot
                    slots[j] = arr[i].id;
                    countJobs++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        Job arr[n];
        
        // Adding id, deadline, profit
        for(int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
