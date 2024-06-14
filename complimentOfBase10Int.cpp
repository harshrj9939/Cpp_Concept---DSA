#include <iostream>
#include <string>

using namespace std;

int complementBase10(int num) {
    // Convert the number to a string to easily manipulate each digit
    string numStr = to_string(num);
    string complementStr = "";

    // Calculate the complement of each digit with respect to 9
    for (char digit : numStr) {
        int digitComplement = 9 - (digit - '0'); // Convert char to int and calculate complement
        complementStr += to_string(digitComplement); // Append to complement string
    }

    // Convert the complement string back to an integer
    int complementNum = stoi(complementStr);
    return complementNum;
}

int main() {
    int num = 123;
    int complementNum = complementBase10(num);
    cout << "The complement of " << num << " is " << complementNum << endl;
    return 0;
}
