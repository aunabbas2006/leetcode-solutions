// Problem: Maximum Nesting Depth of Two Valid Parentheses Strings
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Approach: Iterate through the string, maintaining a current nesting depth. For an opening parenthesis, increment the depth and assign it to a subsequence based on the parity of the new depth; for a closing parenthesis, assign it based on the parity of the current depth, then decrement the depth.

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer(seq.length());
        int current_depth = 0;
        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                answer[i] = current_depth % 2;
                current_depth++;
            } else { 
                current_depth--;
                answer[i] = current_depth % 2;
            }
        }
        return answer;
    }
};
