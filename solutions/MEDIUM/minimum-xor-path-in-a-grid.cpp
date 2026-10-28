// Problem: Minimum XOR Path in a Grid
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-xor-path-in-a-grid/
// Approach: Dynamic Programming where `dp[i][j]` stores a bitset representing all possible XOR sums to reach cell `(i, j)`. Each cell's bitset is computed by XORing its value with all sums from `dp[i-1][j]` and `dp[i][j-1]`.

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MAX_XOR_VAL = 1024; 

        
        
        vector<vector<bitset<MAX_XOR_VAL>>> dp(m, vector<bitset<MAX_XOR_VAL>>(n));

        
        
        dp[0][0][grid[0][0]] = true;

        
        
        for (int c = 1; c < n; ++c) {
            for (int prev_xor = 0; prev_xor < MAX_XOR_VAL; ++prev_xor) {
                if (dp[0][c-1][prev_xor]) {
                    dp[0][c][prev_xor ^ grid[0][c]] = true;
                }
            }
        }

        
        
        for (int r = 1; r < m; ++r) {
            for (int prev_xor = 0; prev_xor < MAX_XOR_VAL; ++prev_xor) {
                if (dp[r-1][0][prev_xor]) {
                    dp[r][0][prev_xor ^ grid[r][0]] = true;
                }
            }
        }

        
        
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                
                for (int prev_xor = 0; prev_xor < MAX_XOR_VAL; ++prev_xor) {
                    if (dp[r-1][c][prev_xor]) {
                        dp[r][c][prev_xor ^ grid[r][c]] = true;
                    }
                }
                
                for (int prev_xor = 0; prev_xor < MAX_XOR_VAL; ++prev_xor) {
                    if (dp[r][c-1][prev_xor]) {
                        dp[r][c][prev_xor ^ grid[r][c]] = true;
                    }
                }
            }
        }

        
        
        
        for (int k = 0; k < MAX_XOR_VAL; ++k) {
            if (dp[m-1][n-1][k]) {
                return k; 
            }
        }

        
        return 0; 
    }
};
