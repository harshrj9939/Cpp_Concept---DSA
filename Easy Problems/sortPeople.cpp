#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to sort names by heights in descending order
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    // Create a vector of pairs (height, name)
    vector<pair<int, string>> people;
    for (int i = 0; i < names.size(); i++) {
        people.push_back(make_pair(heights[i], names[i]));
    }

    // Sort the vector of pairs by height in descending order
    sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first;
    });

    // Extract the sorted names from the sorted pairs
    vector<string> sortedNames;
    for (const auto& person : people) {
        sortedNames.push_back(person.second);
    }

    return sortedNames;
}

int main() {
    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};

    vector<string> sortedNames = sortPeople(names, heights);

    for (const string& name : sortedNames) {
        cout << name << " ";
    }

    return 0;
}
