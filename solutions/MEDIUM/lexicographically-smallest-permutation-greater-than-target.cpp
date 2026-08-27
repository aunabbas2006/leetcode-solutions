// Problem: Lexicographically Smallest Permutation Greater Than Target
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
// Approach: Iterate from right to left for the first differing position `k`, attempt to form `target`'s prefix `target[0...k-1]` using characters from `s`, then find the lexicographically smallest available character for `P[k]` that is strictly greater than `target[k]`, and append the remaining characters in sorted ascending order. The first such valid permutation found is the answer.

class Solution {
public:
    int N;

    bool solve(int idx, bool is_currently_greater, string& current_permutation, const string& target, vector<int>& char_counts) {
        if (idx == N) {
            return is_currently_greater;
        }

        if (is_currently_greater) {
            for (char c_val = 'a'; c_val <= 'z'; ++c_val) {
                while (char_counts[c_val - 'a'] > 0) {
                    current_permutation[idx++] = c_val;
                    char_counts[c_val - 'a']--;
                }
            }
            return true;
        }

        for (char c_val = 'a'; c_val <= 'z'; ++c_val) {
            if (char_counts[c_val - 'a'] > 0) {
                if (c_val < target[idx]) {
                    continue;
                }

                current_permutation[idx] = c_val;
                char_counts[c_val - 'a']--;

                bool new_is_currently_greater = (c_val > target[idx]);

                if (solve(idx + 1, new_is_currently_greater, current_permutation, target, char_counts)) {
                    return true;
                }

                char_counts[c_val - 'a']++;
            }
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        N = s.length();

        vector<int> char_counts(26, 0);
        for (char ch : s) {
            char_counts[ch - 'a']++;
        }

        string result_str(N, ' ');

        if (solve(0, false, result_str, target, char_counts)) {
            return result_str;
        } else {
            return "";
        }
    }
};
