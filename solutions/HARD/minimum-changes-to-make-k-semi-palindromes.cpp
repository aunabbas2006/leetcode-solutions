// Problem: Minimum Changes to Make K Semi-palindromes
// Difficulty: HARD
// Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/
// Approach: Precompute the minimum changes needed for each substring to become a semi-palindrome by iterating through all possible valid divisors. Then, use dynamic programming to find the minimum total changes to partition the string into k semi-palindromes.

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();

        
        
        
        
        
        
        vector<vector<int>> P(n, vector<int>(n));

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                if (len == 1) {
                    P[i][j] = n + 1; 
                    continue;
                }

                int current_min_changes = n + 1;

                
                
                for (int d_candidate = 1; d_candidate * d_candidate <= len; ++d_candidate) {
                    if (len % d_candidate == 0) {
                        
                        int d1 = d_candidate;
                        if (d1 < len) { 
                            int current_d1_changes = 0;
                            int group_len1 = len / d1; 
                            for (int g = 0; g < d1; ++g) { 
                                
                                for (int p = 0; p < group_len1 / 2; ++p) {
                                    if (s[i + g + p * d1] != s[i + g + (group_len1 - 1 - p) * d1]) {
                                        current_d1_changes++;
                                    }
                                }
                            }
                            current_min_changes = min(current_min_changes, current_d1_changes);
                        }

                        
                        int d2 = len / d_candidate;
                        
                        
                        if (d2 != d1 && d2 < len) {
                            int current_d2_changes = 0;
                            int group_len2 = len / d2;
                            for (int g = 0; g < d2; ++g) {
                                for (int p = 0; p < group_len2 / 2; ++p) {
                                    if (s[i + g + p * d2] != s[i + g + (group_len2 - 1 - p) * d2]) {
                                        current_d2_changes++;
                                    }
                                }
                            }
                            current_min_changes = min(current_min_changes, current_d2_changes);
                        }
                    }
                }
                P[i][j] = current_min_changes;
            }
        }

        
        
        
        
        int large_value = n * n / 2 + 1;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, large_value));

        
        dp[0][0] = 0;

        
        for (int i = 1; i <= n; ++i) { 
            for (int k_prime = 1; k_prime <= k; ++k_prime) { 
                
                for (int prev_i = 0; prev_i < i; ++prev_i) {
                    if (dp[prev_i][k_prime - 1] != large_value) { 
                        
                        
                        int current_sub_cost = P[prev_i][i - 1];
                        
                        
                        dp[i][k_prime] = min(dp[i][k_prime], dp[prev_i][k_prime - 1] + current_sub_cost);
                    }
                }
            }
        }

        return dp[n][k];
    }
};
