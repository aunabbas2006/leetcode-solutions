// Problem: Stone Game V
// Difficulty: HARD
// Link: https://leetcode.com/problems/stone-game-v/
// Approach: Dynamic Programming (DP) computes the maximum score for each stone segment `[i, j]` by considering all possible split points `k`, utilizing prefix sums to efficiently calculate sub-segment sums and making optimal choices based on Bob's rules.

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        
        if (n == 1) {
            return 0;
        }

        
        
        
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        
        
        for (int len = 2; len <= n; ++len) {
            
            for (int i = 0; i <= n - len; ++i) {
                
                int j = i + len - 1;
                
                int maxScoreForCurrentSegment = 0;

                
                
                
                for (int k = i; k < j; ++k) {
                    
                    int sumL = prefixSum[k + 1] - prefixSum[i];
                    int sumR = prefixSum[j + 1] - prefixSum[k + 1];

                    int currentRoundScore = 0;
                    int nextGameScore = 0;

                    if (sumL < sumR) {
                        
                        currentRoundScore = sumL;
                        nextGameScore = dp[i][k];
                    } else if (sumL > sumR) {
                        
                        currentRoundScore = sumR;
                        nextGameScore = dp[k + 1][j];
                    } else { 
                        
                        currentRoundScore = sumL; 
                        nextGameScore = max(dp[i][k], dp[k + 1][j]);
                    }
                    
                    maxScoreForCurrentSegment = max(maxScoreForCurrentSegment, currentRoundScore + nextGameScore);
                }
                dp[i][j] = maxScoreForCurrentSegment;
            }
        }

        
        return dp[0][n - 1];
    }
};
