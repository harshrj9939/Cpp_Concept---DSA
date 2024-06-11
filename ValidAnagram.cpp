#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() - t.size() > 0) { // comparison between signed and unsigned integer expressions
            return false;
        }
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(map.find(t[i]) != map.end() && map[t[i]] > 0){
                map[t[i]]--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    if (sol.isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
