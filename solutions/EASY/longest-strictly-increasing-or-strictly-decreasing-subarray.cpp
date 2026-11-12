// Problem: Longest Strictly Increasing or Strictly Decreasing Subarray
// Difficulty: EASY
// Link: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
// Approach: Iterative scan maintaining current lengths for both strictly increasing and strictly decreasing subarrays, updating a global maximum length at each step.

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int maxLength = 1;
        int currentIncreasingLength = 1;
        int currentDecreasingLength = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                currentIncreasingLength++;
                currentDecreasingLength = 1; 
            } else if (nums[i] < nums[i - 1]) {
                currentDecreasingLength++;
                currentIncreasingLength = 1;
            } else { 
                currentIncreasingLength = 1;
                currentDecreasingLength = 1;
            }
            maxLength = max(maxLength, currentIncreasingLength);
            maxLength = max(maxLength, currentDecreasingLength);
        }

        return maxLength;
    }
};
