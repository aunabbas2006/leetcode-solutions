// Problem: Sum Game
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/sum-game/
// Approach: Calculate the sum difference `diff_s = sum(first half digits) - sum(second half digits)` and the question mark count difference `diff_q = count(first half '?') - count(second half '?')`. If `diff_q` is odd, Alice wins. If `diff_q` is even, Bob wins if and only if `diff_s + diff_q * 9 / 2` is zero, otherwise Alice wins.

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1 = 0;
        int q1 = 0;
        int sum2 = 0;
        int q2 = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q1++;
            } else {
                sum1 += (num[i] - '0');
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q2++;
            } else {
                sum2 += (num[i] - '0');
            }
        }

        int initial_diff = sum1 - sum2;
        int q_diff = q1 - q2;

        
        
        
        
        
        
        
        if (q_diff == 0) {
            return initial_diff != 0; 
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        return (2 * initial_diff + q_diff * 9) != 0;
    }
};
