// Problem: Stone Game II
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/stone-game-ii/
// Approach: Dynamic programming with memoization is used to calculate the maximum stones the current player can obtain from a given starting pile `i` and maximum `X` value `M`. The recurrence involves iterating through all valid `X` choices, adding the stones taken, and subtracting the optimal score the opponent would achieve from the remaining piles.

class Solution {
public:
    int N;
    vector<int> suffix_sum;
    vector<vector<int>> dp;

    int solve(int i, int m) {
        if (i == N) {
            return 0;
        }
        if (dp[i][m] != -1) {
            return dp[i][m];
        }

        int res = 0;
        
        int current_total_stones_from_i_onwards = suffix_sum[i];

        for (int X = 1; X <= min(2 * m, N - i); ++X) {
            int next_i = i + X;
            int next_m = max(m, X);
            
            int score_current_player = current_total_stones_from_i_onwards - solve(next_i, next_m);
            res = max(res, score_current_player);
        }

        return dp[i][m] = res;
    }

    int stoneGameII(vector<int>& piles) {
        N = piles.size();

        suffix_sum.resize(N + 1, 0);
        for (int i = N - 1; i >= 0; --i) {
            suffix_sum[i] = piles[i] + suffix_sum[i + 1];
        }

        dp.resize(N + 1, vector<int>(N + 1, -1));

        return solve(0, 1);
    }
};
