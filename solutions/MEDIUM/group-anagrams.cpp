// Problem: Group Anagrams
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/group-anagrams/
// Approach: Use a hash map where the sorted version of each string serves as the key, and the value is a list of all original strings that produce that sorted key.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            anagramGroups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto const& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};
