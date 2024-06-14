
#include <iostream>
#include <climits>
using namespace std;
      //THIS IS SOLUTION 01
// class Solution {
// public:
//     int reverse(int x) {
//         int ans = 0;
//         while (x != 0) {
//             int digit = x % 10;

//             if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
//                 return 0;
//             }
//             if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) {
//                 return 0;
//             }

//             ans = ans * 10 + digit;
//             x = x / 10;
//         }
//         return ans;
//     }
// };

// int main() {
//     Solution solution;
//     int number;
//     cout << "Enter a number to reverse: ";
//     cin >> number;

//     int reversedNumber = solution.reverse(number);
//     cout << "Reversed number: " << reversedNumber << endl;

//     return 0;
// }

       //THIS IS SOLUTION 02
int main()
{

int n;
cin>>n;
int reverse = 0;
while(n>0){
    int lastDigit = n%10;
    reverse = reverse*10 + lastDigit;
    n = n/10;
    
}
cout<<reverse<<endl;
return 0;
};