#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string findFirstWordInDictionary(const vector<string>& dictionary) {
    // Create a set to check for duplicates
    unordered_set<string> wordSet;
    
    for (const auto& word : dictionary) {
        if (wordSet.find(word) != wordSet.end()) {
            return "Invalid";
        }
        wordSet.insert(word);
    }
    
    // If no duplicates, find the first word in dictionary order
    vector<string> sortedDictionary = dictionary;
    sort(sortedDictionary.begin(), sortedDictionary.end());
    
    return sortedDictionary.front();
}

int main() {
    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    vector<string> dictionary(n);
    cout << "Enter the words:\n";
    for (int i = 0; i < n; ++i) {
        cin >> dictionary[i];
    }

    string result = findFirstWordInDictionary(dictionary);
    cout << "Output: " << result << endl;

    return 0;
}
