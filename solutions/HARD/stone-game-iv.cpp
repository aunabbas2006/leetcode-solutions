// Problem: Stone Game IV
// Difficulty: HARD
// Link: https://leetcode.com/problems/stone-game-iv/
// Approach: Dynamic programming determines winning/losing states: a state `i` is winning if there's any move to `i - k*k` (where `k*k` is a perfect square) from which the opponent loses, otherwise it's a losing state.

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);

        dp[0] = false;

        for (int i = 1; i <= n; ++i) {
            dp[i] = false; 
            
            for (int k = 1; k * k <= i; ++k) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
