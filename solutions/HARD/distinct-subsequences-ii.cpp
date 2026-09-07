// Problem: Distinct Subsequences II
// Difficulty: HARD
// Link: https://leetcode.com/problems/distinct-subsequences-ii/
// Approach: Dynamic programming is used to count distinct subsequences: at each step, the total distinct subsequences roughly doubles and adds one for the current character, but we subtract the count of subsequences ending with previous occurrences of this character to eliminate duplicates.

class Solution {
public:
    int distinctSubseqII(string s) {
        
        
        
        int dp[26] = {0}; 
        
        
        
        long long total_sum = 0; 
        
        const int MOD = 1e9 + 7;
        
        for (char c : s) {
            int char_idx = c - 'a';
            
            
            
            long long old_count_for_c = dp[char_idx];
            
            
            
            
            
            
            long long new_count_for_c = (total_sum + 1) % MOD;
            
            
            dp[char_idx] = new_count_for_c;
            
            
            
            
            
            
            total_sum = (total_sum + new_count_for_c - old_count_for_c + MOD) % MOD;
        }
        
        return total_sum;
    }
};
