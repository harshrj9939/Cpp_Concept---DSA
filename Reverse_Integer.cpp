
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;

            // Check for overflow/underflow before updating ans
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            ans = ans * 10 + digit;
            x = x / 10;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int number;
    cout << "Enter a number to reverse: ";
    cin >> number;

    int reversedNumber = solution.reverse(number);
    cout << "Reversed number: " << reversedNumber << endl;

    return 0;
}
