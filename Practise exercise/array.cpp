#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    const int size = 10000;
    array<int, size> arr;
    fill(arr.begin(), arr.end(), 3); // Initializes the entire array to 1

    
    cout << arr[size-1] << endl; // Outputs: 1 1

    return 0;
}
