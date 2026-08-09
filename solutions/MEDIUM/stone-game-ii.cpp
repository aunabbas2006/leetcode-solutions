// Problem: Stone Game II
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/stone-game-ii/
// Approach: Dynamic programming with memoization, where `dp[i][m]` stores the maximum stones the current player can obtain from `piles[i:]` with the current `M` value, assuming optimal play by both Alice and Bob.

class Solution {
public:
    int N;
    vector<int> Piles;
    vector<int> SuffixSum;
    vector<vector<int>> Memo;

    int solve(int idx, int m) {
        if (idx == N) {
            return 0;
        }
        if (Memo[idx][m] != -1) {
            return Memo[idx][m];
        }

        int maxStones = 0; 
        for (int X = 1; X <= 2 * m; ++X) {
            if (idx + X > N) {
                break;
            }
            int currentStones = SuffixSum[idx] - solve(idx + X, max(m, X));
            maxStones = max(maxStones, currentStones);
        }

        return Memo[idx][m] = maxStones;
    }

    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        Piles = piles;

        SuffixSum.resize(N + 1, 0);
        for (int i = N - 1; i >= 0; --i) {
            SuffixSum[i] = Piles[i] + SuffixSum[i + 1];
        }

        Memo.resize(N + 1, vector<int>(N + 1, -1));

        return solve(0, 1);
    }
};
