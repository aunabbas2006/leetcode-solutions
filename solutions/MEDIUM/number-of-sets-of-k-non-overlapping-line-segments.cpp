// Problem: Number of Sets of K Non-Overlapping Line Segments
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Approach: Dynamic programming with `dp[i][j]` representing the number of ways to form `j` segments using points up to `i`, where state transitions are efficiently computed using prefix sums of previous `dp` states.

class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;

        
        
        
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        
        
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }

        
        for (int j = 1; j <= k; ++j) {
            
            
            
            
            
            
            long long sum_ways_for_prev_segments = 0;
            
            
            
            for (int i = 0; i < n; ++i) {
                
                
                
                long long ways_not_using_i = (i > 0) ? dp[i-1][j] : 0;

                
                
                
                
                

                dp[i][j] = (ways_not_using_i + sum_ways_for_prev_segments) % MOD;

                
                
                
                
                sum_ways_for_prev_segments = (sum_ways_for_prev_segments + dp[i][j-1]) % MOD;
            }
        }

        
        return dp[n-1][k];
    }
};
