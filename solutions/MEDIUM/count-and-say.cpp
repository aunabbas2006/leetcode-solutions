// Problem: Count and Say
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/count-and-say/
// Approach: Iteratively generate the sequence, starting with "1", by repeatedly applying run-length encoding to the previous term. Each step involves traversing the current string, counting consecutive identical characters, and appending the count followed by the character to build the next string.

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string current_s = "1"; 

        for (int i = 2; i <= n; ++i) {
            string next_s = "";
            int j = 0;
            while (j < current_s.length()) {
                char current_char = current_s[j];
                int count = 0;
                int temp_j = j;
                while (temp_j < current_s.length() && current_s[temp_j] == current_char) {
                    count++;
                    temp_j++;
                }
                
                next_s += to_string(count); 
                next_s += current_char;
                
                j = temp_j; 
            }
            current_s = next_s;
        }

        return current_s;
    }
};
