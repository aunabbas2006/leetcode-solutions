// Problem: Subarrays Distinct Element Sum of Squares I
// Difficulty: EASY
// Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Approach: Iterate through all possible subarrays using nested loops, and for each subarray, calculate the count of distinct elements using a hash set, then add the square of this count to a running total.

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSumOfSquares = 0;

        for (int i = 0; i < n; ++i) {
            vector<bool> seen(101, false); 
            int currentDistinctCount = 0;

            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    currentDistinctCount++;
                }
                totalSumOfSquares += currentDistinctCount * currentDistinctCount;
            }
        }

        return totalSumOfSquares;
    }
};
