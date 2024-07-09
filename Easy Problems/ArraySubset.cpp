#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> frequencyA1, frequencyA2;

    // Count frequencies of elements in a1
    for (int i = 0; i < n; i++) {
        frequencyA1[a1[i]]++;
    }

    // Count frequencies of elements in a2
    for (int i = 0; i < m; i++) {
        frequencyA2[a2[i]]++;
    }

    // Check if each element in a2 has at least the same frequency in a1
    for (auto& pair : frequencyA2) {
        if (frequencyA1[pair.first] < pair.second) {
            return "No";
        }
    }

    return "Yes";
}
