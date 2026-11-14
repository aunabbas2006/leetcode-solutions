// Problem: Minimum Positive Sum Subarray
// Difficulty: EASY
// Link: https://leetcode.com/problems/minimum-positive-sum-subarray/
// Approach: Use prefix sums to efficiently calculate subarray sums. Maintain a sliding window of valid prefix sums using a balanced binary search tree (e.g., multiset) to quickly find the largest previous prefix sum that results in a positive subarray sum within the given length range.

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        long long minPositiveSum = 100001LL; 
        
        for (int i = 0; i < n; ++i) {
            for (int currentLength = l; currentLength <= r; ++currentLength) {
                int j = i + currentLength - 1;
                
                if (j < n) {
                    long long currentSum = prefixSum[j + 1] - prefixSum[i];
                    
                    if (currentSum > 0) {
                        if (currentSum < minPositiveSum) {
                            minPositiveSum = currentSum;
                        }
                    }
                }
            }
        }
        
        if (minPositiveSum == 100001LL) {
            return -1;
        } else {
            return static_cast<int>(minPositiveSum);
        }
    }
};
