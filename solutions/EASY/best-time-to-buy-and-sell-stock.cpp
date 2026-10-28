// Problem: Best Time to Buy and Sell Stock
// Difficulty: EASY
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: A single pass iterates through the prices, tracking the minimum price encountered so far and continuously updating the maximum profit with the difference between the current price and that minimum.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
