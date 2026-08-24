// Problem: Stone Game VIII
// Difficulty: HARD
// Link: https://leetcode.com/problems/stone-game-viii/
// Approach: This problem can be solved using dynamic programming with an optimization for suffix maximums. Let `P[k]` be the prefix sum `stones[0] + ... + stones[k-1]`. `dp[i]` represents the maximum score difference the current player can achieve if the current leftmost stone's value is the accumulated sum of `stones[0]` through `stones[i-1]`, and `stones[i], ..., stones[n-1]` are the remaining original stones.

The current player chooses `j` (from `i+1` to `n`) to combine the current leftmost stone with `stones[i], ..., stones[j-1]`. The sum added to their score is `P[j]`. The next player then plays optimally from state `j`, aiming to minimize the current player's score. Thus, `dp[i] = max_{j=i+1 ... n} (P[j] - dp[j])`. This can be optimized to O(N) by iterating backwards from `n-1` to `1` and maintaining a running maximum of `P[k] - dp[k]`. The base case is `dp[n] = 0` (no more moves possible). The final answer is `dp[1]`.

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i+1] = prefix_sum[i] + stones[i];
        }

        
        
        
        
        
        
        
        

        
        

        
        
        
        
        
        
        long long max_suf_diff = prefix_sum[n];

        
        vector<long long> dp(n + 1);
        dp[n] = 0; 

        for (int i = n - 1; i >= 1; --i) {
            
            
            
            dp[i] = max_suf_diff;

            
            
            
            
            max_suf_diff = max(max_suf_diff, prefix_sum[i] - dp[i]);
        }

        
        
        return static_cast<int>(dp[1]);
    }
};
