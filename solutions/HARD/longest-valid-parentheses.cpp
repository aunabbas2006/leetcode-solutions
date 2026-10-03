// Problem: Longest Valid Parentheses
// Difficulty: HARD
// Link: https://leetcode.com/problems/longest-valid-parentheses/
// Approach: Stack-based approach that tracks indices of opening parentheses and boundary markers, allowing length calculation when a valid pair is formed by a closing parenthesis.

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        vector<int> st;
        st.push_back(-1); 

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push_back(i);
            } else { 
                st.pop_back(); 
                if (st.empty()) {
                    st.push_back(i);
                } else {
                    max_len = max(max_len, i - st.back());
                }
            }
        }
        return max_len;
    }
};
