#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> meetings;
        
        // Creating pairs of (end time, start time)
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sorting the meetings by end time
        sort(meetings.begin(), meetings.end());
        
        int count = 0; // Number of meetings we can hold
        int last_end_time = 0; // End time of the last selected meeting
        
        // Iterating through the sorted list of meetings
        for (int i = 0; i < n; i++) {
            // If the start time of the current meeting is greater
            // than the end time of the last selected meeting
            if (meetings[i].second > last_end_time) {
                // We can select this meeting
                count++;
                // Update the end time of the last selected meeting
                last_end_time = meetings[i].first;
            }
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
