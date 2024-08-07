#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> below_20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands{"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int i = 0;
        string words = "";

        while (num > 0) {
            if (num % 1000 != 0) {
                words = helper(num % 1000) + thousands[i] + " " + words;
            }
            num /= 1000;
            i++;
        }

        // Trim any extra spaces
        while (words.back() == ' ') {
            words.pop_back();
        }

        return words;
    }

    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return below_20[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return below_20[num / 100] + " Hundred " + helper(num % 100);
    }
};

// Driver code to test the solution
int main() {
    Solution sol;
    vector<int> test_cases = {123, 12345, 1234567, 0, 1000000};
    for (int num : test_cases) {
        cout << num << ": " << sol.numberToWords(num) << endl;
    }
    return 0;
}
