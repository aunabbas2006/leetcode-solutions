// Problem: Sum of Squares of Special Elements
// Difficulty: EASY
// Link: https://leetcode.com/problems/sum-of-squares-of-special-elements/
// Approach: Iterate through the array with a 1-indexed loop, checking if the current index `i` divides the array length `n`; if it does, add the square of the corresponding element `nums[i-1]` to a running sum.

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int totalSumOfSquares = 0;

        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                
                totalSumOfSquares += nums[i - 1] * nums[i - 1];
            }
        }

        return totalSumOfSquares;
    }
};
