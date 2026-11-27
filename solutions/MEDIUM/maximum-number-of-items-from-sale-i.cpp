// Problem: Maximum Number of Items From Sale I
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/maximum-number-of-items-from-sale-i/
// Approach: For each item, calculate its total value as one purchased copy plus all free copies it grants to other distinct items. Then, use a 0/1 knapsack dynamic programming approach to find the maximum total value achievable for each possible cost by selecting distinct item types, finally adding any additional copies of the cheapest item buyable with the remaining budget.

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int N = items.size();

        vector<int> freeItemCountContrib(N);
        for (int i = 0; i < N; ++i) {
            int factor_i = items[i][0];
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    continue;
                }
                int factor_j = items[j][0];
                if (factor_j % factor_i == 0) {
                    freeItemCountContrib[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        
        
        
        
        
        for (int i = 0; i < N; ++i) {
            int price_i = items[i][1];
            int valueIfFirstPurchase = 1 + freeItemCountContrib[i]; 

            for (int b = budget; b >= price_i; --b) {
                dp[b] = max(dp[b], dp[b - price_i] + valueIfFirstPurchase);
            }
        }

        
        
        
        
        
        
        for (int i = 0; i < N; ++i) {
            int price_i = items[i][1];
            int valueIfSubsequentPurchase = 1;

            for (int b = price_i; b <= budget; ++b) {
                dp[b] = max(dp[b], dp[b - price_i] + valueIfSubsequentPurchase);
            }
        }
        
        
        
        
        return dp[budget];
    }
};
